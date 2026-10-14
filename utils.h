// utils.h - small helper functions shared by every file in the project
#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <vector>
using namespace std;

// Reads an integer safely. If the user types letters instead of a number,
// it asks again instead of getting stuck in an infinite loop.
inline int readInt(const string& prompt) {
    int x;
    cout << prompt;
    while (!(cin >> x)) {
        cin.clear();                                          // reset the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // throw away the bad input
        cout << "Please enter a valid number: ";
    }
    return x;
}

#endif
