//Name: Alon Raigorodetsky
//User ID: 109763201
//Date: 13/11/2021
//email: araigorodetsky@myseneca.ca


//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <algorithm>
#include <numeric>
#include <iomanip>
#include <fstream>
#include <iterator>
#include "SongCollection.h"


extern void printbar(std::ostream& out = std::cout);

namespace sdds
{

	std::string Song::operator=(const std::string& al)
	{
		return album = al;
	}

	SongCollection::SongCollection(const std::string& file)
	{
		
		std::string tmpstr{};

		std::fstream f(file, std::ios::in | std::ios::binary);

		if (!f)
			throw "Bad File Name!";

		tmpstr.resize(MAX_NUM_SIZE);

		while (!f.eof()) {

			Song tmp{};

			tmp.artist.resize(MAX_STR_SIZE);
			tmp.title.resize(MAX_STR_SIZE);
			tmp.album.resize(MAX_STR_SIZE);

			f.read(&tmp.title[0], MAX_STR_SIZE);
			trim(tmp.title);

			f.read(&tmp.artist[0], MAX_STR_SIZE);
			trim(tmp.artist);

			f.read(&tmp.album[0], MAX_STR_SIZE);
			trim(tmp.album);


			f.read(&tmpstr[0], MAX_NUM_SIZE);

			if (tmpstr.find_first_not_of(' ') != std::string::npos)
				tmp.year = stoul(tmpstr);

			f.read(&tmpstr[0], MAX_NUM_SIZE);
			if (tmpstr.find_first_not_of(' ') != std::string::npos)
				tmp.length = stoul(tmpstr);

			f.read(&tmpstr[0], MAX_NUM_SIZE);
			if (tmpstr.find_first_not_of(' ') != std::string::npos)
				tmp.m_price = stod(tmpstr);

			f.ignore(std::numeric_limits
				<std::streamsize>::max(), '\n');

			songs.push_back(std::move(tmp));
		}

	}

	void SongCollection::display(std::ostream& os) const
	{
		unsigned long total{ 0ul };


		std::copy(songs.cbegin(), songs.cend(),
			std::ostream_iterator<const Song&>(os, "\n"));

		total = std::accumulate(songs.cbegin(), songs.cend(), 0ul);

		printbar(os);

		os << "| " << std::setfill(' ') << std::setw(76)
			<< "Total Listening Time:" << std::setw(NUM_WIDTH)
			<< (total / SEC_PER_MIN / MIN_PER_HOUR) << ':'
			<< std::setw(NUM_WIDTH)
			<< (total / SEC_PER_MIN % MIN_PER_HOUR) << ':'
			<< std::setw(NUM_WIDTH) << (total % SEC_PER_MIN)
			<< std::right << " |" << std::endl;
	}

	void SongCollection::sort(const std::string& field)
	{

		if (field == "title") {
			std::sort(songs.begin(), songs.end(),
				[](const Song& a, const Song& b) {
					return a.title < b.title;
				});
		}
		else if (field == "album") {
			std::sort(songs.begin(), songs.end(),
				[](const Song& a, const Song& b) {
					return a.album < b.album;
				});
		}
		else if (field == "length") {
			std::sort(songs.begin(), songs.end(),
				[](const Song& a, const Song& b) {
					return a.length < b.length;
				});
		}
		else {
			throw std::invalid_argument("field to sort by must"
				" be: title, album, or length");
		}

	}

	void SongCollection::cleanAlbum()
	{
		std::replace_if(songs.begin(), songs.end(), [](const Song& s) {
			return s.album == "[None]";
			}, "");
	}

	bool SongCollection::inCollection(const std::string& name) const
	{
		return std::any_of(songs.cbegin(), songs.cend(),
			[&name](const Song& s) {
				return s.artist == name;
			});
	}


	std::list<Song> SongCollection::getSongsForArtist
	(const std::string& name) const
	{
		std::list<Song> l{};
		std::copy_if(songs.cbegin(), songs.cend(), back_inserter(l),
			[&name](const Song& s) {
				return name == s.artist;
			});
		return l;
	}

	std::ostream& operator<<(std::ostream& os, const Song& s)
	{
		os << "| " << std::left << std::setw(TITLE_WIDTH)
			<< s.title << " | " << std::setw(ARTIST_WIDTH)
			<< s.artist << " | " << std::setw(ALBUM_WIDTH)
			<< s.album << " | " << std::right
			<< std::setw(YEAR_WIDTH);

		if (s.year != 0ul)
			os << s.year;
		else
			os << "";

		os << " | " << std::setfill('0')
			<< (s.length / SEC_PER_MIN % MIN_PER_HOUR)
			<< ':' << std::setw(NUM_WIDTH)
			<< (s.length % SEC_PER_MIN) << " | "
			<< std::setfill(' ') << std::fixed
			<< std::setprecision(2)
			<< s.m_price << " |"
			<< std::setprecision(6);


		os.unsetf(std::ios::fixed);

		return os;
	}

	unsigned long operator+(unsigned long num, const Song& s)
	{
		return num + s.length;
	}

	void trim(std::string& str)
	{
		size_t i{ str.find_first_not_of(' ') };
		str = str.substr(i, str.find_last_not_of(' ') - i + 1);
	}

}