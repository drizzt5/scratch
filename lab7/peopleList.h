#ifndef PEOPLELIST_H
#define PEOPLELIST_H
#include "person.h"
//PeopleList is a list of node structs, with a head and a tail, along with a count of how many nodes there are.
//It's functionality is append to add a node to that instance, and member to help with identification of duplicates.
class PersonNode {
public:
    Person* data;
    PersonNode* next;
    PersonNode(Person* x, PersonNode *p): data(x), next(p) {} ;
};
class PeopleList {

public:
    PersonNode *head, *tail;
    PeopleList();
    ~PeopleList();
    void append(Person* data);
    void printBlock();

};
#endif
