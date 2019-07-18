#include "and7697_Dialog.h"

Dialog::Dialog(Library& l) : library(l)
{
    set_title("Library Management System");

    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    add(*vbox);

    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);
    Gtk::MenuItem *menuitem_save = Gtk::manage(new Gtk::MenuItem("_Save", true));
    menuitem_save->signal_activate().connect(sigc::mem_fun(*this, &Dialog::on_save_button_click));
    filemenu->append(*menuitem_save);
    Gtk::MenuItem *menuitem_load = Gtk::manage(new Gtk::MenuItem("_Load", true));
    menuitem_load->signal_activate().connect(sigc::mem_fun(*this, &Dialog::on_load_button_click));
    filemenu->append(*menuitem_load);
    Gtk::MenuItem *menuitem_exit = Gtk::manage(new Gtk::MenuItem("_Exit", true));
    menuitem_exit->signal_activate().connect(sigc::mem_fun(*this, &Dialog::on_exit_click));
    filemenu->append(*menuitem_exit);

    Gtk::Box *hbox1 = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
    vbox->add(*hbox1);

    Gtk::Box *vbox1 = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    hbox1->add(*vbox1);

    Gtk::Grid *grid1 = Gtk::manage(new Gtk::Grid);
    grid1->set_border_width(10);
    vbox1->add(*grid1);

    Gtk::Label *label_main_menu = Gtk::manage(new Gtk::Label("View"));
    grid1->attach(*label_main_menu, 0, 0, 1, 1);

    Gtk::Button *button_browse_catalog = Gtk::manage(new Gtk::Button("Browse Catalog"));
    button_browse_catalog->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_browse_catalog_button_click));
    grid1->attach(*button_browse_catalog, 0, 1, 1, 1);

    Gtk::Button *button_view_checked_out_list = Gtk::manage(new Gtk::Button("View Checked Out List"));
    button_view_checked_out_list->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_view_checked_out_list_button_click));
    grid1->attach(*button_view_checked_out_list, 0, 2, 1, 1);

    Gtk::Button *button_view_checked_out_bundle_list = Gtk::manage(new Gtk::Button("View Checked Out Bundle List"));
    button_view_checked_out_bundle_list->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_view_checked_out_bundle_list_button_click));
    grid1->attach(*button_view_checked_out_bundle_list, 0, 3, 1, 1);

    Gtk::Button *button_view_transactions = Gtk::manage(new Gtk::Button("View Transactions"));
    button_view_transactions->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_view_transactions_button_click));
    grid1->attach(*button_view_transactions, 0, 4, 1, 1);

    Gtk::Button *button_view_customers = Gtk::manage(new Gtk::Button("View Customers"));
    button_view_customers->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_view_customers_button_click));
    grid1->attach(*button_view_customers, 0, 5, 1, 1);

    Gtk::Button *button_view_librarians = Gtk::manage(new Gtk::Button("View Librarians"));
    button_view_librarians->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_view_librarians_button_click));
    grid1->attach(*button_view_librarians, 0, 6, 1, 1);

    Gtk::Button *button_view_bundles = Gtk::manage(new Gtk::Button("View Bundles"));
    button_view_bundles->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_view_bundles_button_click));
    grid1->attach(*button_view_bundles, 0, 7, 1, 1);

    Gtk::Box *vbox2 = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    hbox1->add(*vbox2);

    Gtk::Grid *grid2 = Gtk::manage(new Gtk::Grid);
    grid2->set_border_width(10);
    vbox2->add(*grid2);

    Gtk::Label *label_add = Gtk::manage(new Gtk::Label("Add"));
    grid2->attach(*label_add, 0, 0, 1, 1);

    Gtk::Button *button_add_transaction = Gtk::manage(new Gtk::Button("Add Transaction"));
    button_add_transaction->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_add_transaction_button_click));
    grid2->attach(*button_add_transaction, 0, 1, 1, 1);

    Gtk::Button *button_add_customer = Gtk::manage(new Gtk::Button("Add Customer"));
    button_add_customer->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_add_customer_button_click));
    grid2->attach(*button_add_customer, 0, 2, 1, 1);

    Gtk::Button *button_add_librarian = Gtk::manage(new Gtk::Button("Add Librarian"));
    button_add_librarian->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_add_librarian_button_click));
    grid2->attach(*button_add_librarian, 0, 3, 1, 1);

    Gtk::Button *button_add_bundle = Gtk::manage(new Gtk::Button("Add Bundle"));
    button_add_bundle->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_add_bundle_button_click));
    grid2->attach(*button_add_bundle, 0, 4, 1, 1);

    Gtk::Box *vbox3 = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    hbox1->add(*vbox3);

    Gtk::Grid *grid3 = Gtk::manage(new Gtk::Grid);
    grid3->set_border_width(10);
    vbox3->add(*grid3);

    Gtk::Label *label_add_media = Gtk::manage(new Gtk::Label("Add Media"));
    grid3->attach(*label_add_media, 0, 0, 1, 1);

    Gtk::Button *button_add_book = Gtk::manage(new Gtk::Button("Add Book"));
    button_add_book->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_add_book_button_click));
    grid3->attach(*button_add_book, 0, 1, 1, 1);

    Gtk::Button *button_add_movie = Gtk::manage(new Gtk::Button("Add Movie"));
    button_add_movie->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_add_movie_button_click));
    grid3->attach(*button_add_movie, 0, 2, 1, 1);

    Gtk::Button *button_add_video_game = Gtk::manage(new Gtk::Button("Add Video Game"));
    button_add_video_game->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_add_video_game_button_click));
    grid3->attach(*button_add_video_game, 0, 3, 1, 1);

    Gtk::Button *button_add_music_album = Gtk::manage(new Gtk::Button("Add Music Album"));
    button_add_music_album->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_add_music_album_button_click));
    grid3->attach(*button_add_music_album, 0, 4, 1, 1);

    Gtk::Button *button_add_television_show_season = Gtk::manage(new Gtk::Button("Add Television Show Season"));
    button_add_television_show_season->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_add_television_show_season_button_click));
    grid3->attach(*button_add_television_show_season, 0, 5, 1, 1);

    Gtk::Box *vbox4 = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    hbox1->add(*vbox4);

    Gtk::Grid *grid4 = Gtk::manage(new Gtk::Grid);
    grid4->set_border_width(10);
    vbox4->add(*grid4);

    Gtk::Label *label_other = Gtk::manage(new Gtk::Label("Other"));
    grid4->attach(*label_other, 0, 0, 1, 1);

    Gtk::Button *button_check_in = Gtk::manage(new Gtk::Button("Check in"));
    button_check_in->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_check_in_button_click));
    grid4->attach(*button_check_in, 0, 1, 1, 1);

    Gtk::Button *button_check_out = Gtk::manage(new Gtk::Button("Check out"));
    button_check_out->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_check_out_button_click));
    grid4->attach(*button_check_out, 0, 2, 1, 1);

    Gtk::Button *button_check_in_bundle = Gtk::manage(new Gtk::Button("Check in Bundle"));
    button_check_in_bundle->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_check_in_bundle_button_click));
    grid4->attach(*button_check_in_bundle, 0, 3, 1, 1);

    Gtk::Button *button_check_out_bundle = Gtk::manage(new Gtk::Button("Check out Bundle"));
    button_check_out_bundle->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_check_out_bundle_button_click));
    grid4->attach(*button_check_out_bundle, 0, 4, 1, 1);

    Gtk::Button *button_pay_balance = Gtk::manage(new Gtk::Button("Pay Balance"));
    button_pay_balance->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_pay_balance_button_click));
    grid4->attach(*button_pay_balance, 0, 5, 1, 1);

    Gtk::Box *hbox2 = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
    vbox->add(*hbox2);

    Gtk::Button *button_save = Gtk::manage(new Gtk::Button("Save"));
    button_save->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_save_button_click));
    hbox2->pack_start(*button_save);

    Gtk::Button *button_load = Gtk::manage(new Gtk::Button("Load"));
    button_load->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_load_button_click));
    hbox2->pack_start(*button_load);

    Gtk::Button *button_exit = Gtk::manage(new Gtk::Button("Exit"));
    button_exit->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_exit_click));
    hbox2->pack_start(*button_exit);

    vbox->show_all();
}

Dialog::~Dialog()
{
    //dtor
}

/*
***For Main Menu***
*/

void Dialog::on_browse_catalog_button_click()
{
    string display;

    if(library.get_medias().size() <= 0)
        display = "The catalog is empty.";
    else
        display = library.print_medias_to_string();

    Gtk::Window *window_browse_catalog = new Gtk::Window();
    window_browse_catalog->set_default_size(600, 600);
    window_browse_catalog->set_title("Browse Catalog");
    
    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    window_browse_catalog->add(*vbox);

    Gtk::Grid *grid = Gtk::manage(new Gtk::Grid);
    grid->set_border_width(10);
    vbox->add(*grid);

    Gtk::Label *label = Gtk::manage(new Gtk::Label("Browse Catalog"));
    grid->attach(*label, 0, 0, 1, 1);

    Glib::RefPtr<Gtk::TextBuffer> textbuffer;
    textbuffer = Gtk::TextBuffer::create();
    textbuffer->set_text(display);
    
    Gtk::ScrolledWindow *scrolledwindow = Gtk::manage(new Gtk::ScrolledWindow());
    scrolledwindow->set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
    vbox->pack_start(*scrolledwindow);

    Gtk::TextView *textview = Gtk::manage(new Gtk::TextView());
    textview->set_editable(false);
    textview->set_buffer(textbuffer);
    scrolledwindow->add(*textview);

    window_browse_catalog->show_all();
}

void Dialog::on_view_checked_out_list_button_click()
{
    string display;

    if(library.get_checked_out_list().size() <= 0)
        display = "The are nothing checked out.";
    else
        display = library.print_checked_out_list_to_string();

    Gtk::Window *window_view_checked_out_list = new Gtk::Window();
    window_view_checked_out_list->set_default_size(600, 600);
    window_view_checked_out_list->set_title("View Checked Out List");
    
    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    window_view_checked_out_list->add(*vbox);

    Gtk::Grid *grid = Gtk::manage(new Gtk::Grid);
    grid->set_border_width(10);
    vbox->add(*grid);

    Gtk::Label *label = Gtk::manage(new Gtk::Label("View Checked Out List"));
    grid->attach(*label, 0, 0, 1, 1);

    Glib::RefPtr<Gtk::TextBuffer> textbuffer;
    textbuffer = Gtk::TextBuffer::create();
    textbuffer->set_text(display);
    
    Gtk::ScrolledWindow *scrolledwindow = Gtk::manage(new Gtk::ScrolledWindow());
    scrolledwindow->set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
    vbox->pack_start(*scrolledwindow);

    Gtk::TextView *textview = Gtk::manage(new Gtk::TextView());
    textview->set_editable(false);
    textview->set_buffer(textbuffer);
    scrolledwindow->add(*textview);

    window_view_checked_out_list->show_all();
}

void Dialog::on_view_checked_out_bundle_list_button_click()
{
    string display;

    if(library.get_checked_out_bundle_list().size() <= 0)
        display = "The are nothing checked out.";
    else
        display = library.print_checked_out_bundle_list_to_string();

    Gtk::Window *window_view_checked_out_bundle_list = new Gtk::Window();
    window_view_checked_out_bundle_list->set_default_size(600, 600);
    window_view_checked_out_bundle_list->set_title("View Checked Out List");
    
    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    window_view_checked_out_bundle_list->add(*vbox);

    Gtk::Grid *grid = Gtk::manage(new Gtk::Grid);
    grid->set_border_width(10);
    vbox->add(*grid);

    Gtk::Label *label = Gtk::manage(new Gtk::Label("View Checked Out List"));
    grid->attach(*label, 0, 0, 1, 1);

    Glib::RefPtr<Gtk::TextBuffer> textbuffer;
    textbuffer = Gtk::TextBuffer::create();
    textbuffer->set_text(display);
    
    Gtk::ScrolledWindow *scrolledwindow = Gtk::manage(new Gtk::ScrolledWindow());
    scrolledwindow->set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
    vbox->pack_start(*scrolledwindow);

    Gtk::TextView *textview = Gtk::manage(new Gtk::TextView());
    textview->set_editable(false);
    textview->set_buffer(textbuffer);
    scrolledwindow->add(*textview);

    window_view_checked_out_bundle_list->show_all();
}

void Dialog::on_view_transactions_button_click()
{
    string display;

    if(library.get_transactions().size() <= 0)
        display = "There are no transactions";
    else
        display = library.print_transactions_to_string();

    Gtk::Window *window_browse_catalog = new Gtk::Window();
    window_browse_catalog->set_default_size(600, 600);
    window_browse_catalog->set_title("Transactions");
    
    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    window_browse_catalog->add(*vbox);

    Gtk::Grid *grid = Gtk::manage(new Gtk::Grid);
    grid->set_border_width(10);
    vbox->add(*grid);

    Gtk::Label *label = Gtk::manage(new Gtk::Label("Transactions"));
    grid->attach(*label, 0, 0, 1, 1);

    Glib::RefPtr<Gtk::TextBuffer> textbuffer;
    textbuffer = Gtk::TextBuffer::create();
    textbuffer->set_text(display);
    
    Gtk::ScrolledWindow *scrolledwindow = Gtk::manage(new Gtk::ScrolledWindow());
    scrolledwindow->set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
    vbox->pack_start(*scrolledwindow);

    Gtk::TextView *textview = Gtk::manage(new Gtk::TextView());
    textview->set_editable(false);
    textview->set_buffer(textbuffer);
    scrolledwindow->add(*textview);

    window_browse_catalog->show_all();
}

void Dialog::on_view_customers_button_click()
{
    string display;

    if(library.get_customers().size() <= 0)
        display = "There are no customers";
    else
        display = library.print_customers_to_string();

    Gtk::Window *window_browse_catalog = new Gtk::Window();
    window_browse_catalog->set_default_size(600, 600);
    window_browse_catalog->set_title("Customers");
    
    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    window_browse_catalog->add(*vbox);

    Gtk::Grid *grid = Gtk::manage(new Gtk::Grid);
    grid->set_border_width(10);
    vbox->add(*grid);

    Gtk::Label *label = Gtk::manage(new Gtk::Label("Customers"));
    grid->attach(*label, 0, 0, 1, 1);

    Glib::RefPtr<Gtk::TextBuffer> textbuffer;
    textbuffer = Gtk::TextBuffer::create();
    textbuffer->set_text(display);
    
    Gtk::ScrolledWindow *scrolledwindow = Gtk::manage(new Gtk::ScrolledWindow());
    scrolledwindow->set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
    vbox->pack_start(*scrolledwindow);

    Gtk::TextView *textview = Gtk::manage(new Gtk::TextView());
    textview->set_editable(false);
    textview->set_buffer(textbuffer);
    scrolledwindow->add(*textview);

    window_browse_catalog->show_all();
}

void Dialog::on_view_librarians_button_click()
{
    string display;

    if(library.get_librarians().size() <= 0)
        display = "There are no librarians";
    else
        display = library.print_librarians_to_string();

    Gtk::Window *window_browse_catalog = new Gtk::Window();
    window_browse_catalog->set_default_size(600, 600);
    window_browse_catalog->set_title("Librarians");
    
    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    window_browse_catalog->add(*vbox);

    Gtk::Grid *grid = Gtk::manage(new Gtk::Grid);
    grid->set_border_width(10);
    vbox->add(*grid);

    Gtk::Label *label = Gtk::manage(new Gtk::Label("Librarians"));
    grid->attach(*label, 0, 0, 1, 1);

    Glib::RefPtr<Gtk::TextBuffer> textbuffer;
    textbuffer = Gtk::TextBuffer::create();
    textbuffer->set_text(display);
    
    Gtk::ScrolledWindow *scrolledwindow = Gtk::manage(new Gtk::ScrolledWindow());
    scrolledwindow->set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
    vbox->pack_start(*scrolledwindow);

    Gtk::TextView *textview = Gtk::manage(new Gtk::TextView());
    textview->set_editable(false);
    textview->set_buffer(textbuffer);
    scrolledwindow->add(*textview);

    window_browse_catalog->show_all();
}

void Dialog::on_view_bundles_button_click()
{
    string display;

    if(library.get_bundles().size() <= 0)
        display = "There are no bundles.";
    else
        display = library.print_bundles_to_string();

    Gtk::Window *window_view_bundles = new Gtk::Window();
    window_view_bundles->set_default_size(600, 600);
    window_view_bundles->set_title("View Bundles");
    
    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    window_view_bundles->add(*vbox);

    Gtk::Grid *grid = Gtk::manage(new Gtk::Grid);
    grid->set_border_width(10);
    vbox->add(*grid);

    Gtk::Label *label = Gtk::manage(new Gtk::Label("View Bundles"));
    grid->attach(*label, 0, 0, 1, 1);

    Glib::RefPtr<Gtk::TextBuffer> textbuffer;
    textbuffer = Gtk::TextBuffer::create();
    textbuffer->set_text(display);
    
    Gtk::ScrolledWindow *scrolledwindow = Gtk::manage(new Gtk::ScrolledWindow());
    scrolledwindow->set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
    vbox->pack_start(*scrolledwindow);

    Gtk::TextView *textview = Gtk::manage(new Gtk::TextView());
    textview->set_editable(false);
    textview->set_buffer(textbuffer);
    scrolledwindow->add(*textview);

    window_view_bundles->show_all();
}

// *Check In*
void Dialog::on_check_in_button_click()
{
    window_check_in = new Gtk::Window();
    window_check_in->set_title("Check In");

    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    window_check_in->add(*vbox);

    Gtk::Box *hbox_top = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
    vbox->add(*hbox_top);

    Gtk::Grid *grid1 = Gtk::manage(new Gtk::Grid);
    grid1->set_border_width(10);
    hbox_top->add(*grid1);

    Gtk::Label *label = Gtk::manage(new Gtk::Label("Please input the id number of the media you would like to check in: "));
    grid1->attach(*label, 0, 0, 1, 1);

    entry_id_number = Gtk::manage(new Gtk::Entry());
    entry_id_number->set_text("");
    entry_id_number->set_max_length(50);
    grid1->attach(*entry_id_number, 0, 1, 1, 1);

    Gtk::Box *hbox_bottom = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
    vbox->add(*hbox_bottom);

    Gtk::Grid *grid2 = Gtk::manage(new Gtk::Grid);
    grid2->set_border_width(10);
    hbox_bottom->add(*grid2);
    
    Gtk::Button *button_cancel = Gtk::manage(new Gtk::Button("Cancel"));
    button_cancel->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_check_in_cancel_button_click));
    grid2->attach(*button_cancel, 0, 2, 1, 1);
    
    Gtk::Button *button_ok = Gtk::manage(new Gtk::Button("OK"));
    button_ok->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_check_in_ok_button_click));
    grid2->attach(*button_ok, 1, 2, 1, 1);

    window_check_in->show_all();
}
void Dialog::on_check_in_ok_button_click()
{
    string id_number_str = entry_id_number->get_text();
    stringstream id_number_geek(id_number_str);
    int id_number;
    id_number_geek >> id_number;
    bool found = false;
    for(Media* it : library.get_medias())
    {
        if(id_number == it->get_id_number())
        {
            found = true;
            if(it->is_checked_out() == false) // if is not checked out then display is checked in
            {
                window_check_in->close();
                dialog("\"" + it->get_title() + "\" is already checked in.");
                break;
            }
            else // if is checked out then call check_in()
            {
                it->check_in();
                library.remove_checked_out_media(id_number);
                window_check_in->close();
                dialog("\"" + it->get_title() + "\" checked in.");
                break;
            }
        }
    }
    if(!found)
        dialog("Media with ID Number " + id_number_str + " is not found.");
    delete(window_check_in);
}
void Dialog::on_check_in_cancel_button_click()
{
    window_check_in->close();
    delete(window_check_in);
}

// *Check Out*
void Dialog::on_check_out_button_click()
{
    window_check_out = new Gtk::Window();
    window_check_out->set_title("Check Out");

    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    window_check_out->add(*vbox);

    Gtk::Box *hbox_top = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
    vbox->add(*hbox_top);

    Gtk::Grid *grid1 = Gtk::manage(new Gtk::Grid);
    grid1->set_border_width(10);
    hbox_top->add(*grid1);

    Gtk::Label *label = Gtk::manage(new Gtk::Label("Please input the id number of the media you would like to check out: "));
    grid1->attach(*label, 0, 0, 1, 1);

    entry_id_number = Gtk::manage(new Gtk::Entry());
    entry_id_number->set_text("");
    entry_id_number->set_max_length(50);
    grid1->attach(*entry_id_number, 0, 1, 1, 1);

    Gtk::Box *hbox_bottom = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
    vbox->add(*hbox_bottom);

    Gtk::Grid *grid2 = Gtk::manage(new Gtk::Grid);
    grid2->set_border_width(10);
    hbox_bottom->add(*grid2);
    
    Gtk::Button *button_cancel = Gtk::manage(new Gtk::Button("Cancel"));
    button_cancel->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_check_out_cancel_button_click));
    grid2->attach(*button_cancel, 0, 2, 1, 1);
    
    Gtk::Button *button_ok = Gtk::manage(new Gtk::Button("OK"));
    button_ok->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_check_out_ok_button_click));
    grid2->attach(*button_ok, 1, 2, 1, 1);

    window_check_out->show_all();
}
void Dialog::on_check_out_ok_button_click()
{
    string id_number_str = entry_id_number->get_text();
    stringstream id_number_geek(id_number_str);
    int id_number;
    id_number_geek >> id_number;
    bool found = false;
    for(Media* it : library.get_medias())
    {
        if(id_number == it->get_id_number())
        {
            found = true;
            if(it->is_checked_out() == true) // if is not checked out then display is checked out
            {
                window_check_out->close();
                dialog("\"" + it->get_title() + "\" is already checked out.");
                break;
            }
            else // if is checked out then call check_out()
            {
                it->check_out();
                library.create_new_checked_out_media(it);
                window_check_out->close();
                dialog("\"" + it->get_title() + "\" checked out.");
                break;
            }
        }
    }
    if(!found)
        dialog("Media with ID Number " + id_number_str + " is not found.");
    delete(window_check_out);
}
void Dialog::on_check_out_cancel_button_click()
{
    window_check_out->close();
    delete(window_check_out);
}

// *Check In Bundle*
void Dialog::on_check_in_bundle_button_click()
{
    window_check_in_bundle = new Gtk::Window();
    window_check_in_bundle->set_title("Check In Bundle");

    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    window_check_in_bundle->add(*vbox);

    Gtk::Box *hbox_top = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
    vbox->add(*hbox_top);

    Gtk::Grid *grid1 = Gtk::manage(new Gtk::Grid);
    grid1->set_border_width(10);
    hbox_top->add(*grid1);

    Gtk::Label *label = Gtk::manage(new Gtk::Label("Please input the name of the bundle you would like to check in: "));
    grid1->attach(*label, 0, 0, 1, 1);

    entry_name = Gtk::manage(new Gtk::Entry());
    entry_name->set_text("");
    entry_name->set_max_length(50);
    grid1->attach(*entry_name, 0, 1, 1, 1);

    Gtk::Box *hbox_bottom = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
    vbox->add(*hbox_bottom);

    Gtk::Grid *grid2 = Gtk::manage(new Gtk::Grid);
    grid2->set_border_width(10);
    hbox_bottom->add(*grid2);
    
    Gtk::Button *button_cancel = Gtk::manage(new Gtk::Button("Cancel"));
    button_cancel->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_check_in_bundle_cancel_button_click));
    grid2->attach(*button_cancel, 0, 2, 1, 1);
    
    Gtk::Button *button_ok = Gtk::manage(new Gtk::Button("OK"));
    button_ok->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_check_in_bundle_ok_button_click));
    grid2->attach(*button_ok, 1, 2, 1, 1);

    window_check_in_bundle->show_all();
}
void Dialog::on_check_in_bundle_ok_button_click()
{
    string name = entry_name->get_text();
    bool found = false;
    for(Bundle* it : library.get_bundles())
    {
        if(to_lower_case(name) == to_lower_case(it->get_name()))
        {
            found = true;
            if(it->is_checked_out() == false) // if is not checked out then display is checked in
            {
                window_check_in_bundle->close();
                dialog("\"" + it->get_name() + "\" bundle is already checked in.");
                break;
            }
            else // if is checked out then call check_in_bundle()
            {
                it->check_in_bundle();
                library.remove_checked_out_bundle(name);
                window_check_in_bundle->close();
                dialog("\"" + it->get_name() + "\" bundle checked in.");
                break;
            }
        }
    }
    if(!found)
        dialog("Bundle with ID Number " + name + " is not found.");
    delete(window_check_in_bundle);
}
void Dialog::on_check_in_bundle_cancel_button_click()
{
    window_check_in_bundle->close();
    delete(window_check_in_bundle);
}

// *Check Out Bundle*
void Dialog::on_check_out_bundle_button_click()
{
    window_check_out_bundle = new Gtk::Window();
    window_check_out_bundle->set_title("Check Out Bundle");

    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    window_check_out_bundle->add(*vbox);

    Gtk::Box *hbox_top = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
    vbox->add(*hbox_top);

    Gtk::Grid *grid1 = Gtk::manage(new Gtk::Grid);
    grid1->set_border_width(10);
    hbox_top->add(*grid1);

    Gtk::Label *label = Gtk::manage(new Gtk::Label("Please input the name of the bundle you would like to check out: "));
    grid1->attach(*label, 0, 0, 1, 1);

    entry_name = Gtk::manage(new Gtk::Entry());
    entry_name->set_text("");
    entry_name->set_max_length(50);
    grid1->attach(*entry_name, 0, 1, 1, 1);

    Gtk::Box *hbox_bottom = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
    vbox->add(*hbox_bottom);

    Gtk::Grid *grid2 = Gtk::manage(new Gtk::Grid);
    grid2->set_border_width(10);
    hbox_bottom->add(*grid2);
    
    Gtk::Button *button_cancel = Gtk::manage(new Gtk::Button("Cancel"));
    button_cancel->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_check_out_bundle_cancel_button_click));
    grid2->attach(*button_cancel, 0, 2, 1, 1);
    
    Gtk::Button *button_ok = Gtk::manage(new Gtk::Button("OK"));
    button_ok->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_check_out_bundle_ok_button_click));
    grid2->attach(*button_ok, 1, 2, 1, 1);

    window_check_out_bundle->show_all();
}
void Dialog::on_check_out_bundle_ok_button_click()
{
    string name = entry_name->get_text();
    bool found = false;
    for(Bundle* it : library.get_bundles())
    {
        if(to_lower_case(name) == to_lower_case(it->get_name()))
        {
            found = true;
            if(it->is_checked_out() == true) // if is not checked out then display is checked out
            {
                window_check_out_bundle->close();
                dialog("\"" + it->get_name() + "\" bundle is already checked out.");
                break;
            }
            else // if is checked out then call check_out_bundle()
            {
                it->check_out_bundle();
                library.create_new_checked_out_bundle(it);
                window_check_out_bundle->close();
                dialog("\"" + it->get_name() + "\" bundle checked out.");
                break;
            }
        }
    }
    if(!found)
        dialog("Bundle with ID Number " + name + " is not found.");
    delete(window_check_out_bundle);
}
void Dialog::on_check_out_bundle_cancel_button_click()
{
    window_check_out_bundle->close();
    delete(window_check_out_bundle);
}

// *Pay Balance*
void Dialog::on_pay_balance_button_click()
{
    window_pay_balance = new Gtk::Window();
    window_pay_balance->set_title("Pay Balance");

    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    window_pay_balance->add(*vbox);

    Gtk::Box *hbox_top = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
    vbox->add(*hbox_top);

    Gtk::Grid *grid1 = Gtk::manage(new Gtk::Grid);
    grid1->set_border_width(10);
    hbox_top->add(*grid1);

    Gtk::Label *label = Gtk::manage(new Gtk::Label("Please input the id number of the customer you would like to pay balance: "));
    grid1->attach(*label, 0, 0, 1, 1);

    entry_id = Gtk::manage(new Gtk::Entry());
    entry_id->set_text("");
    entry_id->set_max_length(50);
    grid1->attach(*entry_id, 0, 1, 1, 1);

    Gtk::Box *hbox_bottom = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
    vbox->add(*hbox_bottom);

    Gtk::Grid *grid2 = Gtk::manage(new Gtk::Grid);
    grid2->set_border_width(10);
    hbox_bottom->add(*grid2);
    
    Gtk::Button *button_cancel = Gtk::manage(new Gtk::Button("Cancel"));
    button_cancel->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_pay_balance_cancel_button_click));
    grid2->attach(*button_cancel, 0, 2, 1, 1);
    
    Gtk::Button *button_ok = Gtk::manage(new Gtk::Button("OK"));
    button_ok->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_pay_balance_ok_button_click));
    grid2->attach(*button_ok, 1, 2, 1, 1);

    window_pay_balance->show_all();
}
void Dialog::on_pay_balance_ok_button_click()
{
    string id_str = entry_id->get_text();
    stringstream id_geek(id_str);
    int id;
    id_geek >> id;
    bool found = false;
    for(Customer* it : library.get_customers())
    {
        double balance = it->get_balance();
        if(id == it->get_id())
        {
            found = true;
            if(it->get_balance() > 0)
            {
                it->pay_balance();
                string out;
                ostringstream ost;
                ost << it->get_name() << " paid a balance of $" << fixed << setprecision(2) << balance << ".";
                out = ost.str();
                dialog(out);
                window_pay_balance->close();
                break;
            }
            else
            {
                string out;
                ostringstream ost;
                ost << it->get_name() << " has a balance of $" << fixed << setprecision(2) << balance << ". " << it->get_name() << " doesn't have to pay anything.";
                out = ost.str();
                dialog(out);
                window_pay_balance->close();
                break;
            }
        }
    }
    if(!found)
        dialog("Customer with ID " + id_str + " is not found.");
    delete(window_pay_balance);
}
void Dialog::on_pay_balance_cancel_button_click()
{
    window_pay_balance->close();
    delete(window_pay_balance);
}

// *Save*
void Dialog::on_save_button_click()
{
    window_save = new Gtk::Window();
    window_save->set_title("Save");

    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    window_save->add(*vbox);
    
    Gtk::Grid *grid1 = Gtk::manage(new Gtk::Grid);
    grid1->set_border_width(10);
    vbox->add(*grid1);
    
    Gtk::Label *label = Gtk::manage(new Gtk::Label("Please input a name you would like to save the file as.\n(Leave blank for default file name save.)"));
    grid1->attach(*label, 0, 0, 1, 1);

    entry_save_name = Gtk::manage(new Gtk::Entry());
    entry_save_name->set_text("");
    entry_save_name->set_max_length(50);
    grid1->attach(*entry_save_name, 0, 1, 1, 1);
    
    Gtk::Grid *grid2 = Gtk::manage(new Gtk::Grid);
    grid2->set_border_width(10);
    vbox->add(*grid2);
    
    Gtk::Button *button_cancel = Gtk::manage(new Gtk::Button("Cancel"));
    button_cancel->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_save_cancel_button_click));
    grid2->attach(*button_cancel, 0, 0, 1, 1);
    
    Gtk::Button *button_ok = Gtk::manage(new Gtk::Button("OK"));
    button_ok->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_save_ok_button_click));
    grid2->attach(*button_ok, 1, 0, 1, 1);
    
    window_save->show_all();
}
void Dialog::on_save_ok_button_click()
{
    string file_name = entry_save_name->get_text();
    if(file_name == "")
    {
        file_name = "and7697_default.txt";
    }
    ofstream my_file(file_name);
    if(my_file.is_open())
    {
        if(my_file << library)
            dialog("Saved successfully as " + file_name);
        else
            dialog("ERROR: Unable to save file.");
    }
    else
        dialog("ERROR: Unable to open file.");
    window_save->close();
    delete(window_save);
}
void Dialog::on_save_cancel_button_click()
{
    window_save->close();
    delete(window_save);
}

// *Load*
void Dialog::on_load_button_click()
{
    window_load = new Gtk::Window();
    window_load->set_title("Load");

    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    window_load->add(*vbox);
    
    Gtk::Grid *grid1 = Gtk::manage(new Gtk::Grid);
    grid1->set_border_width(10);
    vbox->add(*grid1);
    
    Gtk::Label *label = Gtk::manage(new Gtk::Label("Please input a name you would like to load the file as.\n(Leave blank for default file name load.)"));
    grid1->attach(*label, 0, 0, 1, 1);

    entry_load_name = Gtk::manage(new Gtk::Entry());
    entry_load_name->set_text("");
    entry_load_name->set_max_length(50);
    grid1->attach(*entry_load_name, 0, 1, 1, 1);
    
    Gtk::Grid *grid2 = Gtk::manage(new Gtk::Grid);
    grid2->set_border_width(10);
    vbox->add(*grid2);
    
    Gtk::Button *button_cancel = Gtk::manage(new Gtk::Button("Cancel"));
    button_cancel->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_load_cancel_button_click));
    grid2->attach(*button_cancel, 0, 0, 1, 1);
    
    Gtk::Button *button_ok = Gtk::manage(new Gtk::Button("OK"));
    button_ok->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_load_ok_button_click));
    grid2->attach(*button_ok, 1, 0, 1, 1);
    
    window_load->show_all();
}
void Dialog::on_load_ok_button_click()
{
    string file_name = entry_load_name->get_text();
    if(file_name == "")
    {
        file_name = "and7697_default.txt";
    }
    ifstream my_file(file_name);
    if(my_file.is_open())
    {
        if(my_file >> library)
            dialog("Loaded successfully from " + file_name);
        else
            dialog("ERROR: Unable to load file.");
    }
    else
        dialog("ERROR: Unable to open file.");
    window_load->close();
    delete(window_load);
}
void Dialog::on_load_cancel_button_click()
{
    window_load->close();
    delete(window_load);
}

void Dialog::on_exit_click()
{
    dialog("Thank You!");
    hide();
}


void Dialog::dialog(Glib::ustring msg)
{
    Gtk::MessageDialog dlg(msg, false, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, true);
    dlg.set_title("Librarian Management System");
    dlg.run();
}

/*
***For Add***
*/

// *Add Transaction*
void Dialog::on_add_transaction_button_click()
{
    window_add_transaction = new Gtk::Window();
    window_add_transaction->set_title("Add Transaction");

    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    window_add_transaction->add(*vbox);

    Gtk::Box *hbox_top = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
    vbox->add(*hbox_top);

    Gtk::Grid *grid1 = Gtk::manage(new Gtk::Grid);
    grid1->set_border_width(10);
    hbox_top->add(*grid1);

    // ***For Transaction Number***

    Gtk::Label *transaction_number = Gtk::manage(new Gtk::Label("Transaction Number:"));
    grid1->attach(*transaction_number, 0, 0, 1, 1);
    
    entry_transaction_number = Gtk::manage(new Gtk::Entry());
    entry_transaction_number->set_text("");
    entry_transaction_number->set_max_length(50);
    grid1->attach(*entry_transaction_number, 1, 0, 3, 1);

    // ***For Check Out Date***

    Gtk::Label *label_check_out_date = Gtk::manage(new Gtk::Label("Check Out Date: (MM DD YYYY)"));
    grid1->attach(*label_check_out_date, 0, 1, 1, 1);
    
    // For Month
    entry_check_out_month = Gtk::manage(new Gtk::Entry());
    entry_check_out_month->set_text("");
    entry_check_out_month->set_max_length(2);
    entry_check_out_month->set_width_chars(2);
    entry_check_out_month->set_max_width_chars(2);
    grid1->attach(*entry_check_out_month, 1, 1, 1, 1);
    
    // For Day
    entry_check_out_day = Gtk::manage(new Gtk::Entry());
    entry_check_out_day->set_text("");
    entry_check_out_day->set_max_length(2);
    entry_check_out_day->set_width_chars(2);
    entry_check_out_day->set_max_width_chars(2);
    grid1->attach(*entry_check_out_day, 2, 1, 1, 1);
    
    // For Year
    entry_check_out_year = Gtk::manage(new Gtk::Entry());
    entry_check_out_year->set_text("");
    entry_check_out_year->set_max_length(4);
    entry_check_out_year->set_width_chars(4);
    entry_check_out_year->set_max_width_chars(4);
    grid1->attach(*entry_check_out_year, 3, 1, 1, 1);

    // ***For Librarian***

    Gtk::Label *label_librarian = Gtk::manage(new Gtk::Label("Librarian ID:"));
    grid1->attach(*label_librarian, 0, 2, 1, 1);
    
    entry_librarian = Gtk::manage(new Gtk::Entry());
    entry_librarian->set_text("");
    entry_librarian->set_max_length(50);
    grid1->attach(*entry_librarian, 1, 2, 3, 1);

    // ***For Customer***

    Gtk::Label *label_customer = Gtk::manage(new Gtk::Label("Customer ID:"));
    grid1->attach(*label_customer, 0, 3, 1, 1);
    
    entry_customer = Gtk::manage(new Gtk::Entry());
    entry_customer->set_text("");
    entry_customer->set_max_length(50);
    grid1->attach(*entry_customer, 1, 3, 3, 1);

    // ***For Medias***

    Gtk::Label *label_medias = Gtk::manage(new Gtk::Label("Media(s):"));
    grid1->attach(*label_medias, 0, 4, 1, 1);
    
    entry_media = Gtk::manage(new Gtk::Entry());
    entry_media->set_text("");
    entry_media->set_max_length(50);
    grid1->attach(*entry_media, 1, 4, 3, 1);
    
    Gtk::Button *button_add_media = Gtk::manage(new Gtk::Button("Add Media"));
    button_add_media->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_add_media_by_id_button_click));
    grid1->attach(*button_add_media, 5, 4, 1, 1);

    // ***For Bundles***

    Gtk::Label *label_bundles = Gtk::manage(new Gtk::Label("Bundle(s):"));
    grid1->attach(*label_bundles, 0, 5, 1, 1);
    
    entry_bundle = Gtk::manage(new Gtk::Entry());
    entry_bundle->set_text("");
    entry_bundle->set_max_length(50);
    grid1->attach(*entry_bundle, 1, 5, 3, 1);
    
    Gtk::Button *button_add_bundle = Gtk::manage(new Gtk::Button("Add Bundle"));
    button_add_bundle->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_add_bundle_by_name_button_click));
    grid1->attach(*button_add_bundle, 5, 5, 1, 1);

    // ***For Check In Date***

    Gtk::Label *label_check_in_date = Gtk::manage(new Gtk::Label("Check In Date: (MM DD YYYY)"));
    grid1->attach(*label_check_in_date, 0, 6, 1, 1);
    
    // For Month
    entry_check_in_month = Gtk::manage(new Gtk::Entry());
    entry_check_in_month->set_text("");
    entry_check_in_month->set_max_length(2);
    entry_check_in_month->set_width_chars(2);
    entry_check_in_month->set_max_width_chars(2);
    grid1->attach(*entry_check_in_month, 1, 6, 1, 1);
    
    // For Day
    entry_check_in_day = Gtk::manage(new Gtk::Entry());
    entry_check_in_day->set_text("");
    entry_check_in_day->set_max_length(2);
    entry_check_in_day->set_width_chars(2);
    entry_check_in_day->set_max_width_chars(2);
    grid1->attach(*entry_check_in_day, 2, 6, 1, 1);
    
    // For Year
    entry_check_in_year = Gtk::manage(new Gtk::Entry());
    entry_check_in_year->set_text("");
    entry_check_in_year->set_max_length(4);
    entry_check_in_year->set_width_chars(4);
    entry_check_in_year->set_max_width_chars(4);
    grid1->attach(*entry_check_in_year, 3, 6, 1, 1);

    // ***For Due Date***

    Gtk::Label *label_due_date = Gtk::manage(new Gtk::Label("Due Date: (MM DD YYYY)"));
    grid1->attach(*label_due_date, 0, 7, 1, 1);
    
    // For Month
    entry_due_month = Gtk::manage(new Gtk::Entry());
    entry_due_month->set_text("");
    entry_due_month->set_max_length(2);
    entry_due_month->set_width_chars(2);
    entry_due_month->set_max_width_chars(2);
    grid1->attach(*entry_due_month, 1, 7, 1, 1);
    
    // For Day
    entry_due_day = Gtk::manage(new Gtk::Entry());
    entry_due_day->set_text("");
    entry_due_day->set_max_length(2);
    entry_due_day->set_width_chars(2);
    entry_due_day->set_max_width_chars(2);
    grid1->attach(*entry_due_day, 2, 7, 1, 1);
    
    // For Year
    entry_due_year = Gtk::manage(new Gtk::Entry());
    entry_due_year->set_text("");
    entry_due_year->set_max_length(4);
    entry_due_year->set_width_chars(4);
    entry_due_year->set_max_width_chars(4);
    grid1->attach(*entry_due_year, 3, 7, 1, 1);

    Gtk::Box *hbox_bottom = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
    vbox->add(*hbox_bottom);

    Gtk::Grid *grid2 = Gtk::manage(new Gtk::Grid);
    grid2->set_border_width(10);
    hbox_bottom->add(*grid2);
    
    Gtk::Button *button_cancel = Gtk::manage(new Gtk::Button("Cancel"));
    button_cancel->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_add_transaction_cancel_button_click));
    grid2->attach(*button_cancel, 0, 0, 1, 1);
    
    Gtk::Button *button_ok = Gtk::manage(new Gtk::Button("OK"));
    button_ok->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_add_transaction_ok_button_click));
    grid2->attach(*button_ok, 1, 0, 1, 1);
   
    window_add_transaction->show_all();
}
void Dialog::on_add_transaction_ok_button_click()
{
    // *Transaction Number*
    string transaction_number_str = entry_transaction_number->get_text();
    stringstream transaction_number_geek(transaction_number_str);
    int transaction_number;
    transaction_number_geek >> transaction_number;
    int month, day, year;
    // *Check Out Date*
    // Month
    string check_out_month_str = entry_check_out_month->get_text();
    stringstream check_out_month_geek(check_out_month_str);
    check_out_month_geek >> month;
    // Day
    string check_out_day_str = entry_check_out_day->get_text();
    stringstream check_out_day_geek(check_out_day_str);
    check_out_day_geek >> day;
    // Year
    string check_out_year_str = entry_check_out_year->get_text();
    stringstream check_out_year_geek(check_out_year_str);
    check_out_year_geek >> year;
    Date *check_out_date = new Date(year, month, day);
    // *Librarian*
    Librarian *librarian;
    string librarian_str = entry_librarian->get_text();
    stringstream librarian_geek(librarian_str);
    int librarian_id;
    librarian_geek >> librarian_id;
    for(Librarian* it : library.get_librarians())
        if(librarian_id == it->get_id())
        {
            librarian = it;
            break;
        }
    // *Customer*
    Customer *customer;
    string customer_str = entry_customer->get_text();
    stringstream customer_geek(customer_str);
    int customer_id;
    customer_geek >> customer_id;
    for(Customer* it : library.get_customers())
        if(customer_id == it->get_id())
        {
            customer = it;
            break;
        }
    // *Check In Date*
    // Month
    string check_in_month_str = entry_check_in_month->get_text();
    stringstream check_in_month_geek(check_in_month_str);
    check_in_month_geek >> month;
    // Day
    string check_in_day_str = entry_check_in_day->get_text();
    stringstream check_in_day_geek(check_in_day_str);
    check_in_day_geek >> day;
    // Year
    string check_in_year_str = entry_check_in_year->get_text();
    stringstream check_in_year_geek(check_in_year_str);
    check_in_year_geek >> year;
    Date *check_in_date = new Date(year, month, day);
    // *Due Date*
    // Month
    string due_month_str = entry_due_month->get_text();
    stringstream due_month_geek(due_month_str);
    due_month_geek >> month;
    // Day
    string due_day_str = entry_due_day->get_text();
    stringstream due_day_geek(due_day_str);
    due_day_geek >> day;
    // Year
    string due_year_str = entry_due_year->get_text();
    stringstream due_year_geek(due_year_str);
    due_year_geek >> year;
    Date *due_date = new Date(year, month, day);
    Transaction *transaction = new Transaction(transaction_number, *check_out_date, *librarian, *customer, medias, bundles, *check_in_date, *due_date);
    library.create_new_transaction(transaction);
    dialog("Transaction " + transaction_number_str + " added.");
    medias.clear();
    bundles.clear();
    window_add_transaction->close();
    delete(window_add_transaction);
}
void Dialog::on_add_transaction_cancel_button_click()
{
    window_add_transaction->close();
    delete(window_add_transaction);
}
void Dialog::on_add_media_by_id_button_click()
{
    string id_number_str = entry_media->get_text();
    stringstream id_number_geek(id_number_str);
    int id_number;
    id_number_geek >> id_number;
    for(Media* it : library.get_medias())
        if(id_number == it->get_id_number())
        {
            medias.push_back(it);
            dialog("\"" + it->get_title() + "\" added.");
            break;
        }
    entry_media->set_text("");
}
void Dialog::on_add_bundle_by_name_button_click()
{
    string name = entry_bundle->get_text();
    for(Bundle* it : library.get_bundles())
        if(to_lower_case(name) == to_lower_case(it->get_name()))
        {
            bundles.push_back(it);
            dialog(it->get_name() + " Bundle added.");
            break;
        }
    entry_bundle->set_text("");
}

// *Add Customer*
void Dialog::on_add_customer_button_click()
{
    window_add_customer = new Gtk::Window();
    window_add_customer->set_title("Add Customer");

    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    window_add_customer->add(*vbox);

    Gtk::Box *hbox_top = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
    vbox->add(*hbox_top);

    Gtk::Grid *grid1 = Gtk::manage(new Gtk::Grid);
    grid1->set_border_width(10);
    hbox_top->add(*grid1);

    // ***For Name***

    Gtk::Label *label_name = Gtk::manage(new Gtk::Label("Name:"));
    grid1->attach(*label_name, 0, 0, 1, 1);
    
    entry_name = Gtk::manage(new Gtk::Entry());
    entry_name->set_text("");
    entry_name->set_max_length(50);
    grid1->attach(*entry_name, 1, 0, 1, 1);

    // ***For ID***

    Gtk::Label *label_id = Gtk::manage(new Gtk::Label("ID:"));
    grid1->attach(*label_id, 0, 1, 1, 1);
    
    entry_id = Gtk::manage(new Gtk::Entry());
    entry_id->set_text("");
    entry_id->set_max_length(50);
    grid1->attach(*entry_id, 1, 1, 1, 1);

    // ***For Phone***

    Gtk::Label *label_phone = Gtk::manage(new Gtk::Label("Phone:"));
    grid1->attach(*label_phone, 0, 2, 1, 1);
    
    entry_phone = Gtk::manage(new Gtk::Entry());
    entry_phone->set_text("");
    entry_phone->set_max_length(50);
    grid1->attach(*entry_phone, 1, 2, 1, 1);

    // ***For Email***

    Gtk::Label *label_email = Gtk::manage(new Gtk::Label("Email:"));
    grid1->attach(*label_email, 0, 3, 1, 1);
    
    entry_email = Gtk::manage(new Gtk::Entry());
    entry_email->set_text("");
    entry_email->set_max_length(50);
    grid1->attach(*entry_email, 1, 3, 1, 1);

    // ***For Balance***

    Gtk::Label *label_balance = Gtk::manage(new Gtk::Label("Balance:"));
    grid1->attach(*label_balance, 0, 4, 1, 1);
    
    entry_balance = Gtk::manage(new Gtk::Entry());
    entry_balance->set_text("");
    entry_balance->set_max_length(50);
    grid1->attach(*entry_balance, 1, 4, 1, 1);

    Gtk::Box *hbox_bottom = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
    vbox->add(*hbox_bottom);

    Gtk::Grid *grid2 = Gtk::manage(new Gtk::Grid);
    grid2->set_border_width(10);
    hbox_bottom->add(*grid2);
    
    Gtk::Button *button_cancel = Gtk::manage(new Gtk::Button("Cancel"));
    button_cancel->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_add_customer_cancel_button_click));
    grid2->attach(*button_cancel, 0, 0, 1, 1);
    
    Gtk::Button *button_ok = Gtk::manage(new Gtk::Button("OK"));
    button_ok->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_add_customer_ok_button_click));
    grid2->attach(*button_ok, 1, 0, 1, 1);
   
    window_add_customer->show_all();
}
void Dialog::on_add_customer_ok_button_click()
{
    string name = entry_name->get_text();
    string id_str = entry_id->get_text();
    stringstream id_geek(id_str);
    int id;
    id_geek >> id;
    string phone_str = entry_phone->get_text();
    stringstream phone_geek(phone_str);
    int phone;
    phone_geek >> phone;
    string email = entry_email->get_text();
    string balance_str = entry_balance->get_text();
    stringstream balance_geek(balance_str);
    double balance;
    balance_geek >> balance;
    Customer* customer = new Customer(name, id, phone, email, balance);
    library.create_new_customer(customer);
    window_add_customer->close();
    dialog(name + " added.");
    delete(window_add_customer);
}
void Dialog::on_add_customer_cancel_button_click()
{
    window_add_customer->close();
    delete(window_add_customer);
}

// *Add Librarian*
void Dialog::on_add_librarian_button_click()
{
    window_add_librarian = new Gtk::Window();
    window_add_librarian->set_title("Add Librarian");

    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    window_add_librarian->add(*vbox);

    Gtk::Box *hbox_top = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
    vbox->add(*hbox_top);

    Gtk::Grid *grid1 = Gtk::manage(new Gtk::Grid);
    grid1->set_border_width(10);
    hbox_top->add(*grid1);

    // ***For Name***

    Gtk::Label *label_name = Gtk::manage(new Gtk::Label("Name:"));
    grid1->attach(*label_name, 0, 0, 1, 1);
    
    entry_name = Gtk::manage(new Gtk::Entry());
    entry_name->set_text("");
    entry_name->set_max_length(50);
    grid1->attach(*entry_name, 1, 0, 1, 1);

    // ***For ID***

    Gtk::Label *label_id = Gtk::manage(new Gtk::Label("ID:"));
    grid1->attach(*label_id, 0, 1, 1, 1);
    
    entry_id = Gtk::manage(new Gtk::Entry());
    entry_id->set_text("");
    entry_id->set_max_length(50);
    grid1->attach(*entry_id, 1, 1, 1, 1);

    Gtk::Box *hbox_bottom = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
    vbox->add(*hbox_bottom);

    Gtk::Grid *grid2 = Gtk::manage(new Gtk::Grid);
    grid2->set_border_width(10);
    hbox_bottom->add(*grid2);
    
    Gtk::Button *button_cancel = Gtk::manage(new Gtk::Button("Cancel"));
    button_cancel->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_add_librarian_cancel_button_click));
    grid2->attach(*button_cancel, 0, 0, 1, 1);
    
    Gtk::Button *button_ok = Gtk::manage(new Gtk::Button("OK"));
    button_ok->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_add_librarian_ok_button_click));
    grid2->attach(*button_ok, 1, 0, 1, 1);
   
    window_add_librarian->show_all();
}
void Dialog::on_add_librarian_ok_button_click()
{
    string name = entry_name->get_text();
    string id_str = entry_id->get_text();
    stringstream id_geek(id_str);
    int id;
    id_geek >> id;
    Librarian* librarian = new Librarian(name, id);
    library.create_new_librarian(librarian);
    window_add_librarian->close();
    dialog(name + " added.");
    delete(window_add_librarian);
}
void Dialog::on_add_librarian_cancel_button_click()
{
    window_add_librarian->close();
    delete(window_add_librarian);
}

// *Add Bundle*
void Dialog::on_add_bundle_button_click()
{
    window_add_bundle = new Gtk::Window();
    window_add_bundle->set_title("Add Bundle");

    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    window_add_bundle->add(*vbox);

    Gtk::Box *hbox1 = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
    vbox->add(*hbox1);

    Gtk::Grid *grid1 = Gtk::manage(new Gtk::Grid);
    grid1->set_border_width(10);
    hbox1->add(*grid1);

    Gtk::Label *label_name = Gtk::manage(new Gtk::Label("Name: "));
    grid1->attach(*label_name, 0, 0, 1, 1);

    entry_name = Gtk::manage(new Gtk::Entry());
    entry_name->set_text("");
    entry_name->set_max_length(50);
    grid1->attach(*entry_name, 1, 0, 1, 1);

    Gtk::Box *hbox2 = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
    vbox->add(*hbox2);

    Gtk::Grid *grid2 = Gtk::manage(new Gtk::Grid);
    grid2->set_border_width(10);
    hbox2->add(*grid2);

    Gtk::Label *label_id_number = Gtk::manage(new Gtk::Label("Please input the id number of the media you would like to add to the Bundle: "));
    grid2->attach(*label_id_number, 0, 0, 2, 1);

    entry_id_number = Gtk::manage(new Gtk::Entry());
    entry_id_number->set_text("");
    entry_id_number->set_max_length(50);
    grid2->attach(*entry_id_number, 0, 1, 1, 1);

    Gtk::Button *button_add_to_bundle = Gtk::manage(new Gtk::Button("Add to Bundle"));
    button_add_to_bundle->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_add_to_bundle_button_click));
    grid2->attach(*button_add_to_bundle, 1, 1, 1, 1);

    Gtk::Box *hbox3 = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
    vbox->add(*hbox3);

    Gtk::Grid *grid3 = Gtk::manage(new Gtk::Grid);
    grid3->set_border_width(10);
    hbox3->add(*grid3);
    
    Gtk::Button *button_cancel = Gtk::manage(new Gtk::Button("Cancel"));
    button_cancel->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_add_bundle_cancel_button_click));
    grid3->attach(*button_cancel, 0, 2, 1, 1);
    
    Gtk::Button *button_ok = Gtk::manage(new Gtk::Button("OK"));
    button_ok->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_add_bundle_ok_button_click));
    grid3->attach(*button_ok, 1, 2, 1, 1);

    window_add_bundle->show_all();
}
void Dialog::on_add_bundle_ok_button_click()
{
    string name = entry_name->get_text();
    Bundle* bundle = new Bundle(name, medias);
    library.create_new_bundle(bundle);
    dialog(name + " Bundle added.");
    medias.clear();
    window_add_bundle->close();
    delete(window_add_bundle);
}
void Dialog::on_add_bundle_cancel_button_click()
{
    window_add_bundle->close();
    delete(window_add_bundle);
}
void Dialog::on_add_to_bundle_button_click()
{
    string id_number_str = entry_id_number->get_text();
    stringstream id_number_geek(id_number_str);
    int id_number;
    id_number_geek >> id_number;
    bool found = false;
    for(Media* it : library.get_medias())
    {
        if(id_number == it->get_id_number())
        {
            // Media media_temp = *it;
            found = true;
            medias.push_back(it);
            entry_id_number->set_text("");
            dialog("\"" + it->get_title() + "\" added to " + entry_name->get_text() + " Bundle.");
            break;
        }
    }
    if(!found)
        dialog("Media with ID Number " + id_number_str + " not found.");
}

/*
***For Add Media***
*/

// *Add Book*
void Dialog::on_add_book_button_click()
{
    window_add_book = new Gtk::Window();
    window_add_book->set_title("Add Book");

    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    window_add_book->add(*vbox);

    Gtk::Box *hbox_top = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
    vbox->add(*hbox_top);

    Gtk::Grid *grid1 = Gtk::manage(new Gtk::Grid);
    grid1->set_border_width(10);
    hbox_top->add(*grid1);

    // ***For ID Number***

    Gtk::Label *label_id_number = Gtk::manage(new Gtk::Label("ID Number:"));
    grid1->attach(*label_id_number, 0, 0, 1, 1);
    
    entry_id_number = Gtk::manage(new Gtk::Entry());
    entry_id_number->set_text("");
    entry_id_number->set_max_length(50);
    grid1->attach(*entry_id_number, 1, 0, 1, 1);

    // ***For Call Number***

    Gtk::Label *label_call_number = Gtk::manage(new Gtk::Label("Call Number:"));
    grid1->attach(*label_call_number, 0, 1, 1, 1);
    
    entry_call_number = Gtk::manage(new Gtk::Entry());
    entry_call_number->set_text("");
    entry_call_number->set_max_length(50);
    grid1->attach(*entry_call_number, 1, 1, 1, 1);

    // ***For Title***

    Gtk::Label *label_title = Gtk::manage(new Gtk::Label("Title:"));
    grid1->attach(*label_title, 0, 2, 1, 1);
    
    entry_title = Gtk::manage(new Gtk::Entry());
    entry_title->set_text("");
    entry_title->set_max_length(50);
    grid1->attach(*entry_title, 1, 2, 1, 1);

    // ***For Genre***

    Gtk::Label *label_genre = Gtk::manage(new Gtk::Label("Genre:"));
    grid1->attach(*label_genre, 0, 3, 1, 1);
    
    entry_genre = Gtk::manage(new Gtk::Entry());
    entry_genre->set_text("");
    entry_genre->set_max_length(50);
    grid1->attach(*entry_genre, 1, 3, 1, 1);

    // ***For Author***

    Gtk::Label *label_author = Gtk::manage(new Gtk::Label("Author:"));
    grid1->attach(*label_author, 0, 4, 1, 1);
    
    entry_author = Gtk::manage(new Gtk::Entry());
    entry_author->set_text("");
    entry_author->set_max_length(50);
    grid1->attach(*entry_author, 1, 4, 1, 1);

    // ***For Copyright Year***

    Gtk::Label *label_copyright_year = Gtk::manage(new Gtk::Label("Copyright Year:"));
    grid1->attach(*label_copyright_year, 0, 5, 1, 1);
    
    entry_copyright_year = Gtk::manage(new Gtk::Entry());
    entry_copyright_year->set_text("");
    entry_copyright_year->set_max_length(50);
    grid1->attach(*entry_copyright_year, 1, 5, 1, 1);

    Gtk::Box *hbox_bottom = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
    vbox->add(*hbox_bottom);

    Gtk::Grid *grid2 = Gtk::manage(new Gtk::Grid);
    grid2->set_border_width(10);
    hbox_bottom->add(*grid2);
    
    Gtk::Button *button_cancel = Gtk::manage(new Gtk::Button("Cancel"));
    button_cancel->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_add_book_cancel_button_click));
    grid2->attach(*button_cancel, 0, 0, 1, 1);
    
    Gtk::Button *button_ok = Gtk::manage(new Gtk::Button("OK"));
    button_ok->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_add_book_ok_button_click));
    grid2->attach(*button_ok, 1, 0, 1, 1);
   
    window_add_book->show_all();
}
void Dialog::on_add_book_ok_button_click()
{
    string id_number_str = entry_id_number->get_text();
    stringstream id_number_geek(id_number_str);
    int id_number;
    id_number_geek >> id_number;
    string call_number = entry_call_number->get_text();
    string title = entry_title->get_text();
    string genre = entry_genre->get_text();
    string author = entry_author->get_text();
    string copyright_year_str = entry_copyright_year->get_text();
    stringstream copyright_year_geek(copyright_year_str);
    int copyright_year;
    copyright_year_geek >> copyright_year;
    Book* book = new Book(id_number, call_number, title, genre, author, copyright_year);
    library.create_new_media(book);
    window_add_book->close();
    dialog("\"" + title + "\" added.");
    delete(window_add_book);
}
void Dialog::on_add_book_cancel_button_click()
{
    window_add_book->close();
    delete(window_add_book);
}

// *Add Movie*
void Dialog::on_add_movie_button_click()
{
    window_add_movie = new Gtk::Window();
    window_add_movie->set_title("Add Movie");

    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    window_add_movie->add(*vbox);

    Gtk::Box *hbox_top = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
    vbox->add(*hbox_top);

    Gtk::Grid *grid1 = Gtk::manage(new Gtk::Grid);
    grid1->set_border_width(10);
    hbox_top->add(*grid1);

    // ***For ID Number***

    Gtk::Label *label_id_number = Gtk::manage(new Gtk::Label("ID Number:"));
    grid1->attach(*label_id_number, 0, 0, 1, 1);
    
    entry_id_number = Gtk::manage(new Gtk::Entry());
    entry_id_number->set_text("");
    entry_id_number->set_max_length(50);
    grid1->attach(*entry_id_number, 1, 0, 1, 1);

    // ***For Call Number***

    Gtk::Label *label_call_number = Gtk::manage(new Gtk::Label("Call Number:"));
    grid1->attach(*label_call_number, 0, 1, 1, 1);
    
    entry_call_number = Gtk::manage(new Gtk::Entry());
    entry_call_number->set_text("");
    entry_call_number->set_max_length(50);
    grid1->attach(*entry_call_number, 1, 1, 1, 1);

    // ***For Title***

    Gtk::Label *label_title = Gtk::manage(new Gtk::Label("Title:"));
    grid1->attach(*label_title, 0, 2, 1, 1);
    
    entry_title = Gtk::manage(new Gtk::Entry());
    entry_title->set_text("");
    entry_title->set_max_length(50);
    grid1->attach(*entry_title, 1, 2, 1, 1);

    // ***For Genre***

    Gtk::Label *label_genre = Gtk::manage(new Gtk::Label("Genre:"));
    grid1->attach(*label_genre, 0, 3, 1, 1);
    
    entry_genre = Gtk::manage(new Gtk::Entry());
    entry_genre->set_text("");
    entry_genre->set_max_length(50);
    grid1->attach(*entry_genre, 1, 3, 1, 1);

    // ***For Release Year***

    Gtk::Label *label_release_year = Gtk::manage(new Gtk::Label("Release Year:"));
    grid1->attach(*label_release_year, 0, 4, 1, 1);
    
    entry_release_year = Gtk::manage(new Gtk::Entry());
    entry_release_year->set_text("");
    entry_release_year->set_max_length(50);
    grid1->attach(*entry_release_year, 1, 4, 1, 1);

    // ***For Producer***

    Gtk::Label *label_producer = Gtk::manage(new Gtk::Label("Producer:"));
    grid1->attach(*label_producer, 0, 5, 1, 1);
    
    entry_producer = Gtk::manage(new Gtk::Entry());
    entry_producer->set_text("");
    entry_producer->set_max_length(50);
    grid1->attach(*entry_producer, 1, 5, 1, 1);

    // ***For Director***

    Gtk::Label *label_director = Gtk::manage(new Gtk::Label("Director:"));
    grid1->attach(*label_director, 0, 6, 1, 1);
    
    entry_director = Gtk::manage(new Gtk::Entry());
    entry_director->set_text("");
    entry_director->set_max_length(50);
    grid1->attach(*entry_director, 1, 6, 1, 1);

    // ***For Leading Actors***

    Gtk::Label *label_leading_actors = Gtk::manage(new Gtk::Label("Leading Actor(s):"));
    grid1->attach(*label_leading_actors, 0, 7, 1, 1);
    
    entry_leading_actor = Gtk::manage(new Gtk::Entry());
    entry_leading_actor->set_text("");
    entry_leading_actor->set_max_length(50);
    grid1->attach(*entry_leading_actor, 1, 7, 1, 1);
    
    Gtk::Button *button_add_leading_actor = Gtk::manage(new Gtk::Button("Add Leading Actor"));
    button_add_leading_actor->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_add_leading_actor_button_click));
    grid1->attach(*button_add_leading_actor, 2, 7, 1, 1);

    Gtk::Box *hbox_bottom = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
    vbox->add(*hbox_bottom);

    Gtk::Grid *grid2 = Gtk::manage(new Gtk::Grid);
    grid2->set_border_width(10);
    hbox_bottom->add(*grid2);
    
    Gtk::Button *button_cancel = Gtk::manage(new Gtk::Button("Cancel"));
    button_cancel->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_add_movie_cancel_button_click));
    grid2->attach(*button_cancel, 0, 0, 1, 1);
    
    Gtk::Button *button_ok = Gtk::manage(new Gtk::Button("OK"));
    button_ok->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_add_movie_ok_button_click));
    grid2->attach(*button_ok, 1, 0, 1, 1);
   
    window_add_movie->show_all();
}
void Dialog::on_add_movie_ok_button_click()
{
    string id_number_str = entry_id_number->get_text();
    stringstream id_number_geek(id_number_str);
    int id_number;
    id_number_geek >> id_number;
    string call_number = entry_call_number->get_text();
    string title = entry_title->get_text();
    string genre = entry_genre->get_text();
    string release_year_str = entry_release_year->get_text();
    stringstream release_year_geek(release_year_str);
    int release_year;
    release_year_geek >> release_year;
    string producer = entry_producer->get_text();
    string director = entry_director->get_text();
    Movie* movie = new Movie(id_number, call_number, title, genre, release_year, producer, director, leading_actors);
    library.create_new_media(movie);
    dialog("\"" + title + "\" added.");
    leading_actors.clear();
    window_add_movie->close();
    delete(window_add_movie);
}
void Dialog::on_add_movie_cancel_button_click()
{
    window_add_movie->close();
    delete(window_add_movie);
}
void Dialog::on_add_leading_actor_button_click()
{
    string leading_actor = entry_leading_actor->get_text();
    leading_actors.push_back(leading_actor);
    entry_leading_actor->set_text("");
    dialog(leading_actor + " added.");
}

// *Add Video Game*
void Dialog::on_add_video_game_button_click()
{
    window_add_video_game = new Gtk::Window();
    window_add_video_game->set_title("Add Video Game");

    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    window_add_video_game->add(*vbox);

    Gtk::Box *hbox_top = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
    vbox->add(*hbox_top);

    Gtk::Grid *grid1 = Gtk::manage(new Gtk::Grid);
    grid1->set_border_width(10);
    hbox_top->add(*grid1);

    // ***For ID Number***

    Gtk::Label *label_id_number = Gtk::manage(new Gtk::Label("ID Number:"));
    grid1->attach(*label_id_number, 0, 0, 1, 1);
    
    entry_id_number = Gtk::manage(new Gtk::Entry());
    entry_id_number->set_text("");
    entry_id_number->set_max_length(50);
    grid1->attach(*entry_id_number, 1, 0, 1, 1);

    // ***For Call Number***

    Gtk::Label *label_call_number = Gtk::manage(new Gtk::Label("Call Number:"));
    grid1->attach(*label_call_number, 0, 1, 1, 1);
    
    entry_call_number = Gtk::manage(new Gtk::Entry());
    entry_call_number->set_text("");
    entry_call_number->set_max_length(50);
    grid1->attach(*entry_call_number, 1, 1, 1, 1);

    // ***For Title***

    Gtk::Label *label_title = Gtk::manage(new Gtk::Label("Title:"));
    grid1->attach(*label_title, 0, 2, 1, 1);
    
    entry_title = Gtk::manage(new Gtk::Entry());
    entry_title->set_text("");
    entry_title->set_max_length(50);
    grid1->attach(*entry_title, 1, 2, 1, 1);

    // ***For Genre***

    Gtk::Label *label_genre = Gtk::manage(new Gtk::Label("Genre:"));
    grid1->attach(*label_genre, 0, 3, 1, 1);
    
    entry_genre = Gtk::manage(new Gtk::Entry());
    entry_genre->set_text("");
    entry_genre->set_max_length(50);
    grid1->attach(*entry_genre, 1, 3, 1, 1);

    // ***For Release Year***

    Gtk::Label *label_release_year = Gtk::manage(new Gtk::Label("Release Year:"));
    grid1->attach(*label_release_year, 0, 4, 1, 1);
    
    entry_release_year = Gtk::manage(new Gtk::Entry());
    entry_release_year->set_text("");
    entry_release_year->set_max_length(50);
    grid1->attach(*entry_release_year, 1, 4, 1, 1);

    // ***For Studio***

    Gtk::Label *label_studio = Gtk::manage(new Gtk::Label("Studio:"));
    grid1->attach(*label_studio, 0, 5, 1, 1);
    
    entry_studio = Gtk::manage(new Gtk::Entry());
    entry_studio->set_text("");
    entry_studio->set_max_length(50);
    grid1->attach(*entry_studio, 1, 5, 1, 1);

    Gtk::Box *hbox_bottom = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
    vbox->add(*hbox_bottom);

    Gtk::Grid *grid2 = Gtk::manage(new Gtk::Grid);
    grid2->set_border_width(10);
    hbox_bottom->add(*grid2);
    
    Gtk::Button *button_cancel = Gtk::manage(new Gtk::Button("Cancel"));
    button_cancel->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_add_video_game_cancel_button_click));
    grid2->attach(*button_cancel, 0, 0, 1, 1);
    
    Gtk::Button *button_ok = Gtk::manage(new Gtk::Button("OK"));
    button_ok->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_add_video_game_ok_button_click));
    grid2->attach(*button_ok, 1, 0, 1, 1);
   
    window_add_video_game->show_all();
}
void Dialog::on_add_video_game_ok_button_click()
{
    string id_number_str = entry_id_number->get_text();
    stringstream id_number_geek(id_number_str);
    int id_number;
    id_number_geek >> id_number;
    string call_number = entry_call_number->get_text();
    string title = entry_title->get_text();
    string genre = entry_genre->get_text();
    string release_year_str = entry_release_year->get_text();
    stringstream release_year_geek(release_year_str);
    int release_year;
    release_year_geek >> release_year;
    string studio = entry_studio->get_text();
    Video_Game* video_game = new Video_Game(id_number, call_number, title, genre, release_year, studio);
    library.create_new_media(video_game);
    dialog("\"" + title + "\" added.");
    window_add_video_game->close();
    delete(window_add_video_game);
}
void Dialog::on_add_video_game_cancel_button_click()
{
    window_add_video_game->close();
    delete(window_add_video_game);
}

// *Add Music Album*
void Dialog::on_add_music_album_button_click()
{
    window_add_music_album = new Gtk::Window();
    window_add_music_album->set_title("Add Music Album");

    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    window_add_music_album->add(*vbox);

    Gtk::Box *hbox_top = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
    vbox->add(*hbox_top);

    Gtk::Grid *grid1 = Gtk::manage(new Gtk::Grid);
    grid1->set_border_width(10);
    hbox_top->add(*grid1);

    // ***For ID Number***

    Gtk::Label *label_id_number = Gtk::manage(new Gtk::Label("ID Number:"));
    grid1->attach(*label_id_number, 0, 0, 1, 1);
    
    entry_id_number = Gtk::manage(new Gtk::Entry());
    entry_id_number->set_text("");
    entry_id_number->set_max_length(50);
    grid1->attach(*entry_id_number, 1, 0, 1, 1);

    // ***For Call Number***

    Gtk::Label *label_call_number = Gtk::manage(new Gtk::Label("Call Number:"));
    grid1->attach(*label_call_number, 0, 1, 1, 1);
    
    entry_call_number = Gtk::manage(new Gtk::Entry());
    entry_call_number->set_text("");
    entry_call_number->set_max_length(50);
    grid1->attach(*entry_call_number, 1, 1, 1, 1);

    // ***For Title***

    Gtk::Label *label_title = Gtk::manage(new Gtk::Label("Title:"));
    grid1->attach(*label_title, 0, 2, 1, 1);
    
    entry_title = Gtk::manage(new Gtk::Entry());
    entry_title->set_text("");
    entry_title->set_max_length(50);
    grid1->attach(*entry_title, 1, 2, 1, 1);

    // ***For Genre***

    Gtk::Label *label_genre = Gtk::manage(new Gtk::Label("Genre:"));
    grid1->attach(*label_genre, 0, 3, 1, 1);
    
    entry_genre = Gtk::manage(new Gtk::Entry());
    entry_genre->set_text("");
    entry_genre->set_max_length(50);
    grid1->attach(*entry_genre, 1, 3, 1, 1);

    // ***For Release Year***

    Gtk::Label *label_release_year = Gtk::manage(new Gtk::Label("Release Year:"));
    grid1->attach(*label_release_year, 0, 4, 1, 1);
    
    entry_release_year = Gtk::manage(new Gtk::Entry());
    entry_release_year->set_text("");
    entry_release_year->set_max_length(50);
    grid1->attach(*entry_release_year, 1, 4, 1, 1);

    // ***For Artist***

    Gtk::Label *label_artist = Gtk::manage(new Gtk::Label("Artist:"));
    grid1->attach(*label_artist, 0, 5, 1, 1);
    
    entry_artist = Gtk::manage(new Gtk::Entry());
    entry_artist->set_text("");
    entry_artist->set_max_length(50);
    grid1->attach(*entry_artist, 1, 5, 1, 1);

    // ***For Tracks***

    Gtk::Label *label_tracks = Gtk::manage(new Gtk::Label("Track(s):"));
    grid1->attach(*label_tracks, 0, 7, 1, 1);
    
    entry_track = Gtk::manage(new Gtk::Entry());
    entry_track->set_text("");
    entry_track->set_max_length(50);
    grid1->attach(*entry_track, 1, 7, 1, 1);
    
    Gtk::Button *button_add_track = Gtk::manage(new Gtk::Button("Add Track"));
    button_add_track->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_add_track_button_click));
    grid1->attach(*button_add_track, 2, 7, 1, 1);

    Gtk::Box *hbox_bottom = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
    vbox->add(*hbox_bottom);

    Gtk::Grid *grid2 = Gtk::manage(new Gtk::Grid);
    grid2->set_border_width(10);
    hbox_bottom->add(*grid2);
    
    Gtk::Button *button_cancel = Gtk::manage(new Gtk::Button("Cancel"));
    button_cancel->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_add_music_album_cancel_button_click));
    grid2->attach(*button_cancel, 0, 0, 1, 1);
    
    Gtk::Button *button_ok = Gtk::manage(new Gtk::Button("OK"));
    button_ok->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_add_music_album_ok_button_click));
    grid2->attach(*button_ok, 1, 0, 1, 1);
   
    window_add_music_album->show_all();
}
void Dialog::on_add_music_album_ok_button_click()
{
    string id_number_str = entry_id_number->get_text();
    stringstream id_number_geek(id_number_str);
    int id_number;
    id_number_geek >> id_number;
    string call_number = entry_call_number->get_text();
    string title = entry_title->get_text();
    string genre = entry_genre->get_text();
    string release_year_str = entry_release_year->get_text();
    stringstream release_year_geek(release_year_str);
    int release_year;
    release_year_geek >> release_year;
    string artist = entry_artist->get_text();
    Music_Album* music_album = new Music_Album(id_number, call_number, title, genre, release_year, artist, tracks);
    library.create_new_media(music_album);
    dialog("\"" + title + "\" added.");
    tracks.clear();
    window_add_music_album->close();
    delete(window_add_music_album);

}
void Dialog::on_add_music_album_cancel_button_click()
{
    window_add_music_album->close();
    delete(window_add_music_album);
}
void Dialog::on_add_track_button_click()
{
    string track = entry_track->get_text();
    tracks.push_back(track);
    entry_track->set_text("");
    dialog("\"" + track + "\" added.");
}

// *Add Television Show Season
void Dialog::on_add_television_show_season_button_click()
{
    window_add_television_show_season = new Gtk::Window();
    window_add_television_show_season->set_title("Add Television Show");

    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    window_add_television_show_season->add(*vbox);

    Gtk::Box *hbox_top = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
    vbox->add(*hbox_top);

    Gtk::Grid *grid1 = Gtk::manage(new Gtk::Grid);
    grid1->set_border_width(10);
    hbox_top->add(*grid1);

    // ***For ID Number***

    Gtk::Label *label_id_number = Gtk::manage(new Gtk::Label("ID Number:"));
    grid1->attach(*label_id_number, 0, 0, 1, 1);
    
    entry_id_number = Gtk::manage(new Gtk::Entry());
    entry_id_number->set_text("");
    entry_id_number->set_max_length(50);
    grid1->attach(*entry_id_number, 1, 0, 1, 1);

    // ***For Call Number***

    Gtk::Label *label_call_number = Gtk::manage(new Gtk::Label("Call Number:"));
    grid1->attach(*label_call_number, 0, 1, 1, 1);
    
    entry_call_number = Gtk::manage(new Gtk::Entry());
    entry_call_number->set_text("");
    entry_call_number->set_max_length(50);
    grid1->attach(*entry_call_number, 1, 1, 1, 1);

    // ***For Title***

    Gtk::Label *label_title = Gtk::manage(new Gtk::Label("Title:"));
    grid1->attach(*label_title, 0, 2, 1, 1);
    
    entry_title = Gtk::manage(new Gtk::Entry());
    entry_title->set_text("");
    entry_title->set_max_length(50);
    grid1->attach(*entry_title, 1, 2, 1, 1);

    // ***For Genre***

    Gtk::Label *label_genre = Gtk::manage(new Gtk::Label("Genre:"));
    grid1->attach(*label_genre, 0, 3, 1, 1);
    
    entry_genre = Gtk::manage(new Gtk::Entry());
    entry_genre->set_text("");
    entry_genre->set_max_length(50);
    grid1->attach(*entry_genre, 1, 3, 1, 1);

    // ***For Release Year***

    Gtk::Label *label_release_year = Gtk::manage(new Gtk::Label("Release Year:"));
    grid1->attach(*label_release_year, 0, 4, 1, 1);
    
    entry_release_year = Gtk::manage(new Gtk::Entry());
    entry_release_year->set_text("");
    entry_release_year->set_max_length(50);
    grid1->attach(*entry_release_year, 1, 4, 1, 1);

    // ***For Producer***

    Gtk::Label *label_producer = Gtk::manage(new Gtk::Label("Producer:"));
    grid1->attach(*label_producer, 0, 5, 1, 1);
    
    entry_producer = Gtk::manage(new Gtk::Entry());
    entry_producer->set_text("");
    entry_producer->set_max_length(50);
    grid1->attach(*entry_producer, 1, 5, 1, 1);

    // ***For Voice Actors***

    Gtk::Label *label_voice_actors = Gtk::manage(new Gtk::Label("Voice Actor(s):"));
    grid1->attach(*label_voice_actors, 0, 6, 1, 1);
    
    entry_voice_actor = Gtk::manage(new Gtk::Entry());
    entry_voice_actor->set_text("");
    entry_voice_actor->set_max_length(50);
    grid1->attach(*entry_voice_actor, 1, 6, 1, 1);
    
    Gtk::Button *button_add_voice_actor = Gtk::manage(new Gtk::Button("Add Voice Actor"));
    button_add_voice_actor->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_add_voice_actor_button_click));
    grid1->attach(*button_add_voice_actor, 2, 6, 1, 1);

    // ***For Composers***

    Gtk::Label *label_composers = Gtk::manage(new Gtk::Label("Composer(s):"));
    grid1->attach(*label_composers, 0, 7, 1, 1);
    
    entry_composer = Gtk::manage(new Gtk::Entry());
    entry_composer->set_text("");
    entry_composer->set_max_length(50);
    grid1->attach(*entry_composer, 1, 7, 1, 1);
    
    Gtk::Button *button_add_composer = Gtk::manage(new Gtk::Button("Add Composer"));
    button_add_composer->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_add_composer_button_click));
    grid1->attach(*button_add_composer, 2, 7, 1, 1);

    // ***For Season Number***

    Gtk::Label *label_season_number = Gtk::manage(new Gtk::Label("Season Number:"));
    grid1->attach(*label_season_number, 0, 8, 1, 1);
    
    entry_season_number = Gtk::manage(new Gtk::Entry());
    entry_season_number->set_text("");
    entry_season_number->set_max_length(50);
    grid1->attach(*entry_season_number, 1, 8, 1, 1);

    Gtk::Box *hbox_bottom = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
    vbox->add(*hbox_bottom);

    Gtk::Grid *grid2 = Gtk::manage(new Gtk::Grid);
    grid2->set_border_width(10);
    hbox_bottom->add(*grid2);
    
    Gtk::Button *button_cancel = Gtk::manage(new Gtk::Button("Cancel"));
    button_cancel->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_add_television_show_season_cancel_button_click));
    grid2->attach(*button_cancel, 0, 0, 1, 1);
    
    Gtk::Button *button_ok = Gtk::manage(new Gtk::Button("OK"));
    button_ok->signal_clicked().connect(sigc::mem_fun(*this, &Dialog::on_add_television_show_season_ok_button_click));
    grid2->attach(*button_ok, 1, 0, 1, 1);
   
    window_add_television_show_season->show_all();
}
void Dialog::on_add_television_show_season_ok_button_click()
{
    string id_number_str = entry_id_number->get_text();
    stringstream id_number_geek(id_number_str);
    int id_number;
    id_number_geek >> id_number;
    string call_number = entry_call_number->get_text();
    string title = entry_title->get_text();
    string genre = entry_genre->get_text();
    string release_year_str = entry_release_year->get_text();
    stringstream release_year_geek(release_year_str);
    int release_year;
    release_year_geek >> release_year;
    string producer = entry_producer->get_text();
    string season_number_str = entry_season_number->get_text();
    stringstream season_number_geek(season_number_str);
    int season_number;
    season_number_geek >> season_number;
    Television_Show_Season* television_show_season = new Television_Show_Season(id_number, call_number, title, genre, release_year, producer, voice_actors, composers, season_number);
    library.create_new_media(television_show_season);
    dialog("\"" + title + "\" added.");
    voice_actors.clear();
    composers.clear();
    window_add_television_show_season->close();
    delete(window_add_television_show_season);
}
void Dialog::on_add_television_show_season_cancel_button_click()
{
    window_add_television_show_season->close();
    delete(window_add_television_show_season);
}
void Dialog::on_add_voice_actor_button_click()
{
    string voice_actor = entry_voice_actor->get_text();
    voice_actors.push_back(voice_actor);
    entry_voice_actor->set_text("");
    dialog(voice_actor + " added.");
}
void Dialog::on_add_composer_button_click()
{
    string composer = entry_composer->get_text();
    composers.push_back(composer);
    entry_composer->set_text("");
    dialog(composer + " added.");
}

/*
***Miscellaneous***
*/

string Dialog::to_lower_case(string s)
{
    for(int i = 0; i < s.size(); i++)
        s[i] = easy_to_lower(s[i]);
    return s;
}

char Dialog::easy_to_lower(char a)
{
    if(a <= 'Z' && a >= 'A')
        return a - ('Z' - 'z');
    return a;
}