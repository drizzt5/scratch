#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char *firstname;
	char *lastname;
    char *ssn;
    char *dob;
};

struct Person *Person_create(char *firstname, char *lastname, char *ssn, char *dob)
{
    struct Person *who = malloc(sizeof(struct Person));
    assert(who != NULL);

    who->firstname = strdup(firstname);
    who->lastname = strdup(lastname);
    who->ssn = strdup(ssn);
    who->dob = strdup(dob);

    return who;
}

void Person_destroy(struct Person *who)
{
    assert(who != NULL);

    free(who->firstname);
    free(who);
}

void Person_print(struct Person *who)
{
	printf("First Name: %s\n", who->firstname);
    printf("Last Name: %s\n", who->lastname);
    printf("\tSSN: %s\n", who->ssn);
    printf("\tDate Of Birth: %s\n", who->dob);
}
