//# Author : nuclear852 ========================#
//# Solution : 5153164 =========================#
//# Time Stamp : 2017-02-03 10:36:43 ===========#
//# Problem Title : 직사각형을 만드는 방법 ===========#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(){
        int n; cin>>n; int ans = 0;
        for(int i=1; i<=n; i++) for(int j=1; j<=i; j++) if(!(i%j)&&(j>=i/j)) ans++;
        cout<<ans;
}