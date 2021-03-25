//# Author : nuclear852 ========================#
//# Solution : 5148986 =========================#
//# Time Stamp : 2017-02-02 16:08:52 ===========#
//# Problem Title : 안정적인 문자열 ===============#
//# Language : C++98 ===========================#

#include <string.h>
#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
        int testcase = 1;
        char s[2005];
        scanf("%s",s);
        while(s[0] != '-'){
                int l = strlen(s);
                int num = 0;
                int n1 = 0;     int n2 = 0;
                for(int i=0; i<l; i++){
                        if(s[i] == '{') num++;
                        if(s[i] == '}') num--;
                        if(num < 0)     {n1++;  num = 0;}
                }
                num = 0;
                for(int i=l-1; i>=0; i--){
                        if(s[i] == '}') num++;
                        if(s[i] == '{') num--;
                        if(num < 0)     {n2++; num = 0;}
                }
                int ans = (n1+1)/2 + (n2+1)/2;
                printf("%d. %d\n",testcase,ans);
                testcase++;
                scanf("%s",s);
        }
}