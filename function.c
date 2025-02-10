#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"

User users[100];
int userCount = 0;

void mainMenu() {
    int choice;
    do {
        printf("***Bank management system using C***\n\n");
        printf("%8s%17s\n"," ","CHOOSE YOUR ROLE");
        printf("%5s%24s\n"," ", "========================");
        printf("%5s%11s\n"," ","[1] Admin.");
        printf("%5s%10s\n"," ","[2] User.");
        printf("%5s%22s\n"," ","[3] Exit the program.");
        printf("%5s%24s\n"," ","========================");
        printf("%5s%20s"," ","Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                displayUserMenu();
                break;
            case 2:
                printf("User menu is under development.\n");
                break;
            case 3:
                end();
                break;
            default:
                printf("Invalid choice. Please try again!\n");
        }
    } while (choice != 3);
}

void end() {
    printf("========= Thank You =========\n");
    printf("========= See You Soon ======\n\n");
    printf("--------------------------------");
}

void displayUserMenu() {
    int choice;
    do {
        printf("***Student Management System Using C***\n\n");
        printf("%16s%4s\n"," ","Menu");
        printf("%5s%24s\n"," ","========================");
        printf("%7s%20s\n"," ","[1] Add A New user.");
        printf("%7s%19s\n"," ","[2] Show All user.");
        printf("%7s%25s\n"," ","[3] Show detail an user.");
        printf("%7s%16s\n"," ","[4] Add a user.");
        printf("%7s%20s\n"," ","[5] User Guideline.");
        printf("%7s%14s\n"," ","[6] About us.");
        printf("%7s%10sn\n"," ","[0] Exit.");
        printf("%5s%24s\n"," ","========================");
        printf("%5s%20s"," ","Enter your choice: ");
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
    printf("=========================================================================================\n");
    printf("| %-12s | %-20s | %-25s | %-11s | %-2s|\n", "ID", "Name", "Email", "Phone", "Status");
    printf("=========================================================================================\n");
    int i=0; 
     for ( i ; i < userCount; i++) {
        printf("| %-12s | %-20s | %-25s | %-11s | %-3s  |\n",users[i].id, users[i].name, users[i].email, users[i].phone, users[i].status);
        printf("-----------------------------------------------------------------------------------------\n");
    }
}

void addUser() {
    if (userCount >= 100) {
        printf("Cannot add more users.\n");
        return;
    }
    User newUser;
    printf("Enter the ID: ");
    scanf("%s", newUser.id);
    printf("Enter the name: ");
    scanf("%s", newUser.name);
    printf("Enter the phone: ");
    scanf("%s", newUser.phone);
    printf("Enter the email: ");
    scanf("%s", newUser.email);
    printf("Enter the username: ");
    scanf("%s", newUser.username);
    strcpy(newUser.password, newUser.phone);
    strcpy(newUser.status, "open");
		 
    users[userCount++] = newUser;
    printf("User added successfully.\n");
}

