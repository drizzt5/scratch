#include "peopleList.h"
PeopleList::PeopleList()
{
  PeopleList::head  = NULL;
  PeopleList::tail  = NULL;
}

void PeopleList::append(Person* data)
{
  PersonNode *current  = new PersonNode(data, NULL);
  if (head == NULL) {
    head = current;
    tail = current;
  } else {
    tail->next = current;
    tail = current;
  }
}
void PeopleList::printBlock()
{

}
PeopleList::~PeopleList()
{
  PersonNode* old = head;
  while (old != NULL) {
    delete old->data;
    PersonNode* temp = old->next;
    delete old;
    old = temp;
  }
}
