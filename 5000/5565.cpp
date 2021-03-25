//# Author : nuclear852 ========================#
//# Solution : 5048219 =========================#
//# Time Stamp : 2017-01-18 13:45:09 ===========#
//# Problem Title : 영수증 ====================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(){
        int tot;        cin>>tot;
        int arr[9];
        int sum = 0;
        for(int i=0; i<9; i++)  {cin>>arr[i]; sum += arr[i];}
        cout<<tot-sum<<endl;
                
}