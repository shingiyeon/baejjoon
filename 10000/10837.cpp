//# Author : nuclear852 ========================#
//# Solution : 4931445 =========================#
//# Time Stamp : 2017-01-04 11:11:02 ===========#
//# Problem Title : 동전 게임 ==================#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
        int x, y;
        int k, c;
        scanf("%d %d",&k, &c);

        while(c--)
        {
                scanf("%d %d", &x, &y);
                if(x<y)
                {
                        if( k-y+x+1 >= y)
                                printf("1\n");
                        else
                                printf("0\n");
                }
                else if(x>y)
                {
                        if( k-x+2+y >= x)
                                printf("1\n");
                        else
                                printf("0\n");
                }
                else
                        printf("1\n");
        }
}