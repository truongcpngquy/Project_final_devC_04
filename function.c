// noi trien khai ham 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"
#include"datatype.h"
#define MAX 100 
 
struct User users[MAX]; 
int userCount=0; 

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
                printf("This functionality is under development!\n");
                break;
            case 3:
                end();
                break;
            default:
                printf("Lua chon khong hop le! Vui long chon lai\n");
        }
    } while (choice != 3);
}

void displayUserMenu() {	
    int choice;
    do {
    	system("cls"); 
        printf("***Student Management System Using C***\n\n");
        printf("%16s%4s\n", " ", "Menu");
        printf("%9s%24s\n", " ", "========================");
        printf("%8s%14s\n", " ", "[1] Add user.");
        printf("%8s%19s\n", " ", "[2] Show All user.");
        printf("%8s%25s\n", " ", "[3] Search user by name.");
        printf("%8s%25s\n", " ", "[4] Show detail an user.");
        printf("%8s%14s\n", " ", "[5] About us.");
        printf("%8s%25s\n", " ", "[6] Search user by name.");
        printf("%8s%10s\n", " ", "[0] Exit.");
        printf("%9s%24s\n", " ", "========================");
        printf("%8s%20s", " ", "Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:{
            	system("cls");
                addUser();
                goBackOrExit();
                break;
            }
            case 2:{
            	system("cls");
                showUserList();
                goBackOrExit();
                break;
            }
            case 3:{
            	system("cls"); 
	        	searchUserByName(); 
	        	goBackOrExit();
				break;
			}
			case 4:{
				system("cls");
				showDetailUser();
				goBackOrExit();
				break;
			}
			case 5:{
				system("cls");
				toggleUserLockStatusByID();
				goBackOrExit();
				break;
			} 
			case 6:{
				system("cls");
				sortUsersByName();
				goBackOrExit();
				break;
			} 
        }
    } while (choice != 0);
}

void addUser() {
    if (userCount >= MAX) {
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
    printf("\nUser added successfully.\n");\
    
}

void showUserList() {		  
    printf("\n");
    printf("+======================|======================|===========================|===============|===========+\n");
    printf("| %-20s | %-20s | %-25s | %-11s   | %-8s  |\n", "ID", "Name", "Email", "Phone", "Status");
    printf("+======================|======================|===========================|===============|===========+\n");
	int i=0; 
    for (i; i < userCount; i++) {
        printf("| %-20s | %-20s | %-25s |  %-11s  |  %-8s |\n",users[i].id, users[i].name, users[i].email, users[i].phone, users[i].status);
        printf("+----------------------|----------------------|---------------------------|---------------|-----------+\n");
	}	
}

void searchUserByName() {
    char searchName[50];
    printf("\nEnter user name : ");
    scanf("%49s", searchName);

    int found = 0;
    printf("\nSearch Results:\n");
    printf("+======================|======================|===========================|===============|===========+\n");
    printf("| %-20s | %-20s | %-25s | %-11s   | %-8s  |\n", "ID", "Name", "Email", "Phone", "Status");
    printf("+======================|======================|===========================|===============|===========+\n");
	int i=0; 
    for (i; i < userCount; i++) {
        if (strstr(users[i].name, searchName)) {
            printf("| %-20s | %-20s | %-25s |  %-11s  |  %-8s |\n",users[i].id, users[i].name, users[i].email, users[i].phone, users[i].status);
        printf("+----------------------|----------------------|---------------------------|---------------|-----------+\n");
            found = 1;
        }
    }

    if (!found) {
        printf("No users found with the given name.\n");
    }
    
}

void showDetailUser(){
    char searchId[20];
    printf("\nEnter user ID : ");
    scanf("%s", searchId);

    int found = 0;
    int i = 0;
    for (i; i < userCount; i++) {
        if (strcmp(users[i].id, searchId) == 0) {
            found = 1;
            
            printf("ID:            %s \n", users[i].id);
            printf("Name:          %s \n", users[i].name);
            printf("Date of Birth: %02d-%02d-%04d                   \n", users[i].dateOfBirth.day, users[i].dateOfBirth.month, users[i].dateOfBirth.year);
            printf("Gender:        %s \n", users[i].gender ? "Male" : "Female");
            printf("Email:         %s \n", users[i].email);
            printf("Phone:         %s \n", users[i].phone);
            printf("Username:      %s \n", users[i].username);
            printf("Balance:       %f \n", users[i].balance);
            printf("Status:        %s \n", users[i].status);
            
            break;
        }
    }

    if (!found) {
        printf("User with ID '%s' not found.\n", searchId);
    }

    
}

void end() {		 
    printf("========= Thank You =========\n");
    printf("========= See You Soon ======\n\n");
    printf("--------------------------------\n");
    exit(0); 
}

void toggleUserLockStatusByID() {
    char searchId[20];
    int action;

    printf("\nEnter user ID: ");
    scanf("%s", searchId);

    // Find the user
    int found = 0;
    int i=0; 
    for (i ; i < userCount; i++) {
        if (strcmp(users[i].id, searchId) == 0) {
            found = 1;

            // Display current status for clarity
            printf("Current status: %s\n", users[i].status);

            // Get the action from the user
             while(1){
                printf("Enter action (1 to lock, 0 to unlock): ");
                scanf("%d", &action);
                if(action == 0 || action == 1) break;
                else printf("Invalid action. Please enter 0 or 1.\n");
            }

            if (action == 1) {
                strcpy(users[i].status, "Locked");
                printf("User with ID '%s' has been locked.\n", searchId);
            } else if (action == 0) {
                strcpy(users[i].status, "open");  // Or "Open", whichever you prefer
                printf("User with ID '%s' has been unlocked.\n", searchId);
            } 
            break; // Important: Exit the loop once the user is found and updated
        }
    }

    if (!found) {
        printf("User with ID '%s' not found.\n", searchId);
    }
}

void sortUsersByName() {
    int i, j;
    struct User temp;
    int order;

    // Hoi nguoi dung muon sap xep theo thu tu nao
    printf("Enter sorting order (1 for ascending, 0 for descending): ");
    scanf("%d", &order);

    for (i = 0; i < userCount - 1; i++) {
        for (j = 0; j < userCount - i - 1; j++) {
            if (order == 1) {
                // Sap xep tang dan
                if (strcmp(users[j].name, users[j + 1].name) > 0) {
                    // hoan doi vi tri 
                    temp = users[j];
                    users[j] = users[j + 1];
                    users[j + 1] = temp;
                }
            } else if (order == 0) {
                // sap xep giam dan 
                if (strcmp(users[j].name, users[j + 1].name) < 0) {
                    // hoan doi vi tri 
                    temp = users[j];
                    users[j] = users[j + 1];
                    users[j + 1] = temp;
                }
            } else {
                printf("Invalid sorting order.\n");
                return;
            }
        }
    }
}

void goBackOrExit(){
	char choice;
    while (1) {
        printf("Go back (b) or exit (0): ");
        scanf(" %c", &choice);

        if (choice == 'b') {
            displayUserMenu();
            return;
        } else if (choice == '0') {
            mainMenu();
            return;
        } else {
            printf("Invalid choice! Please choose again.\n");
        }
    }
} 
