// Demonstration of STL::list with objects
// FUN FACT: a herd of goats is called a 'trip'
#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ = 200;

int main() {
    srand(time(0));

    // first read names file and store in an array
    ifstream fin("names.txt");
    string names[SZ];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();

    // create a set of Goat objects
    list<Goat> trip;   // a herd of goats is called a "trip" <-- fun fact
    // create 3 Goat objects and insert them into the list & print
    for (int i = 0; i < 3; i++) {
        Goat tmp(names[rand() % SZ], rand() % 20 + 1);
        trip.push_back(tmp);
    }
    cout << "The trip has " << trip.size() << " goats:\n";
    for (auto val : trip)
        cout << "\t" << val.get_name() << endl;

    // if we use emplace(), we don't have to create the temporary
    // Goat object first; we can just provide the constructor arguments
    for (int i = 0; i < 8; i++) {
        trip.emplace_back(names[rand() % SZ], rand() % 20 + 1);
    }
    cout << "The trip has " << trip.size() << " goats:\n";
    // note alternate method of printing using an iterator
    for (auto it = trip.begin(); it != trip.end(); it++)
        cout << "\t" << it->get_name() << endl;

    // let's sort for good measure
    trip.sort();   
    cout << "Sorted:\n";    
    for (auto val : trip)
        cout << "\t" << val.get_name() << endl;

    return 0;
}

/*
Common <list> member functions:
.back()              // returns a reference to the last element in the container
.begin()             // returns an iterator to the first element
.clear()             // removes all elements from the list
.emplace(it, args)   // emplaces, but requires an iterator pointing to an existing element
.emplace_back(args)  // emplaces to the back
.emplace_front(args) // emplaces to the front
.empty()             // returns true if empty; false otherwise
.erase(it)           // erases the element pointed to by the iterator
.front()             // returns a reference to the first element in the container
.insert(it, value)   // inserts value before the element at the specified position
.pop_back()          // removes the last element
.pop_front()         // removes the first element
.push_back(value)    // adds an element to the end
.push_front(value)   // adds an element to the front
.remove(value)       // removes all elements equal to value
.reverse()           // reverses the order of the elements
.sort()              // sorts the elements
.size()              // returns the number of elements
.unique()            // deduplicates the list
*/