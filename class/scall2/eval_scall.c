#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    //printf("%s",argv[1]);
    FILE *f;
    f= fopen(argv[1],"r");
    char str[1000];
    
    int a=0;

    char b= argv[2][0];
    
    printf("pppp%c",b);

    while ((feof(f))!=1){
        fgets(str,255,f);
        //printf("%s",str);

        int i=0;
        while (str[i]!='\0'){
            if (str[i]==b){

                ///printf("%c",  str[i]);
                a++;
            }
            //printf("%c",str[i]);

            i++;

        }
    


    }
    
    printf("%d",a);




}