#include "and7697_Video_Game.h"

int Video_Game::get_release_year()
{
    return release_year;
}

string Video_Game::get_studio()
{
    return studio;
}

string Video_Game::to_string() const
{
    string out;
    ostringstream ost;
    ost << R"(
== Video Game ==
              )" << endl;
    ost << "    ID Number: " << this->id_number << endl;
    ost << "    Call Number: " << this->call_number << endl;
    ost << "    Title: " << this->title << " (" << this->release_year << ")" << endl;
    ost << "    Genre: " << this->genre << endl;
    ost << "    Studio: " << this->studio << endl;
    out = ost.str();
    return out;
}

string Video_Game::to_file() const
{
    string out;
    ostringstream ost;
    ost << this->type << ";"
        << this->id_number << ";"
        << this->call_number << ";"
        << this->title << ";"
        << this->genre << ";"
        << this->release_year << ";"
        << this->studio << endl;
    out = ost.str();
    return out;
}

ostream& operator<<(ostream& ost, const Video_Game& video_game_two)
{
    ost << R"(
== Video Game ==
              )" << endl;
    ost << "    ID Number: " << video_game_two.id_number << endl;
    ost << "    Call Number: " << video_game_two.call_number << endl;
    ost << "    Title: " << video_game_two.title << " (" << video_game_two.release_year << ")" << endl;
    ost << "    Genre: " << video_game_two.genre << endl;
    ost << "    Studio: " << video_game_two.studio << endl;
    return ost;
}
