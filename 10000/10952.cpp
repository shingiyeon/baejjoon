//# Author : nuclear852 ========================#
//# Solution : 2214819 =========================#
//# Time Stamp : 2016-03-10 22:15:22 ===========#
//# Problem Title : A+B - 5 ================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(void)
{
    int a, b;
    cin>>a>>b;
       while( !(a==0 && b==0)){
           cout<<a+b<<endl;
           cin>>a>>b;
       }
}