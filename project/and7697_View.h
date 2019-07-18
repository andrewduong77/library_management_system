#ifndef AND7697_VIEW_H_INCLUDED
#define AND7697_VIEW_H_INCLUDED

#include "and7697_Library.h"

class View
{
public:
    View(Library& l) : library(l) {};
    string get_menu();
    string get_add_menu();
    string get_add_media_menu();
    string print_try_again_message();
private:
    Library& library;
};

#endif // AND7697_VIEW_H_INCLUDED
