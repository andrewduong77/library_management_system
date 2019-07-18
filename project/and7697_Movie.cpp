#include "and7697_Movie.h"

int Movie::get_release_year()
{
    return release_year;
}

string Movie::get_producer()
{
    return producer;
}

string Movie::get_director()
{
    return director;
}

string Movie::leading_actors_to_string() const
{
    string out;
    ostringstream ost;
    if(leading_actors.size() == 0)
    {
        out = "N/A";
        return out;
    }
    for(int i = 0; i < leading_actors.size(); i++)
    {
        ost << leading_actors[i];
        if(i < leading_actors.size() - 1)
            ost << ", "; // print commas
        out = ost.str(); // convert
    }
    return out;
}

string Movie::leading_actors_to_file() const
{
    string out;
    ostringstream ost;
    for(int i = 0; i < leading_actors.size(); i++)
    {
        ost << leading_actors[i];
        if(i < leading_actors.size() - 1)
            ost << ":";
        out = ost.str();
    }
    return out;
}

string Movie::to_string() const
{
    string out;
    ostringstream ost;
    ost << R"(
== Movie ==
              )" << endl;
    ost << "    ID Number: " << this->id_number << endl;
    ost << "    Call Number: " << this->call_number << endl;
    ost << "    Title: " << this->title << " (" << this->release_year << ")" << endl;
    ost << "    Genre: " << this->genre << endl;
    ost << "    Release Year: " << this->release_year << endl;
    ost << "    Producer: " << this->producer << endl;
    ost << "    Director: " << this->director << endl;
    ost << "    Leading Actors: " << this->leading_actors_to_string() << endl;
    out = ost.str();
    return out;
}

string Movie::to_file() const
{
    string out;
    ostringstream ost;
    ost << this->type << ";"
        << this->id_number << ";"
        << this->call_number << ";"
        << this->title << ";"
        << this->genre << ";"
        << this->release_year << ";"
        << this->producer << ";"
        << this->director << ";"
        << this->leading_actors_to_file() << endl;
    out = ost.str();
    return out;
}

ostream& operator<<(ostream& ost, const Movie& movie_two)
{
    ost << R"(
== Movie ==
              )" << endl;
    ost << "    ID Number: " << movie_two.id_number << endl;
    ost << "    Call Number: " << movie_two.call_number << endl;
    ost << "    Title: " << movie_two.title << " (" << movie_two.release_year << ")" << endl;
    ost << "    Genre: " << movie_two.genre << endl;
    ost << "    Release Year: " << movie_two.release_year << endl;
    ost << "    Producer: " << movie_two.producer << endl;
    ost << "    Director: " << movie_two.director << endl;
    ost << "    Leading Actors: " << movie_two.leading_actors_to_string() << endl;
    return ost;
}
