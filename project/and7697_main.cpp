#include "and7697_Controller.h"

int main(int argc, char *argv[])
{

    Library library {};
    View view (library);
    Controller controller (library, view);

//    controller.cli();
    controller.gui(argc, argv);
}
