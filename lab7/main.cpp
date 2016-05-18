#include "person.h"
#include "peopleList.h"
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
#define FNAME "people.txt"
//Person person *promptDefinePerson(string firstName);
long stringToInt(string s);
int main(int argc, char **argv)
{
    PeopleList peopleArray[10];
    ifstream inputFile;
    inputFile.open(FNAME, fstream::in);
    int ssn, day, month, year, joinMonth, joinYear;
    string firstName, lastName, mystring, delim = ",", token;
    vector<string> person;
    vector<string>::iterator it;
    //Load from file and add to appropriate lists.
    if (inputFile.is_open())
    {
        while( getline(inputFile, mystring) )
        {
            it = person.begin();
            person.clear();
            //Parse based on CSV. Load into a temp vector for loading one at a time.
            while(token != mystring)
            {
                token = mystring.substr(0,mystring.find_first_of(delim));
                mystring = mystring.substr(mystring.find_first_of(delim) + 1);
                person.insert(person.begin(), token.c_str());
            }
            //Modulo 10 to get the last digit.
            if(person.size() == 9){
              Person *current = new Student(stringToInt(person[8]), stringToInt(person[7]), stringToInt(person[6]), stringToInt(person[5]), person[4], person[3], stringToInt(person[2]), stringToInt(person[1]), stringToInt(person[0]));//peopleArray[current->getSSN() % 10].append(current);
              peopleArray[current->getSSN() % 10].append(current);
            }else if(person.size() == 8){
              Person *current = new Faculty(stringToInt(person[7]), stringToInt(person[6]), stringToInt(person[5]), stringToInt(person[4]), person[3], person[2], stringToInt(person[1]), stringToInt(person[0]));
              cout << endl;
              peopleArray[current->getSSN() % 10].append(current);
            }else{
              Person *current = new Person(stringToInt(person[5]), stringToInt(person[4]), stringToInt(person[3]), stringToInt(person[2]), person[1], person[0]);
              peopleArray[current->getSSN() % 10].append(current);
            }
        }
    }
    inputFile.close();

}

long stringToInt(string s){
  //Function written because stoi wasn't functioning for whatever reason.
  stringstream ss(s);
  long result;
  ss >> result;
  return result;
}
