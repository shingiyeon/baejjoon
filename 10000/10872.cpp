//# Author : nuclear852 ========================#
//# Solution : 5048237 =========================#
//# Time Stamp : 2017-01-18 13:46:53 ===========#
//# Problem Title : 팩토리얼 ===================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(){
    int N; cin>>N; int ans = 1;
    for(int i=1; i<=N; i++)
        ans *= i;
    cout<<ans<<endl;
}