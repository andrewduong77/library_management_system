#include "and7697_Television_Show_Season.h"

int Television_Show_Season::get_release_year()
{
    return release_year;
}

string Television_Show_Season::get_producer()
{
    return producer;
}

string Television_Show_Season::voice_actors_to_string() const
{
    string out;
    ostringstream fmtStr;
    if(voice_actors.size() == 0)
    {
        out = "N/A";
        return out;
    }
    for(int i = 0; i < voice_actors.size(); i++)
    {
        fmtStr << voice_actors[i];
        if(i < voice_actors.size() - 1)
            fmtStr << ", ";
        out = fmtStr.str();
    }
    return out;
}

string Television_Show_Season::voice_actors_to_file() const
{
    string out;
    ostringstream ost;
    for(int i = 0; i < voice_actors.size(); i++)
    {
        ost << voice_actors[i];
        if(i < voice_actors.size() - 1)
            ost << ":";
        out = ost.str();
    }
    return out;
}

string Television_Show_Season::composers_to_string() const
{
    string out;
    ostringstream fmtStr;
    if(composers.size() == 0)
    {
        out = "N/A";
        return out;
    }
    for(int i = 0; i < composers.size(); i++)
    {
        fmtStr << composers[i];
        if(i < composers.size() - 1)
            fmtStr << ", ";
        out = fmtStr.str();
    }
    return out;
}

string Television_Show_Season::composers_to_file() const
{
    string out;
    ostringstream ost;
    for(int i = 0; i < composers.size(); i++)
    {
        ost << composers[i];
        if(i < composers.size() - 1)
            ost << ":";
        out = ost.str();
    }
    return out;
}

int Television_Show_Season::get_season_number()
{
    return season_number;
}

string Television_Show_Season::to_string() const
{
    string out;
    ostringstream ost;
    ost << R"(
== Television Show Season ==
              )" << endl;
    ost << "    ID Number: " << this->id_number << endl;
    ost << "    Call Number: " << this->call_number << endl;
    ost << "    Title: " << this->title << " (" << this->release_year << ")" << endl;
    ost << "    Genre: " << this->genre << endl;
    ost << "    Producer: " << this->producer << endl;
    ost << "    Directors: " << this->voice_actors_to_string() << endl;
    ost << "    Leading Actors: " << this->composers_to_string() << endl;
    ost << "    Season Number: " << this->season_number << endl;
    out = ost.str();
    return out;
}

string Television_Show_Season::to_file() const
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
        << this->voice_actors_to_file() << ";"
        << this->composers_to_file() << ";"
        << this->season_number << endl;
    out = ost.str();
    return out;
}

ostream& operator<<(ostream& ost, const Television_Show_Season& television_show_season_two)
{
    ost << R"(
== Television Show Season ==
              )" << endl;
    ost << "    ID Number: " << television_show_season_two.id_number << endl;
    ost << "    Call Number: " << television_show_season_two.call_number << endl;
    ost << "    Title: " << television_show_season_two.title << " (" << television_show_season_two.release_year << ")" << endl;
    ost << "    Genre: " << television_show_season_two.genre << endl;
    ost << "    Producer: " << television_show_season_two.producer << endl;
    ost << "    Directors: " << television_show_season_two.voice_actors_to_string() << endl;
    ost << "    Leading Actors: " << television_show_season_two.composers_to_string() << endl;
    ost << "    Season Number: " << television_show_season_two.season_number << endl;
    return ost;
}
