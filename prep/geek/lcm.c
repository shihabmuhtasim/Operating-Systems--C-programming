#include <stdio.h>
#include <stdlib.h>
//LCM of 15 and 25 is 75
int main(){
    int n1=15;
    int n2=25;
    int i=1;
    int val=0;
    
    while(1){

        int j=1;
        while (j!=10000){
            
            if((n1*i)==(n2*j)){
                val=n1*i;
                
                break;
            }
            else {
            j++;
            }
        }
        
        if (val!=0){
            break;
        }
        else{
            i++;
        }    
        }
    printf("LCM is %d",val);

    }


