#ifndef AND7697_CUSTOMER_H_INCLUDED
#define AND7697_CUSTOMER_H_INCLUDED

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

class Customer
{
public:
    Customer(string n, int idn, int p, string e, double b) : name {n}, id {idn}, phone {p}, email {e}, balance {b}, type {"Customer"} {};
    void pay_balance();
    string get_name();
    int get_id();
    int get_phone();
    string get_email();
    double get_balance();
    void set_type(string type);
    string get_type();
    string to_string() const;
    string to_file() const;
    friend ostream& operator<<(ostream& ost, const Customer& customer_two);
protected:
    string type;
private:
    string name;
    int id;
    int phone;
    string email;
    double balance;
};

#endif // AND7697_CUSTOMER_H_INCLUDED
