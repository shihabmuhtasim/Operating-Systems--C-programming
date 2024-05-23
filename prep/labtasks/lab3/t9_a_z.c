//Write a C program to open a text file and print the characters [a-z, A-Z] only from that file.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    FILE *fp;
    char ch;
    fp = fopen("az.txt", "r");
    if (fp == NULL)
    {
        printf("File does not exist\n");
        exit(1);
    }
    //read the file

    //run infinity loop
    while (1)
    {
        //read the file
        ch = fgetc(fp);
        //if end of file break the loop
        if (ch == EOF)
        {
            break;
        }
        //if the character is in the range of [a-z, A-Z] print it
        if (ch>='a' && ch<='z' || ch>='A' && ch<='Z')
        {
            printf("%c", ch);
        }
    }

}