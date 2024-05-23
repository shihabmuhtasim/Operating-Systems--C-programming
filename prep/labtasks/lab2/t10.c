//Write a C program to store students information in a struct. Take input from users for a student and print it.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Write a C program to concatenate two strings given by the user.

struct student{
    int id;
    char name[100];
};

int main(){

    struct student s;
    printf("Enter id\n");
    scanf("%d", &s.id);

    printf("enter name:\n");
    scanf("%s", s.name);

    printf("Student id: %d", s.id);
    printf("Student name : %s", s.name);


     


}





