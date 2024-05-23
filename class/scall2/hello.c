
#include<stdio.h>
#include<string.h>
//this is library

//int return type
// struct student{

//     int stid;
//     char name[100];
//     float cgpa;

// };


int main(){
    //integer
    // int n=10;
    // int m=5;
    // int s=n+m;
    // printf("The sum of %d and %d is %d\n",m,n,s+5);
    // printf("CSE321");



    //float
    // float f=5.6;
    // printf("%0.2f\n", f);
    // double d =14.555444666666666666666666;
    // printf("%lf/n",d);


    //Float func
    // int n=12;
    // int m=5;
    // float f=(float)n/m;
    // printf("%f\n",f);

    //INPUT
    // int n;
    // printf("enter a number:");
    // scanf("%d",&n);
    // printf("%d\n",n*n);



    // int ara[5];
    // //int b[]={3,2,4,5,6};

    // int i;
    // for(i=0; i<5; i++){
    //     scanf("%d",&ara[i]);
    // }

    // for (i=0;i<sizeof(ara)/sizeof(ara[0]);i++){
    //     printf("%d ",ara[i]);
    // }

    //nested loop

    // int i,j;
    // for (i=0;i<5;i++){
    //     for (j=0;j<i;j++){
    //         printf("%d",j);
    //     }
    //     printf("\n");
    // }


    // int n;
    // scanf("%d",&n);
    
    // int i;
    // for (i=1;i<11;i++){
    //     printf("%d*%d=%d\n", n,i,n*i);


    // }

    //pointer
    // int n=10;
    // int *p=&n;
    // printf("%d's address is %p\n",n,p);

    // char ar[5]={'a','4','r','8','t'};
    // char *ptr= ar;
    // int i;
    // for(i=0;i<5;i++){
    //     printf("%c - %p\n",*ptr, ptr);
    //     *ptr++;
    // }


    //array
    // char araa[]={'a','a','j','r','o','b','i','b','\0'};
    // char araa2[]={'a','a','j','r','o','b','i','b','\0'};
    // printf("%s\n",araa);

    // printf("%ld\n",strlen(araa));

    // strcat(araa,araa2);
    // printf("%s", araa);


    //struct
    // struct student s1;
    // struct student s2;
    // s1.stid=12121;
    // strcpy(s1.name, "alif");
    // s1.cgpa=3.5;

    // printf("%d\n",s1.stid);
    // printf("%s\n",s1.name);
    // printf("%f\n",s1.cgpa);



    int ara[5];

    int i;
    for(i=0; i<5; i++){
        scanf("%d",&ara[i]);
        }

        int sum;
    int *ptr= ara;
    

    
    int x;
    int t;
    t=0;
    for(x=0;x<5;x++){
        t+=*ptr;
        
        *ptr++;
    }
    printf("Total :%d",t);

    int *p= t;
    printf("Address of sum:  - %p\n",p);



    }
    





    

