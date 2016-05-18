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

long PeopleList::getNodeSSN()
{
    return tail->data->getSSN();
}

void PeopleList::printBlock()
{
  while(head->data != NULL){
    head->data->printPerson();
    head = head->next;
  }
}
PeopleList::~PeopleList()
{
  int i = 0;
  PersonNode *old;
  while(i < count){
    old = head;
    head = head->next;
    free(old);
    i++;
  }
  free(tail);
}
