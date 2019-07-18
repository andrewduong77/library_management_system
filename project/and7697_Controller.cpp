#include "and7697_Controller.h"

int Controller::gui(int argc, char *argv[])
{
    Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "com.gtkmm.tutorial3.base");

    Dialog dialog(library);

    return app->run(dialog);
}

void Controller::cli()
{
    int cmd = -1;
    while(cmd != 7)
    {
        cout << view.get_menu();
        cin >> cmd;
        execute_cmd(cmd);
        cout << endl;
    }
}

void Controller::execute_cmd(int cmd)
{
    switch(cmd)
    {
    case 1: // browse catalog
        library.print_medias();
        break;
    case 2: // add
        cli_add();
        break;
    case 3: // check in

        break;
    case 4: // check out

        break;
    case 5: // save file
        save();
        break;
    case 6: // load file
        load();
        break;
    case 7: // exit
        cout << endl << "Thank You!";
        break;
    default: // invalid input
        cout << endl << view.print_try_again_message();
        break;
    }
}

void Controller::cli_add()
{
    int cmd_add = -1;
    while(cmd_add != 6)
    {
        cout << view.get_add_menu();
        cin >> cmd_add;
        cmd_add = execute_cmd_add(cmd_add);
        cout << endl;
    }
}

int Controller::execute_cmd_add(int cmd_add)
{
    switch(cmd_add)
    {
    case 1: // add media
        cli_add_media();
        cmd_add = 6; // to exit
        break;
    case 2: // add transaction

        break;
    case 3: // add customer
        add_customer();
        cmd_add = 6; // to exit
        break;
    case 4: // add librarian
        add_librarian();
        cmd_add = 6; // to exit
        break;
    case 5: // add bundle

        break;
    case 6: // exit
        break;
    default:
        cout << endl << view.print_try_again_message();
        break;
    }
    return cmd_add;
}

void Controller::cli_add_media()
{
    int cmd_add_media = -1;
    while(cmd_add_media != 6)
    {
        cout << view.get_add_media_menu();
        cin >> cmd_add_media;
        cmd_add_media = execute_cmd_add_media(cmd_add_media);
        cout << endl;
    }
}

int Controller::execute_cmd_add_media(int cmd_add_media)
{
    switch(cmd_add_media)
    {
    case 1: // add book
        add_book();
        cmd_add_media = 6; // to exit
        break;
    case 2: // add movie
        add_movie();
        cmd_add_media = 6; // to exit
        break;
    case 3: // add video game
        add_video_game();
        cmd_add_media = 6; // to exit
        break;
    case 4: // add music album
        add_music_album();
        cmd_add_media = 6; // to exit
        break;
    case 5: // add television show
        add_television_show_season();
        cmd_add_media = 6; // to exit
        break;
    case 6: // exit
        break;
    default: // invalid input
        cout << endl << view.print_try_again_message();
        break;
    }
    return cmd_add_media;
}

void Controller::add_book()
{
    int id_number;
    string call_number;
    string title;
    string genre;
    string author;
    int copyright_year;
    cout << "ID Number: ";
    cin >> id_number;
    cout << "Call Number: ";
    cin >> call_number;
    cin.ignore();
    cout << "Title: ";
    getline(cin, title);
    cout << "Genre: ";
    getline(cin, genre);
    cout << "Author: ";
    getline(cin, author);
    cout << "Copyright Year: ";
    cin >> copyright_year;
    Book* book = new Book(id_number, call_number, title, genre, author, copyright_year);
    library.create_new_media(book);
}

void Controller::add_movie()
{
    int id_number;
    string call_number;
    string title;
    string genre;
    int release_year;
    string producer;
    string director;
    vector<string> leading_actors;
    cout << "ID Number: ";
    cin >> id_number;
    cout << "Call Number: ";
    cin >> call_number;
    cin.ignore();
    cout << "Title: ";
    getline(cin, title);
    cout << "Genre: ";
    getline(cin, genre);
    cout << "Release Year: ";
    cin >> release_year;
    cin.ignore();
    cout << "Producer: ";
    getline(cin, producer);
    cout << "Director: ";
    getline(cin, director);
    cout << "Please input the number of leading actors: ";
    int count;
    cin >> count;
    cin.ignore();
    cout << "Now please input the name of a leading actor and press 'enter' to input the name of the next leading actor." << endl;
    for(int i = 0; i < count; i++)
    {
        string input;
        getline(cin, input);
        leading_actors.push_back(input);
    }
    Movie* movie = new Movie(id_number, call_number, title, genre, release_year, producer, director, leading_actors);
    library.create_new_media(movie);
}

void Controller::add_video_game()
{
    int id_number;
    string call_number;
    string title;
    string genre;
    int release_year;
    string studio;
    cout << "ID Number: ";
    cin >> id_number;
    cout << "Call Number: ";
    cin >> call_number;
    cin.ignore();
    cout << "Title: ";
    getline(cin, title);
    cout << "Genre: ";
    getline(cin, genre);
    cout << "Release Year: ";
    cin >> release_year;
    cin.ignore();
    cout << "Studio: ";
    getline(cin, studio);
    Video_Game* video_game = new Video_Game(id_number, call_number, title, genre, release_year, studio);
    library.create_new_media(video_game);
}

void Controller::add_music_album()
{
    int id_number;
    string call_number;
    string title;
    string genre;
    int release_year;
    string artist;
    vector<string> tracks;
    cout << "ID Number: ";
    cin >> id_number;
    cout << "Call Number: ";
    cin >> call_number;
    cin.ignore();
    cout << "Title: ";
    getline(cin, title);
    cout << "Genre: ";
    getline(cin, genre);
    cout << "Release Year: ";
    cin >> release_year;
    cin.ignore();
    cout << "Artist: ";
    getline(cin, artist);
    cout << "Please input the number of tracks: ";
    int count;
    cin >> count;
    cin.ignore();
    cout << "Now please input the name of a track and press 'enter' to input the name of the next track." << endl;
    for(int i = 0; i < count; i++)
    {
        string input;
        getline(cin, input);
        tracks.push_back(input);
    }
    Music_Album* music_album = new Music_Album(id_number, call_number, title, genre, release_year, artist, tracks);
    library.create_new_media(music_album);
}

void Controller::add_television_show_season()
{
    int id_number;
    string call_number;
    string title;
    string genre;
    int release_year;
    string producer;
    vector<string> voice_actors;
    vector<string> composers;
    int season_number;
    cout << "ID Number: ";
    cin >> id_number;
    cout << "Call Number: ";
    cin >> call_number;
    cin.ignore();
    cout << "Title: ";
    getline(cin, title);
    cout << "Genre: ";
    getline(cin, genre);
    cout << "Release Year: ";
    cin >> release_year;
    cin.ignore();
    cout << "Producer: ";
    getline(cin, producer);
    cout << "Please input the number of voice actors: ";
    int count;
    cin >> count;
    cin.ignore();
    cout << "Now please input the name of a voice actor and press 'enter' to input the name of the next voice actor." << endl;
    for(int i = 0; i < count; i++)
    {
        string input;
        getline(cin, input);
        voice_actors.push_back(input);
    }
    cout << "Please input the number of composers: ";
    cin >> count;
    cin.ignore();
    cout << "Now please input the name of a composer and press 'enter' to input the name of the next composer." << endl;
    for(int i = 0; i < count; i++)
    {
        string input;
        getline(cin, input);
        composers.push_back(input);
    }
    cin >> season_number;
    Television_Show_Season* television_show_season = new Television_Show_Season(id_number, call_number, title, genre, release_year, producer, voice_actors, composers, season_number);
    library.create_new_media(television_show_season);
}

void Controller::add_customer()
{
    string name;
    int id;
    int phone;
    string email;
    double balance;
    cout << "Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "ID: ";
    cin >> id;
    cout << "Phone: ";
    cin >> phone;
    cin.ignore();
    cout << "Email: ";
    getline(cin, email);
    cout << "Balance: ";
    cin >> balance;
    Customer* customer = new Customer(name, id, phone, email, balance);
    library.create_new_customer(customer);
}

void Controller::add_librarian()
{
    string name;
    int id;
    cout << "Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "ID: ";
    cin >> id;
    Librarian* librarian = new Librarian(name, id);
    library.create_new_librarian(librarian);
}

void Controller::save()
{
    string file_name;
    cout << "Save filename: ";
    cin.ignore();
    getline(cin, file_name);
    // library.save(file_name);
    ofstream my_file(file_name);
    if(my_file.is_open())
    {
        if(my_file << library)
            cout << endl << "File saved successfully.";
        else
            cout << endl << "Unable to save file.";
    }
    else
        cout << endl << "Unable to open file.";
}

void Controller::load()
{
    string file_name;
    cout << "Load filename: ";
    cin.ignore();
    getline(cin, file_name);
    library.load(file_name);
}
