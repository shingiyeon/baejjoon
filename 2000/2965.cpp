//# Author : nuclear852 ========================#
//# Solution : 2194871 =========================#
//# Time Stamp : 2016-03-10 00:05:58 ===========#
//# Problem Title : 캥거루 세마리 ================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(void)
{
        int a, b, c;
        cin>>a>>b>>c;
        if(b-a>c-b)
                a = b-a-1;
        else
                a = c-b-1;

        cout<<a<<endl;
}