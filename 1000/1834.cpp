//# Author : nuclear852 ========================#
//# Solution : 5090783 =========================#
//# Time Stamp : 2017-01-24 01:39:17 ===========#
//# Problem Title : 나머지와 몫이 같은 수 ===========#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(){
        long long n; cin>>n; long long ans = 0;
        for(long long i=1; i<n; i++)
                ans += (i*n) + i;
        cout<<ans;
}