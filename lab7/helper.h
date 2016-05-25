#ifndef HELPER_H_
#define HELPER_H_
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "person.h"
Person *promptDefinePerson(string firstName);
long stringToInt(string s);
string capitalizeName(string name);
bool verifySSN(string SSN);
bool verifyDOB(int month, int day, int year);

#endif
