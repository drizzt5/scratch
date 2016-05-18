#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
int main()
{
    ifstream inputFile;
    inputFile.open("people.txt", fstream::in);
    int ssn, day, month, year, joinMonth, joinYear;
    string firstName, lastName, mystring, delim = ",", token;
    vector<string> person;
    vector<string>::iterator it;

    if (inputFile.is_open())
    {
        while( getline(inputFile, mystring) )
        {
            it = person.begin();
            person.clear();
            while(token != mystring)
            {
                token = mystring.substr(0,mystring.find_first_of(delim));
                mystring = mystring.substr(mystring.find_first_of(delim) + 1);
                person.insert(person.begin(), token.c_str());
            }
            cout << person.size() << endl;
        }
    }
    inputFile.close();


    return 0;
}
