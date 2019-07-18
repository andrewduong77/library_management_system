#include "and7697_Transaction.h"

double Transaction::calculate_fee()
{

}

void Transaction::set_type(string type)
{
    this->type = type;
}

string Transaction::get_type()
{
    return type;
}

string Transaction::to_string()
{
    string out;
    ostringstream ost;
    ost << R"(
== Transaction ==
              )" << endl;
    // ost << "   ERROR: to_string on transaction doesn't wanna work, it's too messy and retarded... Inheritance can be one pain in the n**! >:(" << endl;
    ost << "    Transaction Number: " << this->transaction_number << endl;
    ost << "    Check Out Date: " << this->check_out_date << endl;
    ost << "    Librarian: " << this->librarian.get_name() << endl;
    ost << "    Customer: " << this->customer.get_name() << endl;
    ost << "    Media(s): " << endl;
    for(Media* it : medias)
        ost << "        Title: " << it->get_title() << endl;
    ost << "    Bundle(s): " << endl;
    for(Bundle* it : bundles)
        ost << "        " << it->get_name() << " Bundle" << endl;
    ost << "    Check In Date: " << this->check_in_date << endl;
    ost << "    Due Date: " << this->due_date << endl;
    out = ost.str();
    return out;
}

string Transaction::to_file()
{
    string out;
    ostringstream ost;
    ost << this->type << ";"
        << this->transaction_number << ";"
        << this->check_out_date << ";"
        << this->librarian.get_id() << ";"
        << this->customer.get_id() << ";";
    for(int i = 0; i < medias.size(); i++)
    {
        ost << (medias[i])->get_id_number();
        if(i < medias.size() - 1)
            ost << ":";
    }
    for(int i = 0; i < bundles.size(); i++)
    {
        ost << (bundles[i])->get_name();
        if(i < bundles.size() - 1)
            ost << ":";
    }
    ost << this->check_in_date << ";"
        << this->due_date << endl;
    out = ost.str();
    return out;
}
