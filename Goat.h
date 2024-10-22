// Goat.h

#ifndef GOAT_H
#define GOAT_H
#include <iostream>
using namespace std;

class Goat {
private:
    string name;
    int age;
public: 
    Goat()                    { name = ""; age = 0; }
    Goat(string n, int a)     { name = n; age = a; }
    void set_name(string n)   { name = n; };
    string get_name() const   { return name; };
    void set_age(int a)       { age = a; };
    int get_age() const       { return age; }

    // overload the < operator so sorting can occur
    // if a data structure using this class supports sorting (e.g., STL::set)
    // we need to tell the compiler which private member variable
    // to use in the sorting: name or age? Here, we pick name.
    bool operator< (const Goat &other) const {
        return name < other.name;
    }
};

#endif