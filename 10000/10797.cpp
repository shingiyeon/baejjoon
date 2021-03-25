//# Author : nuclear852 ========================#
//# Solution : 5048118 =========================#
//# Time Stamp : 2017-01-18 13:33:04 ===========#
//# Problem Title : 10부제 ===================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(){ int N; cin>>N; int temp, ans=0; for(int i=0; i<5; i++){     cin>>temp; if(temp==N) ans++;} cout<<ans<<endl;}