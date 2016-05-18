#include "person.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define interactive
#ifdef programatically
// add hard values in here to test.



#else


int ssnCheck(char *ssn);
int dobCheck(char *dob);

int main(int argc, char *argv[])
{
	FILE *testfile = fopen("testfile.txt", "a+");

	struct Person *PeopleArray[10];

	char firstname[10];
	char lastname[10];
	char ssn[10];
	char dob[10];

	int counter=0;
	while( fscanf(testfile, "%s %s %s %s ", firstname, lastname, ssn, dob) != EOF) {

		PeopleArray[counter] = Person_create(firstname, lastname, ssn, dob);
		printf("%s", PeopleArray[counter]->firstname);
		printf("\n");
		counter++;
	}

	int fileCounter = counter; // number of files loaded
	char nfirstname[20];
	char nlastname[20];
	char nSsn[11];
	char nDob[10];
	char nexit[10];
	int breaker;

	// Loop for entering new persons
	int a;
	for(a=1;a<argc;a++) {
		breaker=0;
		printf("\nDo you wish to enter another name?\n(y or n): ");
		scanf("%s", nexit);
		fflush(stdin);
	// If user selected to enter new names
		if (strcmp(nexit, "y")== 0) {

			strcpy(nfirstname, argv[a]);
			printf("Enter %s's last name: ", nfirstname);
			scanf("%s", nlastname);




			printf("Please provide %s's SSN: ", nfirstname);
			scanf("%s", nSsn);
			if (ssnCheck(nSsn) == 0)
			{
				printf("Wrong SSN format! Entry not added.\n");
				continue;
			}




			printf("Please provide %s's DOB: ", nfirstname);
			scanf("%s", nDob);
			if (dobCheck(nDob) == 0)
			{
				printf("Wrong DOB format! Entry not added.\n");
				continue;
			}






			// checks to see if ssn and dob are the same, if firstname is the same as well. If it is it doesn't allow it, if name isn't the same then we just let the user know.
			int b=0;
			for(b=0; b<counter;b++) {
				if (strcmp( nSsn, PeopleArray[b]->ssn ) == 0 && strcmp( nDob, PeopleArray[b]->dob)==0) {
					if ( strcmp( nfirstname, PeopleArray[b]->firstname ) == 0) {
						printf("This name already exists for a person with the same DOB and SSN! New Person not added.\n");
						breaker = 1;
						break;
						}
					else {
						printf("Just letting you know, that DOB and SSN combo is already used.\n");
						}
					}
				}
			if (breaker!=0) {
				continue;
			}

		PeopleArray[counter] = Person_create(nfirstname, nlastname, nSsn, nDob);
		printf("%s %s %s %s\n", PeopleArray[counter]->firstname, PeopleArray[counter]->lastname, PeopleArray[counter]->ssn, PeopleArray[counter]->dob);
		printf("%s added.\n", nfirstname);
		fflush(stdout);


		}
		else {
			break;
			}
		counter++;
	}



    int c=fileCounter; // Not adding the ones we already read from file
    for(c=fileCounter; c < counter; c++) {
    	fprintf(testfile, "%s %s %s %s \n", PeopleArray[c]->firstname, PeopleArray[c]->lastname, PeopleArray[c]->ssn, PeopleArray[c]->dob);

    }

    int j=0;
    for(j=0; j < counter; j++) {
    	Person_destroy(PeopleArray[j]);
    }

    return 0;
    fclose( testfile );
}

int ssnCheck(char *ssn)
	{
	int d=0;
	for(d=0;d<11;d++)
		{
		if(d!=3 && d!=6)
			{
			if(isdigit(ssn[d])==0)
				{
				return 0;
				}
			}

		}
	if(ssn[3]!= '-')
		{
		return 0;
		}
	if(ssn[6]!= '-')
		{
		return 0;
		}
	return 1;
	}

int dobCheck(char *dob)
	{
	int d=0;
	for(d=0;d<10;d++)
		{
		if(d!=2 && d!=5)
			{
			if(isdigit(dob[d])==0)
				{
				return 0;
				}
			}
		}
	if(dob[2]!= '/')
		{
		return 0;
		}
	if(dob[5]!= '/')
		{
		return 0;
		}
	return 1;
	}

#endif
