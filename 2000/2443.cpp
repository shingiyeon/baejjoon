//# Author : nuclear852 ========================#
//# Solution : 10891848 ========================#
//# Time Stamp : 2018-11-26 15:06:59 ===========#
//# Problem Title : 별 찍기 - 6 ===============#
//# Language : C++98 ===========================#

#include <stdio.h>

int main(void){
    int N;
    scanf("%d",&N);
    for(int i=1; i<=N; i++){
        for(int j=1; j<i; j++)
            printf(" ");
        for(int j=1; j<=2*(N-i)+1; j++)
            printf("*");
        printf("\n");
    }
}