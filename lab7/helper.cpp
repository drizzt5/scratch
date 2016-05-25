#include "helper.h"
#include <stdio.h>
#include <iostream>
#define CURRENT_YEAR 2016
using namespace std;
long stringToInt(string s) {
    //Function written because stoi wasn't functioning for whatever reason.
    stringstream ss(s);
    long result;
    ss >> result;
    return result;
}

Person *promptDefinePerson(string firstName)
{
    string cleaned = capitalizeName(firstName);
    //values for base person
    string lastName, ssn, DOB;
    long SSN;
    int m, d, y;
    char choice;
    cout << "Is " << cleaned << " a Person(p), Student(s), or Faculty(f)" << endl;
    cin >> choice;
    cout << "Alright, enter a last name: " << endl;
    cin >> lastName;
    int i;
    for (i = 0; i < 5; i++)
    {
        cout << "Alright, enter a SSN (XXXXXXXXX): " << endl;
        cin >> ssn;
        if (verifySSN(ssn)) {
            SSN = (long)stringToInt(ssn);
            break;
        }
        cout << "You entered an incorrect SSN. You have " << (4 - i) << " attemps remaining." << endl;
    }
    // if (!passed) {
    //   cout << "You blew it, everything went wrong we're getting out of here. " << endl;
    //   return NULL;
    // }
    // passed = false;
    bool passed = false;
    for (i = 0; i < 5; i++)
    {
        cout << "Alright, enter DOB (MMDDYYYY): " << endl;
        cin >> DOB;
        if (DOB.length() == 8) {
            m = stringToInt(DOB.substr(0, 2));
            d = stringToInt(DOB.substr(2, 2));
            y = stringToInt(DOB.substr(4, 4));
            if (verifyDOB(m, d, y)) {
                passed = true;
            }
        }
        if (passed) break;
        cout << "You entered an incorrect DOB. You have " << (4 - i) << " attemps remaining." << endl;
    }
    // if (!passed) {
    //   cout << "You blew it, everything went wrong we're getting out of here. " << endl;
    //   return NULL;
    // }
    Person *current;
    //Special attribute declarations
    int studentID;
    string classOf, joinDate;
    switch (choice)
    {
    case 'p':
        current = new Person(SSN, m, d, y, cleaned, lastName);
        break;
    case 's':

        cout << "What's your student ID?: " << endl;
        cin >> studentID;
        cout << "What classOf are you? (MMYYYY): " << endl;
        cin >> classOf;
        current = new Student(SSN, m, d, y, cleaned, lastName, studentID, stringToInt(classOf.substr(0, 2)), stringToInt(classOf.substr(2, 2)));
        break;
    case 'f':

        cout << "On what date did you join the faculty? (MMYYYY)" << endl;
        cin >> joinDate;
        current = new Faculty(SSN, m, d, y, cleaned, lastName, stringToInt(joinDate.substr(0, 2)), stringToInt(joinDate.substr(2, 2)));
        break;
    default:
        cout << "You didn't enter a proper archetype. Exiting...";
        return NULL;
    }
    return current;

}

string capitalizeName(string name)
{
    for (int i = 0; i < name.size(); i++)
    {
        name[i] = tolower(name[i]);
    }
    name[0] = toupper(name[0]);
    return name;
}
bool verifySSN(string SSN)
{
    return SSN.size() == 9;
}
bool verifyDOB(int month, int day, int year)
{
    return (1 <= month) && (month <= 12) && (1 <= day) && (day <= 31) && (1887 <= year) && (year <= CURRENT_YEAR);
}
