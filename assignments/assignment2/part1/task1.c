//includ libraries including struct.h
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
//struct class for paratha, vegetable, mineral water
  
struct Paratha{
    int quantity;
    int unit_price;
};
struct Vegetable{
    int quantity;
    int unit_price;
};
struct MineralWater{
    int quantity;
    int unit_price;
};
//main function
int main(){
    //struct class for paratha, vegetable, mineral water
    struct Paratha p;
    struct Vegetable v;
    struct MineralWater m;
    //input for paratha, vegetable, mineral water
    printf("Enter Paratha quantity: ");
    scanf("%d", &p.quantity);
    printf("\n");
    printf("Enter Paratha unit price: ");
    scanf("%d", &p.unit_price);
    printf("\n");
    printf("Enter Vegetable quantity: ");
    scanf("%d", &v.quantity);
    printf("\n");
    printf("Enter Vegetable unit price: ");
    scanf("%d", &v.unit_price);
    printf("\n");
    printf("Enter Mineral Water quantity: ");
    scanf("%d", &m.quantity);
    printf("\n");
    printf("Enter Mineral Water unit price: ");
    scanf("%d", &m.unit_price);
    printf("\n");
    printf("Enter total people: ");
    int total_people;
    scanf("%d", &total_people);
    printf("\n");

    //calculate total price for paratha, vegetable, mineral water
    int total_price = p.quantity * p.unit_price + v.quantity * v.unit_price + m.quantity * m.unit_price;
    //calculate price per person in float
    float price_per_person = (float)total_price / total_people;
    printf("Individual people will pay: %.2f\n", price_per_person);

    return 0;
}