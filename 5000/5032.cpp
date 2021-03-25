//# Author : nuclear852 ========================#
//# Solution : 5155838 =========================#
//# Time Stamp : 2017-02-03 17:50:42 ===========#
//# Problem Title : 탄산 음료 ==================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(){
        int ans = 0;
        int a, b, c; cin>>a>>b>>c;
        a=a+b;
        while( ((int)a/c)){
                ans += (int)a/c;
                a = (a%c) + (int)a/c;
        }
        cout<<ans;
}