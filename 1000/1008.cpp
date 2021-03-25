//# Author : nuclear852 ========================#
//# Solution : 11611254 ========================#
//# Time Stamp : 2019-01-31 19:19:37 ===========#
//# Problem Title : A/B ====================#
//# Language : C++98 ===========================#

#include <stdio.h>
int main(){
    int a, b; scanf("%d%d",&a,&b);
    long double c = (long double)a/b;
    printf("%.9Lf", c);
}