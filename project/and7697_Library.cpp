#include "and7697_Library.h"

void Library::create_new_media(Media* media)
{
    medias.push_back(media);
}

void Library::create_new_bundle(Bundle* bundle)
{
    bundles.push_back(bundle);
}

void Library::create_new_librarian(Librarian* librarian)
{
    librarians.push_back(librarian);
}

void Library::create_new_customer(Customer* customer)
{
    customers.push_back(customer);
}

void Library::create_new_transaction(Transaction* transaction)
{
    transactions.push_back(transaction);
}

void Library::create_new_checked_out_media(Media* media)
{
    checked_out_list.push_back(media);
}

void Library::create_new_checked_out_bundle(Bundle* bundle)
{
    checked_out_bundle_list.push_back(bundle);
}

void Library::remove_checked_out_media(int id_number)
{
    for(int i = 0; i < checked_out_list.size(); i++)
    {
        if(id_number == (checked_out_list[i])->get_id_number())
        {
            checked_out_list.erase(checked_out_list.begin() + i);
        }
    }
}

void Library::remove_checked_out_bundle(string name)
{
    for(int i = 0; i < checked_out_bundle_list.size(); i++)
    {
        if(to_lower_case(name) == to_lower_case((checked_out_bundle_list[i])->get_name()))
        {
            checked_out_bundle_list.erase(checked_out_bundle_list.begin() + i);
        }
    }
}

vector<Media*> Library::get_medias()
{
    return medias;
}

vector<Bundle*> Library::get_bundles()
{
    return bundles;
}

vector<Librarian*> Library::get_librarians()
{
    return librarians;
}

vector<Customer*> Library::get_customers()
{
    return customers;
}

vector<Transaction*> Library::get_transactions()
{
    return transactions;
}

vector<Media*> Library::get_checked_out_list()
{
    return this->checked_out_list;
}

vector<Bundle*> Library::get_checked_out_bundle_list()
{
    return this->checked_out_bundle_list;
}

string Library::print_medias_to_string()
{
    string out;
    ostringstream ost;
    for(Media* it : medias)
        ost << it->to_string();
    out = ost.str();
    return out;
}

string Library::print_transactions_to_string()
{
    string out;
    ostringstream ost;
    for(Transaction* it : transactions)
    {
        ost << endl;
        ost << it->to_string();
    }
    out = ost.str();
    return out;
}

string Library::print_customers_to_string()
{
    string out;
    ostringstream ost;
    for(Customer* it : customers)
    {
        ost << endl;
        ost << it->to_string();
    }
    out = ost.str();
    return out;
}

string Library::print_librarians_to_string()
{
    string out;
    ostringstream ost;
    for(Librarian* it : librarians)
    {
        ost << endl;
        ost << it->to_string();
    }
    out = ost.str();
    return out;
}

string Library::print_bundles_to_string()
{
    string out;
    ostringstream ost;
    for(Bundle* it : bundles)
        ost << it->to_string();
    out = ost.str();
    return out;
}

string Library::print_checked_out_list_to_string()
{
    string out;
    ostringstream ost;
    for(Media* it : checked_out_list)
        ost << it->to_string();
    out = ost.str();
    return out;
}

string Library::print_checked_out_bundle_list_to_string()
{
    string out;
    ostringstream ost;
    for(Bundle* it : checked_out_bundle_list)
        it->to_string();
    out = ost.str();
    return out;
}

void Library::print_medias()
{
    cout << R"(
==============
Browse Catalog
==============
    )";
    for(Media* it : medias)
        cout << it->to_string();
}

void Library::print_transactions()
{

}

void Library::print_customers()
{

}

void Library::print_librarians()
{
    
}

void Library::print_bundles()
{

}

void Library::print_checked_out_list()
{
    cout << R"(
===========
Checked Out
===========
    )";
    for(Media* it : checked_out_list)
        cout << it->to_string();
}

void Library::print_checked_out_bundle_list()
{

}

string Library::to_string() const
{
    string out;
    ostringstream ost;
    for(Media* it : this->medias)
        ost << it->to_file();
    for(Transaction* it : this->transactions)
        ost << it->to_file();
    for(Customer* it : this->customers)
        ost << it->to_file();
    for(Librarian* it : this->librarians)
        ost << it->to_file();
    for(Bundle* it : this->bundles)
        ost << it->to_file();
    out = ost.str();
    return out;
}

ostream& operator<<(ostream& ost, const Library& library_two)
{
    for(Media* it : library_two.medias)
        ost << it->to_file();
    for(Transaction* it : library_two.transactions)
        ost << it->to_file();
    for(Customer* it : library_two.customers)
        ost << it->to_file();
    for(Librarian* it : library_two.librarians)
        ost << it->to_file();
    for(Bundle* it : library_two.bundles)
        ost << it->to_file();
    for(Media* it : library_two.checked_out_list)
        ost << it->to_file();
    for(Bundle* it : library_two.checked_out_bundle_list)
        ost << it->to_file();
    return ost;
}

istream& operator>>(istream& ist, Library& library_two)
{
    library_two.medias.clear();
    library_two.transactions.clear();
    library_two.customers.clear();
    library_two.librarians.clear();
    library_two.bundles.clear();
    while(ist)
    {
        // For Media
        string line_str;
        getline(ist, line_str);
        stringstream ist2(line_str);
        int id_number;
        string id_number_str;
        string call_number;
        string title;
        string genre;
        string type;
        getline(ist2, type, ';');
        if(type == "Book")
        {
            string author;
            int copyright_year;
            string copyright_year_str;
            getline(ist2, id_number_str, ';');
            id_number = library_two.string_to_int(id_number_str);
            getline(ist2, call_number, ';');
            getline(ist2, title, ';');
            getline(ist2, genre, ';');
            getline(ist2, author, ';');
            getline(ist2, copyright_year_str);
            copyright_year = library_two.string_to_int(copyright_year_str);
            Book *book = new Book(id_number, call_number, title, genre, author, copyright_year);
            library_two.create_new_media(book);
        }
        else if(type == "Movie")
        {
            int release_year;
            string release_year_str;
            string producer;
            string director;
            vector<string> leading_actors;
            string leading_actors_str;
            getline(ist2, id_number_str, ';');
            id_number = library_two.string_to_int(id_number_str);
            getline(ist2, call_number, ';');
            getline(ist2, title, ';');
            getline(ist2, genre, ';');
            getline(ist2, release_year_str, ';');
            release_year = library_two.string_to_int(release_year_str);
            getline(ist2, producer, ';');
            getline(ist2, director, ';');
            getline(ist2, leading_actors_str);
            stringstream leading_actors_geek(leading_actors_str);
            while(leading_actors_geek)
            {
                string leading_actor;
                if(getline(leading_actors_geek, leading_actor, ':'))
                    leading_actors.push_back(leading_actor);
            }
            Movie *movie = new Movie(id_number, call_number, title, genre, release_year, producer, director, leading_actors);
            library_two.create_new_media(movie);
        }
        else if(type == "Video_Game")
        {
            int release_year;
            string release_year_str;
            string studio;
            getline(ist2, id_number_str, ';');
            id_number = library_two.string_to_int(id_number_str);
            getline(ist2, call_number, ';');
            getline(ist2, title, ';');
            getline(ist2, genre, ';');
            getline(ist2, release_year_str, ';');
            release_year = library_two.string_to_int(release_year_str);
            getline(ist2, studio);
            Video_Game *video_game = new Video_Game(id_number, call_number, title, genre, release_year, studio);
            library_two.create_new_media(video_game);
        }
        else if(type == "Music_Album")
        {
            int release_year;
            string release_year_str;
            vector<string> tracks;
            string tracks_str;
            string artist;
            getline(ist2, id_number_str, ';');
            id_number = library_two.string_to_int(id_number_str);
            getline(ist2, call_number, ';');
            getline(ist2, title, ';');
            getline(ist2, genre, ';');
            getline(ist2, release_year_str, ';');
            release_year = library_two.string_to_int(release_year_str);
            getline(ist2, artist, ';');
            getline(ist2, tracks_str);
            stringstream tracks_geek(tracks_str);
            while(tracks_geek)
            {
                string track;
                if(getline(tracks_geek, track, ':'))
                    tracks.push_back(track);
            }
            Music_Album *music_album = new Music_Album(id_number, call_number, title, genre, release_year, artist, tracks);
            library_two.create_new_media(music_album);
        }
        else if(type == "Television_Show_Season")
        {
            int release_year;
            string release_year_str;
            string producer;
            vector<string> voice_actors;
            string voice_actors_str;
            vector<string> composers;
            string composers_str;
            int season_number;
            string season_number_str;
            getline(ist2, id_number_str, ';');
            id_number = library_two.string_to_int(id_number_str);
            getline(ist2, call_number, ';');
            getline(ist2, title, ';');
            getline(ist2, genre, ';');
            getline(ist2, release_year_str, ';');
            release_year = library_two.string_to_int(release_year_str);
            getline(ist2, producer, ';');
            getline(ist2, voice_actors_str, ';');
            stringstream voice_actors_geek(voice_actors_str);
            while(voice_actors_geek)
            {
                string voice_actor;
                if(getline(voice_actors_geek, voice_actor, ':'))
                    voice_actors.push_back(voice_actor);
            }
            getline(ist2, composers_str, ';');
            stringstream composers_geek(composers_str);
            while(composers_geek)
            {
                string composer;
                if(getline(composers_geek, composer, ':'))
                    composers.push_back(composer);
            }
            getline(ist2, season_number_str);
            season_number = library_two.string_to_int(season_number_str);
            Television_Show_Season *television_show_season = new Television_Show_Season(id_number, call_number, title, genre, release_year, producer, voice_actors, composers, season_number);
            library_two.create_new_media(television_show_season);
        }
        else if(type == "Transaction")
        {
            int year, month, day;
            int transaction_number;
            string transaction_number_str;
            string check_out_date_str;
            Librarian *librarian;
            int librarian_id_number;
            string librarian_id_number_str;
            Customer *customer;
            int customer_id_number;
            string customer_id_number_str;
            vector<Media*> medias;
            vector<Bundle*> bundles;
            string check_in_date_str;
            string due_date_str;
            getline(ist2, transaction_number_str, ';');
            transaction_number = library_two.string_to_int(transaction_number_str);
            getline(ist2, check_out_date_str, ';');
            stringstream check_out_date_geek(check_out_date_str);
            check_out_date_geek >> month;
            check_out_date_geek >> day;
            check_out_date_geek >> year;
            Date *check_out_date = new Date(year, month, day);
            getline(ist2, librarian_id_number_str, ';');
            librarian_id_number = library_two.string_to_int(librarian_id_number_str);
            for(Librarian* it : library_two.librarians)
            {
                if(librarian_id_number == it->get_id())
                {
                    librarian = it;
                }
            }
            getline(ist2, customer_id_number_str, ';');
            customer_id_number = library_two.string_to_int(customer_id_number_str);
            string id_numbers_str;
            for(Customer* it : library_two.customers)
            {
                if(customer_id_number == it->get_id())
                {
                    customer = it;
                }
            }
            getline(ist2, id_numbers_str, ';');
            stringstream id_numbers_geek(id_numbers_str);
            while(id_numbers_geek)
            {
                int id_number;
                if(getline(id_numbers_geek, id_number_str, ':'))
                {
                    id_number = library_two.string_to_int(id_number_str);
                    for(Media* it : library_two.medias)
                    {
                        if(id_number == it->get_id_number())
                        {
                            medias.push_back(it);
                            break;
                        }
                    }
                }
            }
            string names_str;
            getline(ist2, names_str, ';');
            stringstream names_geek(names_str);
            while(names_geek)
            {
                string name;
                if(getline(names_geek, name, ':'))
                {
                    for(Bundle* it : library_two.bundles)
                    {
                        if(name == it->get_name())
                        {
                            bundles.push_back(it);
                            break;
                        }
                    }
                }
            }
            getline(ist2, check_in_date_str, ';');
            stringstream check_in_date_geek(check_in_date_str);
            check_in_date_geek >> month;
            check_in_date_geek >> day;
            check_in_date_geek >> year;
            Date *check_in_date = new Date(year, month, day);
            getline(ist2, due_date_str);
            stringstream due_date_geek(due_date_str);
            due_date_geek >> month;
            due_date_geek >> day;
            due_date_geek >> year;
            Date *due_date = new Date(year, month, day);
            Transaction *transaction = new Transaction(transaction_number, *check_out_date, *librarian, *customer, medias, bundles, *check_in_date, *due_date);
            library_two.create_new_transaction(transaction);
        }
        else if(type == "Customer")
        {
            string name;
            int id;
            string id_str;
            int phone;
            string phone_str;
            string email;
            double balance;
            string balance_str;
            getline(ist2, name, ';');
            getline(ist2, id_str, ';');
            id = library_two.string_to_int(id_str);
            getline(ist2, phone_str, ';');
            phone = library_two.string_to_int(phone_str);
            getline(ist2, email, ';');
            getline(ist2, balance_str);
            balance = library_two.string_to_double(balance_str);
            Customer *customer = new Customer(name, id, phone, email, balance);
            library_two.create_new_customer(customer);
        }
        else if(type == "Librarian")
        {
            string name;
            int id;
            string id_str;
            getline(ist2, name, ';');
            getline(ist2, id_str);
            id = library_two.string_to_int(id_str);
            Librarian *librarian = new Librarian(name, id);
            library_two.create_new_librarian(librarian);
        }
        else if(type == "Bundle")
        {
            string name;
            vector<Media*> medias;
            string id_numbers_str;
            getline(ist2, name, ';');
            getline(ist2, id_numbers_str);
            stringstream id_numbers_geek(id_numbers_str);
            while(id_numbers_geek)
            {
                int id_number;
                if(getline(id_numbers_geek, id_number_str, ':'))
                {
                    id_number = library_two.string_to_int(id_number_str);
                    for(Media* it : library_two.medias)
                    {
                        if(id_number == it->get_id_number())
                        {
                            medias.push_back(it);
                            break;
                        }
                    }
                }
            }
            Bundle *bundle = new Bundle(name, medias);
            library_two.create_new_bundle(bundle);
        }
    }
    return ist;
}

void Library::save(string file_name)
{
    
}

void Library::load(string file_name)
{
    
}

string Library::to_lower_case(string s)
{
    for(int i = 0; i < s.size(); i++)
        s[i] = easy_to_lower(s[i]);
    return s;
}

char Library::easy_to_lower(char a)
{
    if(a <= 'Z' && a >= 'A')
        return a - ('Z' - 'z');
    return a;
}

int Library::string_to_int(string s)
{
    int a;
    stringstream geek(s);
    geek >> a;
    return a;
}

double Library::string_to_double(string s)
{
    double a;
    stringstream geek(s);
    geek >> a;
    return a;
}
