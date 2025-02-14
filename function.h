// noi dinh nghia ham 
#ifndef FUNCTION_H
#define FUNCTION_H

#include "datatype.h"

// ham menu chinh
void mainMenu();

// ham ket thuc chuong trinh
void end();

// ham menu quan ly nguoi dung
void displayUserMenu();

// ham in danh sach nguoi dung 
void showUserList(); 

// ham nhap thong tin nguoi dung 
void addUser();

// ham hien thong tin chi tiet 
void showDetailUser();

void searchUser();

void toggleUserLockStatusByID();

void sortUsersByName();

void goBackOrExit();
		        				  

#endif        
