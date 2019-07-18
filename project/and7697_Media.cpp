#include "and7697_Media.h"

void Media::check_out()
{
    this->checked_out = true;
}

void Media::check_in()
{
    this->checked_out = false;
}

int Media::get_id_number()
{
    return id_number;
}

string Media::get_call_number()
{
    return call_number;
}

string Media::get_title()
{
    return title;
}

string Media::get_genre()
{
    return genre;
}

void Media::set_type(string type)
{
    this->type = type;
}

string Media::get_type()
{
    return type;
}

bool Media::is_checked_out()
{
    return checked_out;
}

string Media::to_string() const
{

}

string Media::to_file() const
{

}
