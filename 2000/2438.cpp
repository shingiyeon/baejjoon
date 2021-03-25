//# Author : nuclear852 ========================#
//# Solution : 5174458 =========================#
//# Time Stamp : 2017-02-07 12:23:41 ===========#
//# Problem Title : 별 찍기 - 1 ===============#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(){ int N; cin>>N; for(int i=1; i<=N; i++) {for(int j=1; j<=i; j++) cout<<"*"; cout<<"\n";}}