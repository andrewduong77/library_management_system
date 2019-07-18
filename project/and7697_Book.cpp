#include "and7697_Book.h"

string Book::get_author()
{
    return author;
}

int Book::get_copyright_year()
{
    return copyright_year;
}

string Book::to_string() const
{
    string out;
    ostringstream ost;
    ost << R"(
== Book ==
              )" << endl;
    ost << "    ID Number: " << this->id_number << endl;
    ost << "    Call Number: " << this->call_number << endl;
    ost << "    Title: " << this->title << endl;
    ost << "    Genre: " << this->genre << endl;
    ost << "    Author: " << this->author << endl;
    ost << "    Copyright Year: " << this->copyright_year << endl;
    out = ost.str();
    return out;
}

string Book::to_file() const
{
    string out;
    ostringstream ost;
    ost << this->type << ";"
        << this->id_number << ";"
        << this->call_number << ";"
        << this->title << ";"
        << this->genre << ";"
        << this->author << ";"
        << this->copyright_year << endl;
    out = ost.str();
    return out;
}

ostream& operator<<(ostream& ost, const Book& book_two)
{
    ost << R"(
== Book ==
              )" << endl;
    ost << "    ID Number: " << book_two.id_number << endl;
    ost << "    Call Number: " << book_two.call_number << endl;
    ost << "    Title: " << book_two.title << endl;
    ost << "    Genre: " << book_two.genre << endl;
    ost << "    Author: " << book_two.author << endl;
    ost << "    Copyright Year: " << book_two.copyright_year << endl;
    return ost;
}
