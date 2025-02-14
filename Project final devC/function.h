// noi dinh nghia ham 
#ifndef FUNCTION_H
#define FUNCTION_H

#include "datatype.h"

// ham menu chinh
void mainMenu();

// ham menu quan ly nguoi dung
void displayUserMenu();

// ham nhap thong tin nguoi dung 
void addUser();

// ham in danh sach nguoi dung 
void showUserList(); 

void searchUserByName();

// ham hien thong tin chi tiet 
void showDetailUser();

// khoa(mo khoa) nguoi dung 
void toggleUserLockStatusByID();

// sap xep nguoi dung 
void sortUsersByName();

// ham ket thuc chuong trinh
void end();


void goBackOrExit();
		    
bool isDuplicateUser();

void saveUsersToFile();

void loadUsersFromFile();

#endif        
