#include "peopleList.h"
PeopleList::PeopleList()
{
  PeopleList::head  = (PersonNode*)malloc(sizeof(PersonNode));
  PeopleList::tail  = (PersonNode*)malloc(sizeof(PersonNode));
  PeopleList::count = 0;
}

void PeopleList::append(Person* data)
{
    if(head->data == NULL){
      head->data = data;
      head->next = tail;
      tail->data = data;
    }else{
      PersonNode *current  = (PersonNode*)malloc(sizeof(PersonNode));
      tail->next = current;
      tail->data = data;
    }
    count++;

}

int PeopleList::getNodeSSN()
{
    return tail->data->getSSN();
}

PeopleList::~PeopleList()
{
}
