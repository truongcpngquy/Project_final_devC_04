#ifndef DATATYPE_H
#define DATATYPE_H
#include <stdbool.h>
typedef struct {
    int day,month,year;
} Date;

typedef struct {
	char transferId[10];
	char receivingId[10];
	double amount;
	char type[10]; // deposit // transfer // withdraw
	char message[50];
//	struct Date transactionDate; 
} Transaction; 

typedef struct {
    char userId[20];
    float balance;
    bool status;
    char userName[10];
	char password[10];
//	struct Transaction transactionHistory[]; 
} AccountInfo;

typedef struct {
    char id[10];
    char name[20];
//    struct DateOfBirth; 
    bool gender;
    char email[20];
    char phone[10];
    
} User;


#endif
