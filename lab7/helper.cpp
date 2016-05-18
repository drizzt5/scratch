#include "helper.h"
#include <stdio.h>
#define CURRENT_YEAR 2016
using namespace std;
long stringToInt(string s){
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
  char choice;
  cout << "Is " << cleaned << " a Person(p), Student(s), or Faculty(f)" << endl;
  cin >> choice;

  cout << "Alright, enter a last name: " << endl;
  cin >> lastName;

  for(int i = 0; i<5; i++)
  {
      cout << "Alright, enter a SSN (XXXXXXXXX): ";
      cin >> ssn;
      if(verifySSN(ssn)) break;
      cout << "You entered an incorrect SSN. You have " << (4-i) << " attemps remaining." << endl;
  }

  for(int i = 0; i<5; i++)
  {
      cout << "Alright, enter DOB (MMDDYYYY): ";
      cin >> DOB;
      if(verifyDOB(DOB)) break;
      cout << "You entered an incorrect SSN. You have " << (4-i) << " attemps remaining." << endl;
  }
  Person *current;
  //Special attribute declarations
  int studentID;
  string classOf, joinDate;
  switch(choice)
  {
    case 'p':
      current = new Person(stringToInt(ssn),stringToInt(DOB.substr(0,1)), stringToInt(DOB.substr(2,3)), stringToInt(DOB.substr(4,7)), cleaned, lastName);
      break;
    case 's':

      cout << "What's your student ID?: " << endl;
      cin >> studentID;
      cout << "What classOf are you? (MMYYYY): " << endl;
      cin >> classOf;
      current = new Student(stringToInt(ssn),stringToInt(DOB.substr(0,1)), stringToInt(DOB.substr(2,3)), stringToInt(DOB.substr(4,7)), cleaned, lastName, studentID, stringToInt(classOf.substr(0,1)), stringToInt(classOf.substr(2,5)));
      break;
    case 'f':

      cout << "On what date did you join the faculty? (MMYYYY)" << endl;
      cin >> joinDate;
      current = new Faculty(stringToInt(ssn),stringToInt(DOB.substr(0,1)), stringToInt(DOB.substr(2,3)), stringToInt(DOB.substr(4,7)), cleaned, lastName, stringToInt(joinDate.substr(0,1)), stringToInt(joinDate.substr(2,5)));
      break;
    default:
      cout << "You didn't enter a proper archetype. Exiting...";
  }
  return current;

}

string capitalizeName(string name)
{
  for(int i = 0; i<name.size();i++)
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
bool verifyDOB(string DOB)
{
  int month, day, year;
  month = stringToInt(DOB.substr(0,1));
  day = stringToInt(DOB.substr(2,3));
  year = stringToInt(DOB.substr(4,7));
  return (01 <= month <= 12) && (01 <= day <= 31) && (1887 <= year <= CURRENT_YEAR);
}
