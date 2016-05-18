#include "person.h"
#include "peopleList.h"
#include <fstream>
#include <vector>
#include "helper.h"
#define FNAME "people.txt"

//If you define test, you will simply load the people from your designated text file,
//and print all of those who are loaded to the screen.
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
              peopleArray[current->getSSN() % 10].append(current);
            }else{
              Person *current = new Person(stringToInt(person[5]), stringToInt(person[4]), stringToInt(person[3]), stringToInt(person[2]), person[1], person[0]);
              peopleArray[current->getSSN() % 10].append(current);
            }
        }
    }
#ifndef test
    //Get user input based on arguments.
    for(int i = 1; i<argc; i++){
      string temp = argv[i];
      Person *current = promptDefinePerson(temp);
      bool duplicate = false;
      //Go through the peopleList to check for duplicates.
      while(peopleArray[current->getSSN() % 10].head->data != NULL){
        peopleArray[current->getSSN() % 10].head = peopleArray[current->getSSN() % 10].head->next;
        if((peopleArray[current->getSSN() % 10].head->data->getSSN() == current->getSSN())&& (peopleArray[current->getSSN() % 10].head->data->checkDOB(current->DOB.month, current->DOB.day, current->DOB.year))){
          duplicate = true;
        }
      }
      if(!duplicate){
      peopleArray[current->getSSN() % 10].append(current);
      }
    }
#endif
#ifdef test

    for(int i = 0; i < 10; i++){
      peopleArray[i].printBlock();
    }
#endif

    inputFile.close();
}
