//# Author : nuclear852 ========================#
//# Solution : 5149930 =========================#
//# Time Stamp : 2017-02-02 17:44:19 ===========#
//# Problem Title : 소음 =====================#
//# Language : C++98 ===========================#

#include <stdio.h>
#include <string.h>
int main(){
        char a[102], b[102], c;
        scanf("%s %c %s",a,&c,b);
        if(c=='+'){
                if(strlen(a)>strlen(b)) {a[ strlen(a)-strlen(b) ] = '1'; printf("%s",a);}
                else if(strlen(a)<strlen(b)) {b[strlen(b)-strlen(a) ] = '1'; printf("%s",b);}
                else {a[0]+=1; printf("%s",a);}
        }
        else{
                printf("%s",a);
                for(int i=0; i<strlen(b)-1; i++){
                        printf("0");
                }
        }
}