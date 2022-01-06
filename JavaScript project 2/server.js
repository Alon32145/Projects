/*********************************************************************************
 * Name: alon
 * Password: 123
 * on step 4
 * mongodb+srv://alon:123@senecaweb.hyakc.mongodb.net/WEB322_Assignment6?retryWrites=true&w=majority
 * 
*  WEB322 – Assignment 06 
*  I declare that this assignment is my own work in accordance with Seneca  Academic Policy.  No part of this 
*  assignment has been copied manually or electronically from any other source (including web sites) or  
*  distributed to other students. 
* 
*  Name: Alon Raigorodetsky Student ID:109763201 Date: 08-Dec-2021
*
*  Online (Heroku) Link: https://enigmatic-journey-17240.herokuapp.com/
*
********************************************************************************/

const HTTP_PORT = process.env.PORT || 8080;
const express = require('express'); 
const path = require('path'); 
const multer = require('multer'); 
const fs = require('fs'); 
const bodyParser = require('body-parser'); 
const app = express(); 
const dataservice = require(__dirname + "/data-service.js");
const exphbs = require('express-handlebars');
const dataServiceAuth = require(__dirname + "/data-service-auth.js");
const clientSessions = require('client-sessions');
const Handlebars = require('handlebars');
const {allowInsecurePrototypeAccess} = require('@handlebars/allow-prototype-access');



// multer
//----------------------------------------------------------------------------------

const storage = multer.diskStorage({
    destination: "./public/images/uploaded",
    filename: function (req, file, cb) {
        cb(null, Date.now() + path.extname(file.originalname));
      }
});

const upload = multer({storage: storage});
// handlers
//----------------------------------------------------------------------------------
app.engine(".hbs", exphbs({
  extname: ".hbs",
  defaultLayout: 'main',
  helpers: {
    navLink: function (url, options) {
      return '<li' +
        ((url == app.locals.activeRoute) ? ' class="active" ' : '') +
        '><a href="' + url + '">' + options.fn(this) + '</a></li>';
    },
    equal: function (lvalue, rvalue, options) {
      if (arguments.length < 3)
        throw new Error("Handlebars Helper equal needs 2 parameters");
      if (lvalue != rvalue) {
        return options.inverse(this);
      } else {
        return options.fn(this);
      }
    }
  }
  , handlebars: allowInsecurePrototypeAccess(Handlebars)
}));
app.set("view engine", ".hbs");



onHttpStart = () => {
    console.log("Express http server listening on port " + HTTP_PORT);
}

//use
//----------------------------------------------------------------------------------
app.use(express.static('public'));
app.use(bodyParser.urlencoded({extended:true}));

app.use(function(req,res,next) {
    let route = req.baseUrl+req.path;
    app.locals.activeRoute = (route == "/") ? "/":route.replace(/\/$/,"");
    next();
});

app.use(clientSessions( {
    cookieName: "session",
    secret: "web_a6_secret",
    duration: 2*60*1000,
    activeDuration: 1000*60
}));

app.use((req,res,next) => {
    res.locals.session = req.session;
    next();
});

ensureLogin = (req,res,next) => {
    if (!(req.session.user)) {
        res.redirect("/login");
    }
    else { next(); }
};

//home
//----------------------------------------------------------------------------------
app.get('/', (req, res) => {
    res.render("home");
});


app.get('/home', (req, res) => {
    res.render("home");
});


//about
//----------------------------------------------------------------------------------
app.get('/about', (req, res) => {
    res.render("about");
});


//employees
//----------------------------------------------------------------------------------
app.get("/employees", ensureLogin, (req, res) => {
    if (req.query.status) {
        dataservice.getEmployeeByStatus(req.query.status)
        .then(data => res.render("employees", { employees: data }))
        .catch(err => res.status(404).send('no results'))
    }
    else if (req.query.department) {
        dataservice.getEmployeesByDepartment(req.query.department)
        .then(data => res.render("employees", { employees: data }))
        .catch(err => res.status(404).send('no results'))
    }
    else if (req.query.manager) {
        dataservice.getEmployeesByManager(req.query.manager)
        .then(data => res.render("employees", { employees: data }))
        .catch(err => res.status(404).send('no results'))
    }
    else {
        dataservice.getAllEmployees()
        .then(data => res.render("employees", { employees: data }))
        .catch(err => res.status(404).send('no results'))
    }
});
//the "/employee/value" route
//----------------------------------------------------------------------------------
app.get("/employee/:empNum", ensureLogin, (req, res) => {

    
    let viewData = {};

    dataservice.getEmployeeByNum(req.params.empNum).then((data) => {
        if (data) {
            viewData.employee = data; 
        } else {
            viewData.employee = null; 
        }
    }).catch(() => {
        viewData.employee = null;  
    }).then(dataservice.getDepartments)
    .then((data) => {
        viewData.departments = data; 

        t

        for (let i = 0; i < viewData.departments.length; i++) {
            if (viewData.departments[i].departmentId == viewData.employee.department) {
                viewData.departments[i].selected = true;
            }
        }

    }).catch(() => {
        viewData.departments = []; 
    }).then(() => {
        if (viewData.employee == null) { 
            res.status(404).send("Employee Not Found");
        } else {
            res.render("employee", { viewData: viewData }); 
        }
    });
});
// Add Employee route
//----------------------------------------------------------------------------------
app.get('/employees/add', ensureLogin, (req,res) => {
    dataservice.getDepartments()
    .then(data => res.render("addEmployee", {departments: data}))
    .catch(err => res.render("addEmployee", {departments: []}));
});

app.post('/employees/add', ensureLogin, (req,res) => {
    dataservice.addEmployee(req.body).then(() => {
        res.redirect("/employees");
    })
});

app.post('/employee/update', ensureLogin, (req, res) => {
    dataservice.updateEmployee(req.body).then(() => {
        res.redirect("/employees");
    })
});


// delete employee
//----------------------------------------------------------------------------------
app.get('/employees/delete/:value', ensureLogin, (req,res) => {
    dataservice.deleteEmployeeByNum(req.params.value)
    .then(res.redirect("/employees"))
    .catch(err => res.status(500).send("Unable to Remove Employee / Employee not found"))
});

//images
//----------------------------------------------------------------------------------
app.get('/images/add', ensureLogin, (req,res) => {
    res.render(path.join(__dirname + "/views/addImage.hbs"));
});

app.post("/images/add", ensureLogin, upload.single("imageFile"), (req,res) => {
    res.redirect("/images");
});

app.get("/images", ensureLogin, (req,res) => {
    fs.readdir("./public/images/uploaded", function(err,items) {
        res.render("images", { data: items });
    })
});

//managers
//----------------------------------------------------------------------------------
app.get("/managers", ensureLogin, (req, res) => {
    dataservice.getManagers()
    .then(data => res.render("employees", {employees: data}))
    .catch(err => res.status(404).send("managers data not found"))
});


//departments
//----------------------------------------------------------------------------------
app.get("/departments", ensureLogin, (req, res) => {
    dataservice.getDepartments()
    .then(data => res.render("departments", { departments: data }))
    .catch(err => res.status(404).send('departments not found'))
});

app.get("/departments/add", ensureLogin, (req,res) => {
    res.render(path.join(__dirname + "/views/addDepartment.hbs"));
});

app.post("/departments/add", ensureLogin, (req,res) => {
    dataservice.addDepartment(req.body).then(() => {
        res.redirect("/departments");
    })
});

app.post("/department/update", ensureLogin, (req,res) => {
    dataservice.updateDepartment(req.body).then(() => {
        res.redirect("/departments");
    })
});

app.get("/department/:departmentId", ensureLogin, (req, res) =>{
    dataservice.getDepartmentById(req.params.departmentId)
    .then((data) => {res.render("department", { department: data })})
    .catch(err => res.status(404).send("department not found"))
});

app.get('/departments/delete/:value', ensureLogin, (req,res) => {
    dataservice.deleteDepartmentByNum(req.params.value)
    .then(res.redirect("/departments"))
    .catch(err => res.status(500).send("Unable to Remove Department / Department not found"))
});

//login
//----------------------------------------------------------------------------------
app.get("/login", (req,res) => {
    res.render("login");
});

app.get("/register", (req,res) => {
    res.render("register");
});

app.post("/register", (req,res) => {
    dataServiceAuth.registerUser(req.body)
    .then(() => res.render("register", {successMessage: "User created" } ))
    .catch (err => res.render("register", {errorMessage: err, userName:req.body.userName }) )
});

app.post("/login", (req,res) => {
    req.body.userAgent = req.get('User-Agent');
    dataServiceAuth.checkUser(req.body)
    .then(user => {
        req.session.user = {
            userName:user.userName,
            email:user.email,
            loginHistory:user.loginHistory
        }
        res.redirect("/employees");
    })
    .catch(err => {
        res.render("login", {errorMessage:err, userName:req.body.userName} )
    }) 
});

app.get("/logout", (req,res) => {
    req.session.reset();
    res.redirect("/login");
});

app.get("/userHistory", ensureLogin, (req,res) => {
    res.render("userHistory", {user:req.session.user} );
});

//no matching route
//----------------------------------------------------------------------------------
app.use((req, res) => {
    res.status(404).end('404 PAGE NOT FOUND');
});

dataservice.initialize()
.then(dataServiceAuth.initialize())
.then(() => {
    app.listen(HTTP_PORT, onHttpStart())
}).catch (() => {
    console.log('promises unfulfilled');
});