
#include <stdio.h>


int main(){
//TASK D
printf("%s","Enter email address: ");
char str[100];

scanf("%s", &str);
int i;
i=0;
int flag=0;
while (str[i] != ' ' && str[i] != '\0') {
    if (str[i]=='@'){
        if (str[i+1]=='k' && str[i+2]=='a' && str[i+3]=='a' && str[i+4]=='j' && str[i+5]=='.'){
            flag=0;
        }
        else if (str[i+1]=='s' && str[i+2]=='h' && str[i+3]=='e' && str[i+4]=='b' && str[i+5]=='a' ){
            flag=1;
        }
        
    }
    


i++;

}
if (flag==0){
    printf("Output: %s\n","Email address is outdated");
}
else {
    printf("Output: %s\n","Email address is okay");
}
}