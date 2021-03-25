//# Author : nuclear852 ========================#
//# Solution : 2124719 =========================#
//# Time Stamp : 2016-03-05 23:24:40 ===========#
//# Problem Title : 나머지 ====================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(void)
{
        int A,B,C;
        cin>>A>>B>>C;
        cout<<(A+B)%C<<endl;
        cout<<(A%C + B%C)%C<<endl;
        cout<<(A*B)%C<<endl;
        cout<<(A%C*B%C)%C<<endl;
}