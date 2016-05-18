//person.h
#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
//Super class Person, has attributes SSN, DOB, firstName, lastName
class Person
{
    protected:
        long SSN;

        string firstName;
        string lastName;
   public:
        struct dob{
          int year;
          int month;
          int day;
        }DOB;
        Person(long ssn, int day, int month, int year, string firstName, string lastName);
        //getSSN for filtering into the personLists.
        int getSSN();
        bool checkDOB(int month, int day, int year);
        virtual void printPerson();
        ~Person();
};
//Child faculty has additional encapsulated attribute joinDate.
class Faculty : public Person
{
    protected:
        struct{
            int month;
            int year;
        }joinDate;
    public:
        Faculty(long ssn, int day, int month, int year, string firstName, string lastName, int joinMonth, int joinYear);
        virtual void printPerson();
        ~Faculty();
};
//Child student has additional encapsulated attribute classOf, along with an integer representing studentID.
//Along with corresponding accessor methods.

class Student : public Person
{
    protected:
        int studentID;
        struct{
            int month;
            int year;
        }classOf;
    public:
        Student(long ssn, int day, int month, int year, string firstName, string lastName, int studentID, int classMonth, int classYear);
        virtual void printPerson();
        ~Student();

};
#endif
