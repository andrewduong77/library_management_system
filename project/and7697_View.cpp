#include "and7697_View.h"

string View::get_menu()
{
    return R"(
=========================
Library Management System
=========================

(1) Browse Catalog
(2) Add
(3) Check in
(4) Check out
(5) Save File
(6) Load File
(7) Exit
_> )";
}

string View::get_add_menu()
{
    return R"(
=========================
Library Management System
=========================

(1) Add Media
(2) Add Transaction
(3) Add Customer
(4) Add Librarian
(5) Add Bundle
(6) Cancel
_> )";
}

string View::get_add_media_menu()
{
    return R"(
============
Select Media
============

(1) Book
(2) Movie
(3) Video Game
(4) Music Album
(5) Television Show Season
(6) Cancel
_> )";
}

string View::print_try_again_message()
{
    return "Invalid selection. Try again!";
}
