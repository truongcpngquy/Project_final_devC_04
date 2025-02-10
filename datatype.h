#ifndef DATATYPE_H
#define DATATYPE_H
#include <stdbool.h>

typedef struct {
    char id[20];
    char name[50];
    bool gender;
    char phone[15];
    char email[50];
    char username[30];
    char password[10];
    char status[10];
} User;

typedef struct {
    char userId[20];
    float balance;
    bool status;
} AccountInfo;

typedef struct {
    int day;
	int month;
	int year;
} Date;

#endif

