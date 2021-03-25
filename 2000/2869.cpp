//# Author : nuclear852 ========================#
//# Solution : 5021637 =========================#
//# Time Stamp : 2017-01-15 09:30:03 ===========#
//# Problem Title : 달팽이는 올라가고 싶다 ===========#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(){
        int A, B, V;
        cin>>A>>B>>V;
        if( A >= V)
                cout<<"1";
        else if( A-B >= V-A)
                cout<<"2";
        else if( ((V-A)%(A-B)) != 0)
                cout<< 2+(int)((V-A)/(A-B));
        else
                cout<< 1+(int)((V-A)/(A-B));
}