//# Author : nuclear852 ========================#
//# Solution : 1766142 =========================#
//# Time Stamp : 2016-02-17 20:41:02 ===========#
//# Problem Title : A/B ====================#
//# Language : C++98 ===========================#

#include <stdio.h>
#include <iostream>
typedef long double ld;
using namespace std;
int main()
{
        ld a, b;
        cin>>a>>b;
        ld c = a/b;
        printf("%.9Lf\n",c);
}