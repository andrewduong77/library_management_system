#include "and7697_Bundle.h"

void Bundle::check_out_bundle()
{
    this->checked_out = true;
}

void Bundle::check_in_bundle()
{
    this->checked_out = false;
}


void Bundle::add_to_bundle(Media *media)
{
    medias.push_back(media);
}

void Bundle::remove_from_bundle(int id)
{
    for(int i = 0; i < medias.size(); i++)
        if(medias[i]->get_id_number() == id)
            medias.erase(medias.begin()+i);
}

string Bundle::get_name()
{
    return name;
}

vector<Media*> Bundle::get_medias()
{
    return medias;
}

void Bundle::set_type(string type)
{
    this->type = type;
}

string Bundle::get_type()
{
    return type;
}

bool Bundle::is_checked_out()
{
    return checked_out;
}

string Bundle::to_string() const
{
    string out;
    ostringstream ost;
    ost << "================" << endl << name << " Bundle" << endl << "================" << endl << endl;
    for(Media* it : medias)
    {
        ost << "    == " << it->get_type() << " ==" << endl;
        ost << "        ID Number: " << it->get_id_number() << endl;
        ost << "        Title: " << it->get_title() << endl;
    }
    out = ost.str();
    return out;
}

string Bundle::to_file() const
{
    string out;
    ostringstream ost;
    ost << this->type << ";"
        << this->name << ";";
    for(int i = 0; i < medias.size(); i++)
    {
        ost << (medias[i])->get_id_number();
        if(i < medias.size() - 1)
            ost << ":";
    }
    // for(Media* it : this->medias)
    //     ost << it->get_id_number() << ":";
    ost << endl;
    out = ost.str();
    return out;
}

ostream& operator<<(ostream& ost, const Bundle& bundle_two)
{
    ost << "================" << endl << bundle_two.name << " Bundle" << endl << "================" << endl << endl;
    for(Media* it : bundle_two.medias)
    {
        ost << "    == " << it->get_type() << " ==" << endl;
        ost << "        ID Number: " << it->get_id_number() << endl;
        ost << "        Title: " << it->get_title() << endl;
    }
    return ost;
}
