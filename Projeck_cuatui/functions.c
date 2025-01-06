#include <stdio.h>
#include "functions.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void roleMenu(){
	printf("***Student Management System Using C***\n\n");
	printf("\tCHOOSE YOUR ROLE\n");
	printf("================================\n");
	printf("[1] Admin\n");
	printf("[2] Student\n");
	printf("[3] Teacher\n");
	printf("[0] Exit The Program\n");
	printf("================================\n");
}

void login(){
	char email[16];
	char password[9];
	system("cls");
	do{
		
		printf("***Student Management System Using C***\n\n");
		printf("\t    LOGIN\n");
		printf("\n================================\n");
		fflush(stdin);
		printf("Email: ");
		fgets(email, sizeof(email), stdin);
		email[strcspn(email, "\n")] = '\0';
		fflush(stdin);
		printf("Password: ");
		fgets(password, sizeof(password), stdin);
		password[strcspn(password, "\n")] = '\0';
		system("cls");
		if(strcmp(password,"password")!=0 || strcmp(email,"admin@gmail.com")!=0){
			printf("\n*wrong Email Or Password! Please Try Again*\n");
		}
	}while(strcmp(password,"password")!=0 || strcmp(email,"admin@gmail.com")!=0);
}

void manageMenu(){
	printf("***Student Management System Using C***\n\n");
	printf("\t     MENU\n");
	printf("================================\n");
	printf("[1] Students Mangement\n");
	printf("[2] Classrooms Management\n");
	printf("[3] Teachers Management\n");
	printf("[0] Back\n");
	printf("================================\n");
}

void studentMenu(){
	printf("***Student Management System Using C***\n\n");
	printf("\t STUDENT MENU\n");
	printf("================================\n");
	printf("[1] Add A New Student\n");
	printf("[2] Show All Students\n");
	printf("[3] Search A Student\n");
	printf("[4] Edit A Student\n");
	printf("[5] Delete A Student\n");
	printf("[6] Sort Students By Name\n");
	printf("[0] Back\n");
	printf("================================\n");
}

void inputStudent(Student student[], int *length) {
    int count, checkstr;
    printf("\t***Add A New Student***\n\n");
    getchar();
    do {
        count = 0;
        printf("Enter Student's ID: ");
        scanf("%d", &student[*length].studentId);
        for (int i = 0; i < *length; i++) {
            if (student[i].studentId == student[*length].studentId) {
                count++;
            }
        }
        if (count != 0 || student[*length].studentId < 1) {
            printf("\n*Error, Please Try Again*\n\n");
        }
    } while (count != 0 || student[*length].studentId < 1);
    getchar();

    do {
        checkstr = 0;
        printf("Enter Student's Full Name: ");
        fgets(student[*length].name, 30, stdin);
        student[*length].name[strcspn(student[*length].name, "\n")] = '\0';
        for (int i = 0; i < strlen(student[*length].name); i++) {
            if (isalpha(student[*length].name[i]) == 0 && student[*length].name[i] != ' ') {
                checkstr++;
            }
        }
        if (student[*length].name[0] == '\0' || checkstr != 0) {
            printf("\n*Error, Please Try Again*\n\n");
        }
    } while (student[*length].name[0] == '\0' || checkstr != 0);

    do {
        printf("Enter Student's Classroom ID: ");
        fgets(student[*length].classroomId, 5, stdin);
        student[*length].classroomId[strcspn(student[*length].classroomId, "\n")] = '\0';
        if (student[*length].classroomId[0] == '\0') {
            printf("\n*Error, Please Try Again*\n\n");
        }
    } while (student[*length].classroomId[0] == '\0');  // Lo?i b? ki?m tra isdigit không c?n thi?t

    do {
        count = 0;
        printf("Enter Student's Email: ");
        fgets(student[*length].email, 35, stdin);
        student[*length].email[strcspn(student[*length].email, "\n")] = '\0';
        for (int i = 0; i < *length; i++) {
            if (strcmp(student[i].email, student[*length].email) == 0) {
                count++;
            }
        }
        if (count != 0 || student[*length].email[0] == '\0') {
            printf("\n*Error, Please Try Again*\n\n");
        }
    } while (count != 0 || student[*length].email[0] == '\0');

    do {
        count = 0;
        printf("Enter Student's Phone Number: ");
        fgets(student[*length].phoneNumber, 15, stdin);
        student[*length].phoneNumber[strcspn(student[*length].phoneNumber, "\n")] = '\0';
        for (int i = 0; i < *length; i++) {
            if (strcmp(student[i].phoneNumber, student[*length].phoneNumber) == 0) {
                count++;
            }
        }
        if (count != 0 || student[*length].phoneNumber[0] == '\0') {
            printf("\n*Error, Please Try Again*\n\n");
        }
    } while (count != 0 || student[*length].phoneNumber[0] == '\0');

    printf("\n*Student Added Successfully*\n");
    (*length)++;
}

void printStudent(Student student[], int length){
	printf("\t**ALL STUDENTS**\n\n");
	printf("|=======|========================|==============|============================|==================|\n");
	printf("|  ID   |         Name           | classroomId  |           Email            |     PhoneNumber  |\n");
	printf("|=======|========================|==============|============================|==================|\n");
	for(int i=0; i<length; i++){
		printf("| %-5d | %-22s | %-12s | %-26s | %-16s |\n", 
		student[i].studentId,
		student[i].name,
		student[i].classroomId,
		student[i].email,
		student[i].phoneNumber);
		printf("|=======|========================|==============|============================|==================|\n");
	}
}

void editStudent(Student student[], int length){
	int find, found, count=0;
	printf("***EDIT STUDENT INFORMATION***\n\n");
	printf("Enter Student ID: ");
	scanf("%d", &find);
	found=-1;
	for(int i=0;i<length; i++){
		if(student[i].studentId==find){
			found=i;
		}
	}
	if(found==-1){
		printf("\n*Can't Find Student With This ID*\n");
	} else{
		printf("      STUDENT INFORMATION\n");
		printf("================================\n");
		printf("ID: %d\n", student[found].studentId);
		printf("Classroom ID: %s\n", student[found].classroomId);
		printf("Full Name: %s\n", student[found].name);
		printf("Email: %s\n", student[found].email);
		printf("Phone Number: %s\n", student[found].phoneNumber);
		printf("\n***UPDATE INFORMATION***\n\n");
		getchar();
		do{
			count=0;
			printf("Enter Student's ID: ");
			scanf("%d", &student[found].studentId);
			for(int i=0; i<length; i++){
				if((i != found && student[i].studentId == student[found].studentId)){
					count++;
				}
			}
			if(count>0 || student[found].studentId<1){
				printf("\n*Error, Please Try Again*\n\n");
			}
		}while(count>0 || student[found].studentId<1);
		getchar();
		do{
			printf("Enter Student's Full Name: ");
			fgets(student[found].name,30,stdin);
			student[found].name[strcspn(student[found].name,"\n")]='\0';
			if(student[found].name[0]=='\0'){
				printf("\n*Error, Please Try Again*\n\n");
			}
		}while(student[found].name[0]=='\0');
		
		do{
			printf("Enter Student's Classroom ID: ");
			fgets(student[found].classroomId,5,stdin);
			student[found].classroomId[strcspn(student[found].classroomId,"\n")]='\0';
			if(student[found].classroomId[0]=='\0'){
				printf("\n*Error, Please Try Again*\n\n");
			}
		}while(student[found].classroomId[0]=='\0');
		
		do{
			count=0;
			printf("Enter Student's Email: ");
			fgets(student[found].email,35,stdin);
			student[found].email[strcspn(student[found].email,"\n")]='\0';
			for(int i=0; i<length; i++){
				if(i!= found && strcmp(student[i].email,student[found].email)==0){
					count++;
				}
			}
			if(count!=0 || student[found].email[0]=='\0'){
				printf("\n*Error, Please Try Again*\n\n");
			}
		}while(count!=0 || student[found].email[0]=='\0');
		do{
			count=0;
			printf("Enter Student's Phone Number: ");
			fgets(student[found].phoneNumber,15,stdin);
			student[found].phoneNumber[strcspn(student[found].phoneNumber,"\n")]='\0';
			for(int i=0; i<length; i++){
				if(i!=found && strcmp(student[i].email,student[found].phoneNumber)==0){
					count++;
				}
			}
			if(count!=0 || student[found].phoneNumber[0]=='\0'){
				printf("\n*Error, Please Try Again*\n\n");
			}
		}while(count!=0 || student[found].phoneNumber[0]=='\0');
		printf("\n*Student's Information Changed Successfully*\n"); 
		saveStudentToFile(student, length);
	}
}

void backAndExit(){
	int backExit;
	do{
		printf("\nGo Back(0) or Exit The Program(1)?: ");
		scanf("%d", &backExit);
		system("cls");
		if(backExit!=0 && backExit!=1){
			printf("\n*Error, Please Try Again*\n");
		}
	}while(backExit!=0 && backExit!=1);
	if(backExit==1){
		printf("\n*Exited The Program*");
		exit(0);
	}
}

void deleteStudent(Student student[], int *length){
	int find, found;
	char yesNo;
	printf("     ***DELETE STUDENT***\n\n");
	printf("Enter Student ID: ");
	scanf("%d", &find);
	found=-1;
	for(int i=0;i<*length; i++){
		if(student[i].studentId==find){
			found=i;
		}
	}
	if(found==-1){
		printf("\n*Can't Find Student With This ID*\n");
	} else{
		printf("      STUDENT INFORMATION\n");
		printf("================================\n");
		printf("ID: %d\n", student[found].studentId);
		printf("Classroom ID: %s\n", student[found].classroomId);
		printf("Full Name: %s\n", student[found].name);
		printf("Email: %s\n", student[found].email);
		printf("Phone Number: %s\n", student[found].phoneNumber);
		do{
			getchar();
			printf("\n\nAre You Sure You Want To Delete This Student? (Y/N): ");
			scanf("%c", &yesNo);
			if(yesNo!='Y' && yesNo!='N'){
				printf("\n\n*Error, Please Try Again*\n");
			}	
		}while(yesNo!='Y' && yesNo!='N');
		if(yesNo=='N'){
			printf("\n*Delete Cancelled*\n");
		} else{
			for(int i=found; i<*length; i++){
				student[i]=student[i+1];
				
			}
			(*length)--;
			printf("\n*Delete Successful*\n");
			saveStudentToFile(student, *length);
		}
	}
}
void sortStudent(Student student[], int length){
    int sortOrder;
    if(length < 2){
        system("cls");
        printf("*Not Enough Students To Sort*\n");
    } else {
        do {
            printf("\nSort By Ascending(0) or Descending(1) order: ");
            scanf("%d", &sortOrder);
        } while(sortOrder != 1 && sortOrder != 0);
        
        system("cls");
        // xap xep tang dan
        if(sortOrder == 0){
            for(int i = 1; i < length; i++){
                Student key = student[i];
                int j = i - 1;
                
                while(j >= 0 && key.studentId < student[j].studentId){
                    student[j + 1] = student[j];
                    j--;
                }
                student[j + 1] = key;
            }
            // xap xep giam dan 
        } else { 
            for(int i = 1; i < length; i++){
                Student key = student[i];
                int j = i - 1;
                
                while(j >= 0 && key.studentId > student[j].studentId){
                    student[j + 1] = student[j];
                    j--;
                }
                student[j + 1] = key;
            }
        }
    }
    if(length>=2){
    	printf("\n\t**SORTED STUDENTS**\n\n");
		printf("|=======|========================|==============|============================|==================|\n");
		printf("|  ID   |         Name           | classroomId  |           Email            |     PhoneNumber  |\n");
		printf("|=======|========================|==============|============================|==================|\n");
		for(int i=0; i<length; i++){
			
			printf("| %-5d | %-22s | %-12s | %-26s | %-16s |\n", 
			student[i].studentId,
			student[i].name,
			student[i].classroomId,
			student[i].email,
			student[i].phoneNumber);
			printf("|=======|========================|==============|============================|==================|\n");
		}
	}
}

void saveStudentToFile(Student student[], int length){
	FILE *ptr=fopen("studentData.dat", "wb");
	if(ptr==NULL){
		printf("\n\n*Can't Open File*\n");
		fclose(ptr);
	}
	fwrite(student,sizeof(Student),length,ptr);
	printf("\n\n*Saved Successfully*\n");
	fclose(ptr);
}

void loadStudentFromFile(Student student[], int *length){
	FILE *ptr=fopen("studentData.dat", "rb");
	if(ptr==NULL){
		printf("Can't Open File");
		fclose(ptr);
	}
	*length=fread(student, sizeof(Student), 100, ptr);
	printf("\n\n*Loaded Successfully*\n");
	fclose(ptr);
}
  // dinh nghia ham chuyen thanh chuoi thanh chu thuong
  void toLowerCase(char *str) {
    for ( int i = 0; str[i]; i++) {
       str[i] = tolower ((unsigned char)str[i]);
	}   
}

void searchStudent(Student student[], int length){
	int count=0;
	int firstTime;
	char name[30];
	getchar();
	do{
		printf("\nEnter Student Name To Search: ");
		fgets(name, sizeof(name), stdin);
		name[strcspn(name,"\n")]='\0';
		if(strlen(name)<=1){
			printf("\n*Minimum 2 Characters Required, Try Again*\n");
		}
	}while(strlen(name)<=1);
	system("cls");
	printf("\n    SEARCH RESULT FOR \"%s\":\n\n", name);
	firstTime=0;
	for(int i=0; i<length; i++){
		if((strstr(student[i].name, name))!= NULL){
			if(firstTime==0){
				printf("|=======|========================|==============|============================|==================|\n");
				printf("|  ID   |         Name           | classroomId  |           Email            |     PhoneNumber  |\n");
				printf("|=======|========================|==============|============================|==================|\n");
				firstTime++;
			}
			printf("| %-5d | %-22s | %-12s | %-26s | %-16s |\n", 
			student[i].studentId,
			student[i].name,
			student[i].classroomId,
			student[i].email,
			student[i].phoneNumber);
			printf("|=======|========================|==============|============================|==================|\n");
			count++;
		}
	}
	if(count==0){
	printf("*No Result*\n");
	}
}

