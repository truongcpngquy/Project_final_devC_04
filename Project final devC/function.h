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

// ham tim kiem nguoi dung bang ten  
void searchUserByName();

// ham hien thong tin chi tiet 
void showDetailUser();

// khoa(mo khoa) nguoi dung 
void toggleUserLockStatusByID();

// sap xep nguoi dung 
void sortUsersByName();

// ham ket thuc chuong trinh
void end();

// ham thoat 
void goBackOrExit();

//ham kiem tra trung lap
bool isDuplicateUser();

// ham luu thong tin nguoi dung
void saveUsersToFile();

// ham doc file
void loadUsersFromFile();

//ham doc file thong tin admin 
void loadAdminFrormFile(); 

//ham dang nhap admin 
void isAdmin(); 

// ham dang nhap user 
void loginUser();
#endif        
