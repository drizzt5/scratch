#include "person.h"
#include "peopleList.h"
int main(){
    Person *FOO = new Person(1234,5,20,2016,"Foo", "Bar");
    Person *BAR = new Person(2345,5,20,2016,"Bar", "Foo");
    Person *LUL = new Faculty(3456,5,20,2016,"LUL", "IN 2016?", 5, 2016);
    PeopleList peopleArray[10];
    peopleArray[FOO->getSSN() % 10].append(FOO);
    peopleArray[BAR->getSSN() % 10].append(BAR);
    LUL->printPerson();
    peopleArray[4].head->data->printPerson();
}
