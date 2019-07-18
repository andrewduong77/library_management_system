#ifndef AND7697_CONTROLLER_H_INCLUDED
#define AND7697_CONTROLLER_H_INCLUDED

#include "and7697_View.h"
#include "and7697_Book.h"
#include "and7697_Movie.h"
#include "and7697_Video_Game.h"
#include "and7697_Music_Album.h"
#include "and7697_Television_Show_Season.h"
#include "and7697_Dialog.h"

#include <fstream>

class Controller
{
public:
    Controller(Library& t, View& v) : library(t), view(v) {};
    int gui(int argc, char *argv[]);
    void cli();
    void execute_cmd(int cmd);
    void cli_add();
    int execute_cmd_add(int cmd_add);
    void cli_add_media();
    int execute_cmd_add_media(int cmd_add_media);
    void add_book();
    void add_movie();
    void add_video_game();
    void add_music_album();
    void add_television_show_season();
    void add_customer();
    void add_librarian();
    void save();
    void load();
private:
    Library& library;
    View& view;
};

#endif // AND7697_CONTROLLER_H_INCLUDED
