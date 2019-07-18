#ifndef AND7697_BUNDLE_H_INCLUDED
#define AND7697_BUNDLE_H_INCLUDED

#include "and7697_Media.h"

class Bundle
{
public:
    Bundle(string n, vector<Media*> m) : name {n}, medias {m}, checked_out {false} {set_type("Bundle");};
    void check_out_bundle();
    void check_in_bundle();
    void add_to_bundle(Media *media);
    void remove_from_bundle(int id);
    string get_name();
    vector<Media*> get_medias();
    void set_type(string type);
    string get_type();
    bool is_checked_out();
    string to_string() const;
    string to_file() const;
    friend ostream& operator<<(ostream& ost, const Bundle& bundle_two);
protected:
    string type;
private:
    string name;
    vector<Media*> medias;
    bool checked_out;
};

#endif // AND7697_BUNDLE_H_INCLUDED
