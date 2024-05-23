#include<stdio.h>


struct Class{
    int num;
    char room[100];
    char ins_name[100];
};

int main(){

    struct Class c;
    scanf("%d", &c.num);
    scanf("%s", &c.room);
    scanf("%s", &c.ins_name);

    printf("%d", c.num);
    return 0;





}