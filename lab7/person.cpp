#include "person.h"
//Person block of definitions
Person::Person(int ssn, int day, int month, int year, string firstName, string lastName)
{
    Person::SSN = ssn;
    Person::firstName = firstName;
    Person::lastName = lastName;
    Person::DOB.day = day;
    Person::DOB.month = month;
    Person::DOB.year = year;
}
void Person::printPerson()
{
  //TODO: Simplify using formatted printing
  cout << firstName << " " << lastName << ": SSN: " << SSN << " DOB: " << DOB.month << "/" << DOB.day << "/" << DOB.year << endl;
}
int Person::getSSN()
{
  return Person::SSN;
}
//Faculty block of definitions
Faculty::Faculty(int ssn, int day, int month, int year, string firstName, string lastName, int joinMonth, int joinYear) : Person(ssn, day, month, year, firstName, lastName)
{
    Faculty::joinDate.month = joinMonth;
    Faculty::joinDate.year = joinYear;
}
void Faculty::printPerson()
{
  //TODO: Simplify using formatted printing
  cout << firstName << " " << lastName << ": SSN: " << SSN << " DOB: " << DOB.month << "/" << DOB.day << "/" << DOB.year << " Joined: " << joinDate.month << "/" << joinDate.year << endl;
}
//Student block of definitions
Student::Student(int ssn, int day, int month, int year, string firstName, string lastName, int studentID, int classMonth, int classYear) : Person(ssn, day, month, year, firstName, lastName)
{
    Student::classOf.month = classMonth;
    Student::classOf.year = classYear;
}
void Student::printPerson()
{
  //TODO: Simplify using formatted printing
  cout << firstName << " " << lastName << ": SSN: " << SSN << " DOB: " << DOB.month << "/" << DOB.day << "/" << DOB.year << " Student ID:" << studentID << " Class of: " << classOf.month << "/" << classOf.year <<endl;
}
//Destructors
Person::~Person()
{
}
Faculty::~Faculty()
{
}
Student::~Student()
{
}