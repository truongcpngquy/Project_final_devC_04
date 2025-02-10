#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"

struct User users[100];
int userCount = 0;

void mainMenu() {
    int choice;
    do {
        printf("***Bank Management System Using C***\n\n");
        printf("%8s%17s\n"," ","CHOOSE YOUR ROLE");
        printf("%5s%24s\n"," ","========================");
        printf("%4s%11s\n"," ","[1] Admin.");
        printf("%4s%10s\n"," ","[2] User.");
        printf("%4s%22s\n"," ","[3] Exit the program.");
        printf("%5s%24s\n"," ","========================");
        printf("%4s%20s"," ","Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                displayUserMenu();
                break;
            case 2:
//                printf("");
                break;
            case 3:
                end();
                break;
            default:
                printf("Lua chon khong hop le! Vui long chon lai\n");
        }
    } while (choice != 3);
}

void end() {
    printf("========= Thank You =========\n");
    printf("========= See You Soon ======\n\n");
    printf("--------------------------------\n");
}

void displayUserMenu() {
    int choice;
    do {
        printf("***Student Management System Using C***\n\n");
        printf("%16s%4s\n", " ", "Menu");
        printf("%9s%24s\n", " ", "========================");
        printf("%8s%20s\n", " ", "[1] Add A New user.");
        printf("%8s%19s\n", " ", "[2] Show All user.");
        printf("%8s%25s\n", " ", "[3] Show detail an user.");
        printf("%8s%20s\n", " ", "[4] User Guideline.");
        printf("%8s%14s\n", " ", "[5] About us.");
        printf("%8s%10s\n", " ", "[0] Exit.");
        printf("%9s%24s\n", " ", "========================");
        printf("%8s%20s", " ", "Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                addUser();
                break;
            case 2:
                showUserList();
                break;
        }
    } while (choice != 0);
}

void showUserList() {
    printf("\n");
    printf("===================================================================================================\n");
    printf("| %-20s | %-20s | %-25s | %-11s | %-8s|\n", "ID", "Name", "Email", "Phone", "Status");
    printf("===================================================================================================\n");
	int i=0; 
    for (i; i < userCount; i++) {
        printf("| %-20s | %-20s | %-25s | %-11s | %-8s|\n",
               users[i].id, users[i].name, users[i].email, users[i].phone, users[i].status);
        printf("---------------------------------------------------------------------------------------------------\n");
    }
}


void addUser() {
    if (userCount >= 100) {
        printf("Cannot add more users.\n");
        return;
    }
    struct User newUser;
    printf("Enter the ID: ");
    scanf("%s", newUser.id);
    printf("Enter the name: ");
    scanf("%s", newUser.name);
    printf("Enter the email: ");
    scanf("%s", newUser.email);
    printf("Enter the phone: ");
    scanf("%s", newUser.phone);
    printf("Enter the gender(Male: 1/Female: 0): ");
    scanf("%d",&newUser.gender);
    printf("Enter the day of birth\n");
    printf("%2s%16s"," ","Enter the day: ");
    scanf("%d", &newUser.dateOfBirth.day);
    printf("%2s%18s"," ","Enter the month: ");
    scanf("%d", &newUser.dateOfBirth.month);
    printf("%2s%17s"," ","Enter the year: ");
    scanf("%d", &newUser.dateOfBirth.year);
    printf("Enter the username: ");
    scanf("%s", newUser.username);
    printf("Enter the balance: ");
	scanf("%f",&newUser.balance); 
    strcpy(newUser.password, newUser.phone);
    strcpy(newUser.status, "open");

    users[userCount++] = newUser;
    printf("User added successfully.\n");
}

