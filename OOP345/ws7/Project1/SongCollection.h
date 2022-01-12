//Name: Alon Raigorodetsky
//User ID: 109763201
//Date: 13/11/2021
//email: araigorodetsky@myseneca.ca


//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H

#include <iostream>
#include <vector>
#include <list>
#include <string>

namespace sdds
{
	//field sizes
	const size_t MAX_STR_SIZE{ 25 };
	const size_t MAX_NUM_SIZE{ 5 };
	//data format
	const int TITLE_WIDTH{ 20 };
	const int ARTIST_WIDTH{ 15 };
	const int ALBUM_WIDTH{ 20 };
	const int YEAR_WIDTH{ 6 };
	const int NUM_WIDTH{ 2 };
	//time rates
	const unsigned long SEC_PER_MIN{ 60 };
	const unsigned long MIN_PER_HOUR{ 60 };

	struct Song {
		std::string artist{};
		std::string title{};
		std::string album{};
		double m_price{ 0.0 };
		unsigned long year{ 0 };
		unsigned long length{ 0 };

		std::string operator=(const std::string& al);
	};

	class SongCollection {

		std::vector<Song> songs;

	public:
		SongCollection(const std::string& file);
		void display(std::ostream& out) const;
		void sort(const std::string& field);
		void cleanAlbum();
		bool inCollection(const std::string& name) const;
		std::list<Song> getSongsForArtist(const std::string& name) const;

	};
	std::ostream& operator<<(std::ostream& out, const Song& theSong);
	unsigned long operator+(unsigned long num, const Song& s);
	void trim(std::string& str);
}
#endif // SDDS_SONGCOLLECTION_H