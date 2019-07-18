#ifndef AND7697_TRANSACTION_H_INCLUDED
#define AND7697_TRANSACTION_H_INCLUDED

#include "and7697_Bundle.h"
// #include "and7697_Media.h"
#include "and7697_Book.h"
#include "and7697_Movie.h"
#include "and7697_Video_Game.h"
#include "and7697_Music_Album.h"
#include "and7697_Television_Show_Season.h"
#include "and7697_Librarian.h"
#include "and7697_Customer.h"
#include "and7697_Date.h"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

class Transaction
{
public:
    Transaction(int t, Date cod, Librarian l, Customer c, vector<Media*> m, vector<Bundle*> b, Date cid, Date dd) : transaction_number {t}, check_out_date {cod}, librarian {l}, customer {c}, medias {m}, bundles {b}, check_in_date {cid}, due_date {dd}, type {"Transaction"} {};
    double calculate_fee();
    void set_type(string type);
    string get_type();
    string to_string();
    string to_file();
protected:
    string type;
private:
    int transaction_number;
    Date check_out_date;
    Librarian librarian;
    Customer customer;
    vector<Media*> medias;
    vector<Bundle*> bundles;
    Date check_in_date;
    Date due_date;
};

#endif // AND7697_TRANSACTION_H_INCLUDED
