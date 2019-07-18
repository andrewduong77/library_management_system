#ifndef AND7697_MOVIE_H_INCLUDED
#define AND7697_MOVIE_H_INCLUDED

#include "and7697_Media.h"

class Movie : public Media
{
public:
    Movie(int idn, string cn, string t, string g, int r, string p, string d, vector<string> la) : Media(idn, cn, t, g), release_year {r}, producer {p}, director {d}, leading_actors {la} {set_type("Movie");};
    int get_release_year();
    string get_producer();
    string get_director();
    string leading_actors_to_string() const;
    string leading_actors_to_file() const;
    string to_string() const;
    string to_file() const;
    friend ostream& operator<<(ostream& ost, const Movie& movie_two);
private:
    int release_year;
    string producer;
    string director;
    vector<string> leading_actors;
};

#endif // AND7697_MOVIE_H_INCLUDED
