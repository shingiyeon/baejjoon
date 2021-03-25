//# Author : nuclear852 ========================#
//# Solution : 5176135 =========================#
//# Time Stamp : 2017-02-07 16:05:05 ===========#
//# Problem Title : 단어의 개수 =================#
//# Language : C++98 ===========================#

#include <stdio.h>
int main(){
        int num = 0;
        char word[1000005];
        while( scanf("%s",word) != EOF)
                num++;
        printf("%d",num);
}