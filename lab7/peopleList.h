#ifndef PEOPLELIST_H
#define PEOPLELIST_H
#include "person.h"
//PeopleList is a list of node structs, with a head and a tail, along with a count of how many nodes there are.
//It's functionality is append to add a node to that instance, and member to help with identification of duplicates.
class PeopleList {
    protected:
        struct PersonNode {
                Person* data;
                PersonNode* next;
        };
        int count;

    public:
        PersonNode *head, *tail;
        PeopleList();
        ~PeopleList();
        void append(Person* data);
        int getNodeSSN();

};
#endif
