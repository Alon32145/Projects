//Name: Alon Raigorodetsky
//User ID: 109763201
//Date: 06/13/2021
//email: araigorodetsky@myseneca.ca

#ifndef SDDS_FOOD_H_
#define SDDS_FOOD_H_
namespace sdds {
    class Food {
        char m_foodName[31];
        int m_calories;
        int m_time;
        void setName(const char* name);
    public:
        void setEmpty();
        void set(const char* name, int calorie, int time);
        void display()const;
        bool isValid()const;
       // char* foodName()const;
        int calories()const;
        int time()const;
    };
}

#endif // !SDDS_SUBJECT_H
