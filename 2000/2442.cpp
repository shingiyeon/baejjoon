//# Author : nuclear852 ========================#
//# Solution : 10891813 ========================#
//# Time Stamp : 2018-11-26 15:03:53 ===========#
//# Problem Title : 별 찍기 - 5 ===============#
//# Language : C++98 ===========================#

#include <stdio.h>

int main(void){
    int N;
    scanf("%d", &N);
    for(int i=1; i<=N; i++){
        for(int j=0; j<N-i; j++)
            printf(" ");
        for(int j=0; j<i*2-1; j++)
            printf("*");
        printf("\n");
    }
}