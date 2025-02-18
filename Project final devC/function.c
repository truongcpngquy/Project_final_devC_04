// noi trien khai ham 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"
#include  "datatype.h"
#define MAX 100 
 
struct User users[MAX]; 
int userCount=0; 

void mainMenu() {			
    int choice;
    while(1) {
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
            case 1:{
            	system("cls");
            	displayUserMenu();
                break;
            }
            case 2:{
            	void clearUserFile();
                printf("This functionality is under development!\n");
                break;
            }
            case 3:{	
                end();
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
            }
        }
    } 
}


void saveUsersToFile() {
    FILE *file = fopen("users.bin", "wb");
    if (file == NULL) {
        printf("coud not open file!\n");
        return;
    }
    fwrite(&userCount, sizeof(int),1,file);
    fwrite(users, sizeof(struct User), userCount, file);
    fclose(file);
}

// Ham doc danh sach nguoi dung tu file
void loadUsersFromFile() {
    FILE *file = fopen("users.bin", "rb");
    if (file == NULL) {
        printf("coud not open file.\n");
        return;
    }
    fread(&userCount, sizeof(int),1,file);
    fread(users, sizeof(struct User), MAX, file);
    fclose(file);
    
}



void displayUserMenu() {	
    int choice;
    while(1) {
    	
        printf("***Student Management System Using C***\n\n");
        printf("%16s%4s\n", " ", "Menu");
        printf("%9s%24s\n", " ", "========================");
        printf("%8s%14s\n", " ", "[1] Add user.");
        printf("%8s%19s\n", " ", "[2] Show All user.");
        printf("%8s%25s\n", " ", "[3] Search user by name.");
        printf("%8s%25s\n", " ", "[4] Show detail an user.");
        printf("%8s%22s\n", " ", "[5] Lock/Unlock user.");
        printf("%8s%23s\n", " ", "[6] Sort user by name.");
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
			case 0:{
				system("cls");
				mainMenu();
				break;
			} 
        }
    } 
}


void addUser() {
    if (userCount >= MAX) {
        printf("Cannot add more users.\n");
        return;
    }

    struct User newUser;
    char conflictField[30];
    //nhap ID
    do {
    	nhaplai:
        printf("Enter the ID: ");
        scanf("%s", newUser.id);
        while(getchar() != '\n'); 
		if(strlen(newUser.id) !=10 ){
            printf("Error: ID can not be less than 10 character!\n");
            goto nhaplai;
        }else{
            if (isDuplicateUser(users, userCount, newUser, conflictField)){
                if(strcmp(conflictField, "ID") == 0){
                    printf("Id %s already exists!\n\n", newUser.id);
                }
            }    
        }
	} while (isDuplicateUser(users, userCount, newUser, conflictField) && strcmp(conflictField, "ID") == 0);
	printf("Enter the name: ");
	gets(newUser.name);
    //nhap email
    do{
        printf("Enter the email: ");
        scanf("%s", newUser.email);
        if(isDuplicateUser(users, userCount, newUser, conflictField)  ){
            if(strcmp(conflictField, "Email") == 0){
                printf("Email. %s already exists!\n",newUser.email);
            }
        }
    } while (isDuplicateUser(users, userCount, newUser, conflictField) && strcmp(conflictField, "Email") == 0);
    //nhap sdt
      do {
    	nhaplai1:
        printf("Enter the Phone: ");
        scanf("%s", newUser.phone);
        while(getchar() != '\n'); 
		if(strlen(newUser.phone) !=10 ){
            printf("Error: Phone number can not be less than 10 character!\n");
            goto nhaplai1;
        }else{
            if (isDuplicateUser(users, userCount, newUser, conflictField)){
                if(strcmp(conflictField, "Phone") == 0){
                    printf("phone number %s already exists!\n\n", newUser.phone);
                }
            }    
        }
	} while (isDuplicateUser(users, userCount, newUser, conflictField) && strcmp(conflictField, "Phone") == 0);

    //nhap birthday
    printf("Enter the gender(Male: 1/Female: 0): ");
    scanf("%d",&newUser.gender);
    printf("Enter the day of birth\n");
    printf("%2s%16s"," ","Enter the day: ");
    scanf("%d", &newUser.dateOfBirth.day);
    printf("%2s%18s"," ","Enter the month: ");
    scanf("%d", &newUser.dateOfBirth.month);
    printf("%2s%17s"," ","Enter the year: ");
    scanf("%d", &newUser.dateOfBirth.year);

    //nhap username
    do{
        printf("Enter the username: ");
        scanf("%s", newUser.username);
        if(isDuplicateUser(users, userCount, newUser, conflictField)){
            if(strcmp(conflictField, "Username") == 0){
                printf("User %s already exists!\n",newUser.username);
            }
        }
    } while (isDuplicateUser(users, userCount, newUser, conflictField) && strcmp(conflictField, "Username") == 0);


    printf("Enter the balance: ");
	scanf("%f",&newUser.balance); 
    strcpy(newUser.password, newUser.phone);
    strcpy(newUser.status, "open");

    users[userCount++] = newUser;
    saveUsersToFile();
    printf("\nUser added successfully.\n");
    
}

void showUserList() {		  
    printf("\n");
    printf("***User List****\n");
    printf("+======================|======================|===========================|===============|===========+\n");
    printf("| %-20s | %-20s | %-25s | %-11s   | %-8s  |\n", "ID", "Name", "Email", "Phone", "Status");
    printf("+======================|======================|===========================|===============|===========+\n");
	int i=0; 
    for (i ; i < userCount; i++) {
        printf("| %-20s | %-20s | %-25s |  %-11s  |  %-8s |\n",users[i].id, users[i].name, users[i].email, users[i].phone, users[i].status);
        printf("+----------------------|----------------------|---------------------------|---------------|-----------+\n");
	}	
}

void searchUserByName() {
    char searchName[50];
    printf("\nEnter user name : ");
    gets(searchName);

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
    int i;
    
    for (i = 0; i < userCount; i++) {
        if (strcmp(users[i].id, searchId) == 0) {
            found = 1;
            
            printf("+==========================================+\n");
            printf("| %-14s | %-23s |\n", "Field", "Value");
            printf("|==========================================|\n");
            printf("| %-14s | %-23s |\n", "ID", users[i].id);
            printf("| %-14s | %-23s |\n", "Name", users[i].name);
            printf("| %-14s | %02d-%02d-%04d              |\n", "Date of Birth", users[i].dateOfBirth.day, users[i].dateOfBirth.month, users[i].dateOfBirth.year);
            printf("| %-14s | %-23s |\n", "Gender", users[i].gender ? "Male" : "Female");
            printf("| %-14s | %-23s |\n", "Email", users[i].email);
            printf("| %-14s | %-23s |\n", "Phone", users[i].phone);
            printf("| %-14s | %-23s |\n", "Username", users[i].username);
            printf("| %-14s | %-23.2f |\n", "Balance", users[i].balance);
            printf("| %-14s | %-23s |\n", "Status", users[i].status);
            printf("+==========================================+\n");
            
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

    printf("\nEnter user ID: ");
    scanf("%s", searchId);

    int found = 0;
    int i=0; 
    for (i ; i < userCount; i++) {
        if (strcmp(users[i].id, searchId) == 0) {
            found = 1;
            printf("Current status: %s\n", users[i].status);

            int choice;
            if (strcmp(users[i].status, "open") == 0) {
                printf("Do you want to lock this user? (1 = Yes, 0 = No): ");
                scanf("%d", &choice);
                if (choice == 1) {
                    strcpy(users[i].status, "Locked");
                    printf("User with ID '%s' has been locked.\n", searchId);
                } else {
                    printf("Action canceled.\n");
                }
            } else if (strcmp(users[i].status, "Locked") == 0) {
                printf("Do you want to unlock this user? (1 = Yes, 0 = No): ");
                scanf("%d", &choice);
                if (choice == 1) {
                    strcpy(users[i].status, "open");
                    printf("User with ID '%s' has been unlocked.\n", searchId);
                } else {
                    printf("Action canceled.\n");
                }
            }

            
            saveUsersToFile();
            return;
        }
    }

    if (found==0) {
        printf("User with ID '%s' not found.\n", searchId);
    }
}

void sortUsersByName() {
    int i=0, j=0;
    struct User temp;
    int order;

    // Hoi nguoi dung muon sap xep theo thu tu nao
    printf("Enter sorting order(Ascending: 1/Descending: 0) : ");
    scanf("%d", &order);
    if (order == 1) {
        for (i ; i < userCount - 1; i++) {
            for (j ; j < userCount - i - 1; j++) {
                // Sap xep tang dan
                if (strcmp(users[j].name, users[j + 1].name) > 0) {
                    // hoan doi vi tri 
                    temp = users[j];
                    users[j] = users[j + 1];
                    users[j + 1] = temp;
                }
            }
        } 
    }else if(order ==0){
        for (i ; i < userCount - 1; i++) {
            for (j ; j < userCount - i - 1; j++) {
                // sap xep giam dan 
                if (strcmp(users[j].name, users[j + 1].name) < 0) {
                    // hoan doi vi tri 
                    temp = users[j];
                    users[j] = users[j + 1];
                    users[j + 1] = temp;
                }
            }
        }
    }else{
        printf("Invalid sorting order.\n");
        return;
    }
    printf("Sorting completed successfully.\n"); 
}


void goBackOrExit(){
	char choice;
    while (1) {
        printf("Go back (b) or exit (0): ");
        scanf(" %c", &choice);

        if (choice == 'b') {
        	system("cls");
            displayUserMenu();
            return;
        } else if (choice == '0') {
        	system("cls");
            mainMenu();
            return;
        } else {
            printf("Invalid choice! Please choose again.\n");
        }
    }
} 

bool isDuplicateUser(struct User users[], int userCount, struct User newUser, char *conflictField) {
	int i=0;
    for (i ; i < userCount; i++) {
        if (strcmp(users[i].id, newUser.id) == 0) {
            strcpy(conflictField, "ID");
            return true;
        }
        if (strcmp(users[i].phone, newUser.phone) == 0) {
            strcpy(conflictField, "Phone");
            return true;
        }
        if (strcmp(users[i].username, newUser.username) == 0) {
            strcpy(conflictField, "Username");
            return true;
        }
        if (strcmp(users[i].email, newUser.email) == 0) {
            strcpy(conflictField, "Email");
            return true;
        }
    }
    return false;
}

void clearUserFile() {
    FILE *file = fopen("users.bin", "wb"); 
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fclose(file);
    printf("User data has been deleted!\n");

    
    userCount = 0;
}


