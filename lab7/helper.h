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
bool verifyDOB(string DOB);

#endif
