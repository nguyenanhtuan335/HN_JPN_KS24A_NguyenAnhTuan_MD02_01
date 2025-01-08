#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include <ctype.h>

int main(int argc, char *argv[]) {
    int chRole, chA1, chA2, length = 0;
    Student student[100];
    int countDeleteS;
    
    do {
        system("cls"); // or "clear" if on Unix/Linux
        roleMenu();
        printf("Enter Your Choice: ");
        if (scanf("%d", &chRole) != 1) {
            printf("\n*Error, Please Enter a Valid Choice*\n");
            while (getchar() != '\n'); // Clear buffer
            continue;
        }

        if (chRole == 1) {
            loadStudentFromFile(student, &length, 0);
            //login();
            do {
                system("cls");
                manageMenu();
                printf("Enter Your Choice: ");
                if (scanf("%d", &chA1) != 1) {
                    printf("\n*Error, Please Enter a Valid Choice*\n");
                    while (getchar() != '\n'); // Clear buffer
                    continue;
                }
                switch(chA1) {
                    case 1:
                        do {
                            system("cls");
                            studentMenu();
                            printf("Enter Your Choice: ");
                            if (scanf("%d", &chA2) != 1) {
                                printf("\n*Error, Please Enter a Valid Choice*\n");
                                while (getchar() != '\n'); // Clear buffer
                                continue;
                            }
                            switch(chA2) {
                                case 1:
                                    system("cls");
                                    inputStudent(student, &length);
                                    saveStudentToFile(student, length, 0);
                                    backAndExit();
                                    break;
                                case 2:
                                    system("cls");
                                    if (length == 0) {
                                        printf("\n*0 Students At The Moment*\n");
                                    } else {
                                        printStudent(student, length);
                                    }
                                    backAndExit();
                                    break;
                                case 3:
                                    searchStudent(student, length);
                                    backAndExit();
                                    break;
                                case 4:
                                    system("cls");
                                    editStudent(student, length);
                                    backAndExit();
                                    break;
                                case 5:
                                    system("cls");
                                    deleteStudent(student, &length);
                                    backAndExit();
                                    break;
                                case 6:
                                    saveStudentToFile(student, length, 0);
                                    sortStudent(student, length);
                                    loadStudentFromFile(student, &length, 0);
                                    backAndExit();
                                    break;
                                case 0:
                                    break;
                                default:
                                    printf("\n*Error, Please Enter a Valid Choice*\n");
                                    backAndExit();
                            }
                        } while(chA2 != 0);
                        break;
                    case 0:
                        break;
                    default:
                        printf("\n*Error, Please Enter a Valid Choice*\n");
                        backAndExit();
                }
            } while(chA1 != 0);
        }
    } while(chRole != 0);
    
    printf("\n*Exited The Program*\n");
    return 0;
}
