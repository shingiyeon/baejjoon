//# Author : nuclear852 ========================#
//# Solution : 5077460 =========================#
//# Time Stamp : 2017-01-22 11:22:20 ===========#
//# Problem Title : 0 = not cute / 1 = cute #
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(){
int n; int temp = 0; int ans=0;
cin>>n; for(int i=0; i<n; i++){cin>>temp;if(temp)ans++;}
if(ans>n-ans)cout<<"Junhee is cute!";
else cout<<"Junhee is not cute!";
}