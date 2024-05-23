#include <stdio.h>


int main(){


//task b
    FILE *f;
    f= fopen("taskb.txt","r");
    char str[1000];
    fgets(str,255,f);
    printf("The text file contains:%s\n",str);

    
    f=fopen("taskb-w.txt","w");
    printf("Written in output file:");
    int i;
    i=0;
    while (str[i]!='\0'){
        if(str[i]!=' '){
            printf("%c",str[i]);
            fprintf(f,"%c",str[i]);
            i++;
        }
        else{
            printf("%c",str[i]);
           fprintf(f,"%c",str[i]);
           i++;
           while (str[i]==' '){
                NULL;
                i++;
           }
        }
        
    }


    
}