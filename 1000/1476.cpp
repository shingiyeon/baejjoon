//# Author : nuclear852 ========================#
//# Solution : 5013189 =========================#
//# Time Stamp : 2017-01-13 23:12:13 ===========#
//# Problem Title : 날짜 계산 ==================#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
        int E, S, M;
        cin>>E>>S>>M;
        int ans = 1;
        int x = 1, y = 1, z = 1;
        while( x != E || y != S || z != M)
        {
                x++; y++; z++; ans++;
                if(x>15)
                        x = 1;
                if(y>28)
                        y = 1;
                if(z>19)
                        z = 1;
        }
        cout<<ans<<endl;
}