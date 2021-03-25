//# Author : nuclear852 ========================#
//# Solution : 5090764 =========================#
//# Time Stamp : 2017-01-24 01:36:51 ===========#
//# Problem Title : 시그마 ====================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(){
        long long a, b; cin>>a>>b;
        long long ans = (a > b) ? (a*(a+1)/2)-(b*(b+1)/2)+b : (b*(b+1)/2-(a*(a+1)/2))+a;
        cout<<ans;
}