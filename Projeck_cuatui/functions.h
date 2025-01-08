#include "dataTypes.h"

void roleMenu();
void login();
void manageMenu();

//student
void studentMenu();
void inputStudent(Student student[], int *length);
void printStudent(Student student[], int length);
void editStudent(Student student[], int length);
void backAndExit();
void deleteStudent(Student student[], int *length);
void sortStudent(Student student[], int length);
void saveStudentToFile(Student student[], int length, int a);
void loadStudentFromFile(Student student[], int *length, int a);
void searchStudent(Student student[], int length);
