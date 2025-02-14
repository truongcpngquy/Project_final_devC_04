// noi khai bao struct 
#ifndef DATATYPE_H
#define DATATYPE_H
#include <stdbool.h>

struct Date{
    int day, month, year;
};

struct Transaction{
    char transferId[20];
    char receivingId[20];
    double amount;
    char type[20]; // deposit // transfer // withdraw
    char message[50];
    struct Date transactionDate;
};

struct AccountInfo{
    char userId[30];
    float balance;
    bool status;
    char userName[20];
    char password[20];
    struct Transaction transactionHistory[100]; 
};

struct User{
    char id[20];
    char name[30];
    struct Date dateOfBirth;
    int gender; 
    char email[30];
    char phone[30];
    char username[20];
    char password[20];
    char status[20];
    float balance;
};

#endif
