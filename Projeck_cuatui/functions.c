#include <stdio.h>
#include "functions.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void roleMenu(){
	printf("     ***Management System Using C***\n\n");
	printf("\tCHOOSE YOUR ROLE\n");
	printf("================================\n");
	printf("[1] Admin\n");
	printf("[2] Student\n");
	printf("[3] Teacher\n");
	printf("[0] Exit The Program\n");
	printf("================================\n");
}

void manageMenu(){
	printf("    ***Management System Using C***\n\n");
	printf("\t     MENU\n");
	printf("================================\n");
	printf("[1] Students Mangement\n");
	printf("[2] Teachers Management\n");
	printf("[3] Classrooms Management\n");
	printf("[0] Back\n");
	printf("================================\n");
}

//student

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
    int count, check;
    printf("\t***Add A New Student***\n\n");
    getchar();
    do {
        count = 0;
        printf("Enter Student's ID: ");
        if (scanf("%d", &student[*length].studentId) == 1) {
            for (int i = 0; i < *length; i++) {
                if (student[i].studentId == student[*length].studentId) {
                    count++;
                }
            }
            if (count != 0 || student[*length].studentId < 1 || student[*length].studentId > 99999) {
                printf("\n*Student ID Must Be Positive And Not Already Exist*\n\n");
            }
        } else {
            printf("\n*Student ID Must Be A Number*\n\n");
            while ((getchar()) != '\n');
        }
    } while (count != 0 || student[*length].studentId < 1 || student[*length].studentId > 99999);
    getchar();
    
    do {
        check = 0;
        printf("Enter Student's Full Name: ");
        fgets(student[*length].name, 25, stdin);
        if (strcspn(student[*length].name, "\n") == strlen(student[*length].name)) {
            while ((getchar()) != '\n');
        } else {
            student[*length].name[strcspn(student[*length].name, "\n")] = '\0';
        }
        for (int i = 0; i < strlen(student[*length].name); i++) {
            if (isalpha(student[*length].name[i]) == 0 && student[*length].name[i] != ' ') {
                check++;
            }
        }
        if (student[*length].name[0] == '\0' || check != 0 || student[*length].name[0] == ' ') {
            printf("\n*Name Must Not Be Empty Or Contains Special Characters*\n\n");
        }
    } while (student[*length].name[0] == '\0' || check != 0 || student[*length].name[0] == ' ');
    
    do {
        check = 0;
        printf("Enter Student's Classroom ID: ");
        fgets(student[*length].classroomId, 5, stdin);
        if (strcspn(student[*length].classroomId, "\n") == strlen(student[*length].classroomId)) {
            while ((getchar()) != '\n');
        } else {
            student[*length].classroomId[strcspn(student[*length].classroomId, "\n")] = '\0';
        }
        for (int i = 0; i < strlen(student[*length].classroomId); i++) {
            if (isdigit(student[*length].classroomId[i]) == 0) {
                check++;
            }
        }
        if (student[*length].classroomId[0] == '\0' || check != 0 || student[*length].classroomId[0] == ' ') {
            printf("\n*Classroom ID Must Not Be Empty Or Be A Negative Number*\n\n");
        }
    } while (student[*length].classroomId[0] == '\0' || check != 0 || student[*length].classroomId[0] == ' ');
    
    do {
        count = 0;
        check = 0;
        printf("Enter Student's Email: ");
        fgets(student[*length].email, 30, stdin);
        if (strcspn(student[*length].email, "\n") == strlen(student[*length].email)) {
            while ((getchar()) != '\n');
        } else {
            student[*length].email[strcspn(student[*length].email, "\n")] = '\0';
        }
        for (int i = 0; i < *length; i++) {
            if (strcmp(student[i].email, student[*length].email) == 0) {
                count++;
            }
        }
        for (int i = 0; i < strlen(student[*length].email); i++) {
            if (isalpha(student[*length].email[i]) == 0 && student[*length].email[i] != '@' && student[*length].email[i] != '.' && student[*length].email[i] != '-' && student[*length].email[i] != '_' && isdigit(student[*length].email[i]) == 0) {
                check++;
            }
        }
        if (count != 0 || student[*length].email[0] == '\0' || check != 0 || student[*length].email[0] == ' ' || student[*length].email[0] == '.' || student[*length].email[0] == '@' || strstr(student[*length].email, "@") == NULL || strstr(student[*length].email, ".com") == NULL) {
            printf("\n*Email Must Not Be Empty, Contain Special Characters (Except \".\", \"-\", \"_\"), Or Already Exist, And Must Contain '@' And '.com'*\n\n");
        }
    } while (count != 0 || student[*length].email[0] == '\0' || check != 0 || student[*length].email[0] == ' ' || student[*length].email[0] == '.' || student[*length].email[0] == '@' || strstr(student[*length].email, "@") == NULL || strstr(student[*length].email, ".com") == NULL);
    
    do {
        count = 0;
        check = 0;
        printf("Enter Student's Phone Number: ");
        fgets(student[*length].phoneNumber, 15, stdin);
        if (strcspn(student[*length].phoneNumber, "\n") == strlen(student[*length].phoneNumber)) {
            while ((getchar()) != '\n');
        } else {
            student[*length].phoneNumber[strcspn(student[*length].phoneNumber, "\n")] = '\0';
        }
        for (int i = 0; i < *length; i++) {
            if (strcmp(student[i].phoneNumber, student[*length].phoneNumber) == 0) {
                count++;
            }
        }
        for (int i = 0; i < strlen(student[*length].phoneNumber); i++) {
            if (isdigit(student[*length].phoneNumber[i]) == 0) {
                check++;
            }
        }
        if (count != 0 || student[*length].phoneNumber[0] == '\0' || check != 0 || student[*length].phoneNumber[0] == ' ') {
            printf("\n*PhoneNumber Must Not Be Empty, Contain Special Characters, Or Already Exist*\n\n");
        }
        if (strlen(student[*length].phoneNumber) != 10) {
            printf("\n*PhoneNumber Must Have 10 Digits*\n\n");
        }
    } while (count != 0 || student[*length].phoneNumber[0] == '\0' || check != 0 || student[*length].phoneNumber[0] == ' ' || strlen(student[*length].phoneNumber) != 10);

    printf("\n*Student Added Successfully*\n");
    (*length)++;
    saveStudentToFile(student, *length, 1);
}


void printStudent(Student student[], int length){
	printf("\t**ALL STUDENTS**\n\n");
	printf("|=======|===========================|==============|================================|==================|\n");
	printf("|  ID   |           Name            | classroomId  |             Email              |    PhoneNumber   |\n");
	printf("|=======|===========================|==============|================================|==================|\n");
	for(int i=0; i<length; i++){
		printf("| %-5d | %-25s | %-12s | %-30s | %-16s |\n", 
		student[i].studentId,
		student[i].name,
		student[i].classroomId,
		student[i].email,
		student[i].phoneNumber);
		printf("|=======|===========================|==============|================================|==================|\n");
	}
}

void editStudent(Student student[], int length){
	int find, found, count=0, check=0;
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
		printf("Full Name: %s\n", student[found].name);
		printf("Classroom ID: %s\n", student[found].classroomId);
		printf("Email: %s\n", student[found].email);
		printf("Phone Number: %s\n", student[found].phoneNumber);
		printf("\n***UPDATE INFORMATION***\n\n");
		getchar();
		do{
			count=0;
			printf("Enter Student's ID: ");
			if(scanf("%d", &student[found].studentId)==1){
				for(int i=0; i<length; i++){
					if(i!=found && student[i].studentId==student[found].studentId){
						count++;
					}
				}
				if(count!=0 || student[found].studentId<1 || student[found].studentId>99999){
					printf("\n*Student ID Must Be Positive And Not Already Exist*\n\n");
				}
			} else{
				printf("\n*Student ID Must Be A Number*\n\n");
				while ((getchar()) != '\n');
			}
		}while(count!=0 || student[found].studentId<1 || student[found].studentId>99999);
		getchar();
		
		do{
			check=0;
			printf("Enter Student's Full Name: ");
			fgets(student[found].name,25,stdin);
			if(strcspn(student[found].name,"\n")==strlen(student[found].name)){
				while ((getchar()) != '\n');
			} else{
				student[found].name[strcspn(student[found].name,"\n")]='\0';
			}
			for(int i=0; i<strlen(student[found].name); i++){
				if(isalpha(student[found].name[i])==0 && student[found].name[i] != ' '){
					check++;
				}
			}
			if(student[found].name[0]=='\0' || check!=0 || student[found].name[0]==' '){
				printf("\n*Name Must Not Be Empty Or Contains Special Characters*\n\n");
			}
		}while(student[found].name[0]=='\0' || check!=0 || student[found].name[0]==' ');
		
		do{
			check=0;
			printf("Enter Student's Classroom ID: ");
			fgets(student[found].classroomId,5,stdin);
			if(strcspn(student[found].classroomId, "\n")==strlen(student[found].classroomId)){
				while((getchar())!='\n');
			} else{
				student[found].classroomId[strcspn(student[found].classroomId,"\n")]='\0';
			}
			for(int i=0; i<strlen(student[found].classroomId); i++){
				if(isdigit(student[found].classroomId[i])==0){
					check++;
				}
			}
			if(student[found].classroomId[0]=='\0' || check!=0 || student[found].classroomId[0]==' '){
				printf("\n*Classroom ID Must Not Be Empty Or Be A Negative Number*\n\n");
			}
		}while(student[found].classroomId[0]=='\0' || check!=0 || student[found].classroomId[0]==' ');
		
		do{
			count=0;
			check=0;
			printf("Enter Student's Email: ");
			fgets(student[found].email,30,stdin);
			if(strcspn(student[found].email, "\n")==strlen(student[found].email)){
				while((getchar())!='\n');
			} else{
				student[found].email[strcspn(student[found].email,"\n")]='\0';
			}
			for(int i=0; i<length; i++){
				if(i!=found && strcmp(student[i].email,student[found].email)==0){
					count++;
				}
			}
			for(int i=0; i<strlen(student[found].email); i++){
				if(isalpha(student[found].email[i])==0 && student[found].email[i]!='@' && student[found].email[i]!='.' && student[found].email[i]!='-' && student[found].email[i]!='_' && isdigit(student[found].email[i])==0){
					check++;
				}
			}
			if(count!=0 || student[found].email[0]=='\0' || check!=0 || student[found].email[0]=='@' || student[found].email[0]=='.' || student[found].email[0]=='_'){
				printf("\n*Email Must Not Be Empty, Contain Special Characters(Except \".\",\"-\",\"_\"), Or Already Exist*\n\n");
			}
		}while(count!=0 || student[found].email[0]=='\0' || check!=0 || student[found].email[0]=='@' || student[found].email[0]=='.' || student[found].email[0]=='_');
		
		do{
			count=0;
			check=0;
			printf("Enter Student's Phone Number: ");
			fgets(student[found].phoneNumber,15,stdin);
			if(strcspn(student[found].phoneNumber, "\n")==strlen(student[found].phoneNumber)){
				while((getchar())!='\n');
			} else{
				student[found].phoneNumber[strcspn(student[found].phoneNumber,"\n")]='\0';
			}
			for(int i=0; i<length; i++){
				if(i!=found && strcmp(student[i].phoneNumber,student[found].phoneNumber)==0){
					count++;
				}
			}
			for(int i=0; i<strlen(student[found].phoneNumber); i++){
				if(isdigit(student[found].phoneNumber[i])==0){
					check++;
				}
			}
			if(count!=0 || student[found].phoneNumber[0]=='\0' || check!=0 || student[found].phoneNumber[0]==' '){
				printf("\n*PhoneNumber Must Not Be Empty, Contain Special Characters, Or Already Exist*\n\n");
			}
			if(strlen(student[found].phoneNumber)!=10){
				printf("\n*PhoneNumber Must Have 10 Digits*\n\n");
			}
		}while(count!=0 || student[found].phoneNumber[0]=='\0' || check!=0 || student[found].phoneNumber[0]==' ' || strlen(student[found].phoneNumber)!=10);
		printf("\n*Student's Information Changed Successfully*\n"); 
		saveStudentToFile(student, length, 1);
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
		printf("\n======Thank You======\n");
		printf("==== See You Soon ====");
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
		printf("Full Name: %s\n", student[found].name);
		printf("Classroom ID: %s\n", student[found].classroomId);
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
			saveStudentToFile(student, *length, 1);
		}
	}
}

void sortStudent(Student student[], int length) {
    int sortOrder;
    if (length < 2) {
        system("cls");
        printf("*Not Enough Students To Sort*\n");
    } else {
        saveStudentToFile(student, length, 0);
        do {
            printf("\nSort By Ascending(0) or Descending(1) order: ");
            scanf("%d", &sortOrder);
        } while (sortOrder != 1 && sortOrder != 0);
        system("cls");
        if (sortOrder == 0) {
            // S?p x?p tãng d?n theo ID
            for (int i = 1; i < length; i++) {
                Student key = student[i];
                int j = i - 1;
                while (j >= 0 && student[j].studentId > key.studentId) {
                    student[j + 1] = student[j];
                    j--;
                }
                student[j + 1] = key;
            }
        } else {
            // S?p x?p gi?m d?n theo ID
            for (int i = 1; i < length; i++) {
                Student key = student[i];
                int j = i - 1;
                while (j >= 0 && student[j].studentId < key.studentId) {
                    student[j + 1] = student[j];
                    j--;
                }
                student[j + 1] = key;
            }
        }

        if (length >= 2) {
            printf("\n\t**SORTED STUDENTS**\n\n");
            printf("|=======|===========================|==============|================================|==================|\n");
            printf("|  ID   |           Name            | Classroom ID |             Email              |   Phone Number   |\n");
            printf("|=======|===========================|==============|================================|==================|\n");
            for (int i = 0; i < length; i++) {
                printf("| %-5d | %-25s | %-12s | %-30s | %-16s |\n", 
                       student[i].studentId,
                       student[i].name,
                       student[i].classroomId,
                       student[i].email,
                       student[i].phoneNumber);
                printf("|=======|===========================|==============|================================|==================|\n");
            }
        }
        loadStudentFromFile(student, &length, 0);
    }
}


void saveStudentToFile(Student student[], int length, int a){
	FILE *ptr=fopen("studentData.dat", "wb");
	if(ptr==NULL){
		printf("\n\n*Can't Open File*\n");
	}
	fwrite(student,sizeof(Student),length,ptr);
	if(a==1){
		printf("\n*Saved Successfully*\n");
	}
	fclose(ptr);
}

void loadStudentFromFile(Student student[], int *length, int a){
	FILE *ptr=fopen("studentData.dat", "rb");
	if(ptr==NULL){
		printf("Can't Open File");
	}
	*length=fread(student, sizeof(Student), 100, ptr);
	if(a==1){
		printf("\n*Loaded Successfully*\n");
	}
	fclose(ptr);
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
				printf("|=======|===========================|==============|================================|==================|\n");
				printf("|  ID   |           Name            | classroomId  |             Email              |    PhoneNumber   |\n");
				printf("|=======|===========================|==============|================================|==================|\n");
				firstTime++;
			}
			printf("| %-5d | %-25s | %-12s | %-30s | %-16s |\n", 
			student[i].studentId,
			student[i].name,
			student[i].classroomId,
			student[i].email,
			student[i].phoneNumber);
			printf("|=======|===========================|==============|================================|==================|\n");
			count++;
		}
	}
	if(count==0){
	printf("*No Result*\n");
	}
}

