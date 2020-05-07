 //
// APS105 Lab 5 and 6
//
// Program for maintaining a personal phone book.
//
// Uses a linked list to hold the phone book entries.
//
// Author: <Lingwei Sun>
// Student Number: <1004723276>
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

//**********************************************************************
// Linked List Definitions
//  Define your linked list node and pointer types
//  here for use throughout the file.
//
//   ADD STATEMENT(S) HERE
typedef struct Node{
	char *familyName;
	char *firstName;
	char *address;
	char *phoneNumber;
	struct Node *next;
}node;

//**********************************************************************
// Linked List Function Declarations
//
// Functions that modify the linked list.
//   Declare your linked list functions here.
//
//   ADD STATEMENT(S) HERE
node *createNewNode(void);
node *insertData(node *newNode);
node *insertSorted(node *head, node *newNode);
node *deleteEntry(node *head, const char *familyName);
node *searchFamily(node *head, char *familyName);
node *searchPhone(node *head, char *phoneNumber);
void printPhone(node *head);
node *deletPhoneBook(node *head);

//**********************************************************************
// Support Function Declarations
//

void safegets (char s[], int arraySize);        // gets without buffer overflow
void familyNameDuplicate (char familyName[]);   // marker/tester friendly
void familyNameFound (char familyName[]);       //   functions to print
void familyNameNotFound (char familyName[]);    //     messages to user
void familyNameDeleted (char familyName[]);
void phoneNumberFound (char phoneNumber[]);
void phoneNumberNotFound (char phoneNumber[]);
void printPhoneBookEmpty (void);
void printPhoneBookTitle (void);

//**********************************************************************
// Program-wide Constants
//

const int MAX_LENGTH = 1023;
const char NULL_CHAR = '\0';
const char NEWLINE = '\n';

//**********************************************************************
// Main Program
//

int main (void)
{
    const char bannerString[]
        = "Personal Phone Book Maintenance Program.\n\n";
    const char commandList[]
        = "Commands are I (insert), D (delete), S (search by name),\n"
          "  R (reverse search by phone #), P (print), Q (quit).\n";

    // Declare linked list head.
    //   ADD STATEMENT(S) HERE TO DECLARE LINKED LIST HEAD.
	node *phoneBook=NULL;

    // announce start of program
    printf("%s",bannerString);
    printf("%s",commandList);

    char response;
    char input[MAX_LENGTH+1];
    do
    {
        printf("\nCommand?: ");
        safegets(input,MAX_LENGTH+1);
        // Response is first char entered by user.
        // Convert to uppercase to simplify later comparisons.
        response = toupper(input[0]);

        if (response == 'I')
        {
            // Insert an phone book entry into the linked list.
            // Maintain the list in alphabetical order by family name.
            //   ADD STATEMENT(S) HERE
			node *newNode;
			newNode=createNewNode();
			newNode=insertData(newNode);
			phoneBook=insertSorted(phoneBook, newNode);
            // USE THE FOLLOWING PRINTF STATEMENTS WHEN PROMPTING FOR DATA:
            // printf("  family name: ");
            // printf("  first name: ");
            // printf("  address: ");
            // printf("  phone number: ");
        }
        else if (response == 'D')
        {
            // Delete an phone book entry from the list.
            printf("\nEnter family name for entry to delete: ");
			char inputEntry[MAX_LENGTH+1];
			safegets(inputEntry,MAX_LENGTH+1);
            //   ADD STATEMENT(S) HERE
			//node *inputEntryNode;
			//inputEntryNode=searchFamily(phoneBook, inputEntry);
			if (searchFamily(phoneBook, inputEntry)==NULL)
				familyNameNotFound (inputEntry);
			else{
				phoneBook=deleteEntry(phoneBook, inputEntry);
				familyNameDeleted (inputEntry);
			}
        }
        else if (response == 'S')
        {
            // Search for an phone book entry by family name.
            printf("\nEnter family name to search for: ");
			char inputName[MAX_LENGTH+1];
			safegets(inputName,MAX_LENGTH+1);
            //   ADD STATEMENT(S) HERE
			node  *fa;
			if (searchFamily(phoneBook, inputName)==NULL)
				familyNameNotFound (inputName); 
			else{
				fa=searchFamily(phoneBook, inputName);
				familyNameFound (inputName);
				printf("%s\n", fa->familyName);
				printf("%s\n", fa->firstName);
				printf("%s\n", fa->address);
				printf("%s\n", fa->phoneNumber);
			}
        }
        else if (response == 'R')
        {
            // Search for an phone book entry by phone number.
            printf("\nEnter phone number to search for: ");
			char inputNumber[MAX_LENGTH+1];
			safegets(inputNumber,MAX_LENGTH+1);
            //   ADD STATEMENT(S) HERE
			node  *cai;
			if (searchPhone(phoneBook, inputNumber)==NULL)
				phoneNumberNotFound (inputNumber);
			else{
				cai=searchPhone(phoneBook, inputNumber);
				phoneNumberFound (inputNumber);
				printf("%s\n", cai->familyName);
				printf("%s\n", cai->firstName);
				printf("%s\n", cai->address);
				printf("%s\n", cai->phoneNumber);
			}
        }
        else if (response == 'P')
        {
            // Print the phone book.
            //   ADD STATEMENT(S) HERE
		printPhone(phoneBook);
        }
        else if (response == 'Q')
        {
            ; // do nothing, we'll catch this below
        }
        else
        {
            // do this if no command matched ...
            printf("\nInvalid command.\n%s\n",commandList);
        }
    } while (response != 'Q');

    // Delete the whole phone book linked list.
    //   ADD STATEMENT(S) HERE
	phoneBook=deletPhoneBook(phoneBook);
    // Print the linked list to confirm deletion.
    //   ADD STATEMENT(S) HERE
	printPhone(phoneBook);

    return 0;
}

//**********************************************************************
// Support Function Definitions

// Function to get a line of input without overflowing target char array.
void safegets (char s[], int arraySize)
{
    int i = 0, maxIndex = arraySize-1;
    char c;
    while (i < maxIndex && (c = getchar()) != NEWLINE)
    {
        s[i] = c;
        i = i + 1;
    }
    s[i] = NULL_CHAR;
}

// Function to call when user is trying to insert a family name
// that is already in the book.
void familyNameDuplicate (char familyName[])
{
    printf("\nAn entry for <%s> is already in the phone book!\n"
           "New entry not entered.\n",familyName);
}

// Function to call when a family name was found in the phone book.
void familyNameFound (char familyName[])
{
    printf("\nThe family name <%s> was found in the phone book.\n",
             familyName);
}

// Function to call when a family name was not found in the phone book.
void familyNameNotFound (char familyName[])
{
    printf("\nThe family name <%s> is not in the phone book.\n",
             familyName);
}

// Function to call when a family name that is to be deleted
// was found in the phone book.
void familyNameDeleted (char familyName[])
{
    printf("\nDeleting entry for family name <%s> from the phone book.\n",
             familyName);
}

// Function to call when a phone number was found in the phone book.
void phoneNumberFound (char phoneNumber[])
{
    printf("\nThe phone number <%s> was found in the phone book.\n",
             phoneNumber);
}

// Function to call when a phone number was not found in the phone book.
void phoneNumberNotFound (char phoneNumber[])
{
    printf("\nThe phone number <%s> is not in the phone book.\n",
             phoneNumber);
}

// Function to call when printing an empty phone book.
void printPhoneBookEmpty (void)
{
    printf("\nThe phone book is empty.\n");
}

// Function to call to print title when whole phone book being printed.
void printPhoneBookTitle (void)
{
    printf("\n  My Personal Phone Book: \n");
}

//**********************************************************************
// Add your functions below this line.
//   ADD STATEMENT(S) HERE
// 3 functions for Insert an phone book entry into the linked list.
node *createNewNode(void){
	node *newNode;
	newNode=(node*)calloc(1,sizeof(node));
	newNode->next=NULL;
	newNode->familyName=(char*)calloc(MAX_LENGTH, sizeof(char));
	newNode->firstName=(char*)calloc(MAX_LENGTH, sizeof(char));
	newNode->address=(char*)calloc(MAX_LENGTH, sizeof(char));
	newNode->phoneNumber=(char*)calloc(MAX_LENGTH, sizeof(char));
	return newNode;
}

node *insertData(node *newNode){
	char input[MAX_LENGTH+1];
	printf("  family name: ");
	safegets(input,MAX_LENGTH+1);
	strcpy(newNode->familyName,input);
	printf("  first name: ");
	safegets(input,MAX_LENGTH+1);
	strcpy(newNode->firstName,input);
	printf("  address: ");
	safegets(input,MAX_LENGTH+1);
	strcpy(newNode->address,input);
	printf("  phone number: ");
	safegets(input,MAX_LENGTH+1);
	strcpy(newNode->phoneNumber,input);
	return newNode;
}

node *insertSorted(node *head, node *newNode){
	node *cur=head, *pre=NULL;
	while (cur!=NULL && (strcmp(newNode->familyName, cur->familyName))>0){
		pre=cur;
		cur=cur->next;
	}
	if (cur!=NULL && (strcmp(newNode->familyName, cur->familyName))==0){
		familyNameDuplicate (cur->familyName);
		free(newNode);
	}
	else{
		newNode->next=cur;
		if(pre==NULL)
			head=newNode;
		else
			pre->next=newNode;
	}
	return head;
}

// Delete an phone book entry from the list.
node *deleteEntry(node *head, const char *familyName){
	node *cur=head, *pre=NULL;
	while (cur!=NULL && (strcmp(cur->familyName, familyName))!=0){
		pre=cur;
		cur=cur->next;
	}
	if(cur!=NULL){
		if (pre!=NULL)
			pre->next=cur->next;
		else
			head=cur->next;
		free(cur);
	}
	return head;
}

// Search for an phone book entry by family name.
node *searchFamily(node *head, char *familyName){
	node *temp;
	temp=head;
	while(temp!=NULL && (strcmp(temp->familyName, familyName))!=0)
		temp=head->next;
	return temp;
}

// Search for an phone book entry by phone number.
node *searchPhone(node *head, char *phoneNumber){
	node *temp;
	temp=head;
	while(temp!=NULL && (strcmp(temp->phoneNumber, phoneNumber))!=0)
		temp=head->next;
	return temp;
}

// Print the phone book.
void printPhone(node *head){
	if (head==NULL)
		printPhoneBookEmpty();
	else{
		while(head!=NULL){
			printPhoneBookTitle ();
			printf("%s\n", head->familyName);
			printf("%s\n", head->firstName);
			printf("%s\n", head->address);
			printf("%s\n", head->phoneNumber);
			head=head->next;
		}
	}
}

// Delete the whole phone book linked list.
node *deletPhoneBook(node *head){
	node *temp;
	while (head!=NULL){
		temp=head;
		head=head->next;
		free(temp);
	}
	return head;
}