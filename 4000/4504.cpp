//# Author : nuclear852 ========================#
//# Solution : 5090737 =========================#
//# Time Stamp : 2017-01-24 01:33:11 ===========#
//# Problem Title : 배수 찾기 ==================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(){
        int n;  cin>>n;
        int arr; cin>>arr;
        while(arr!=0){
                if((arr%n)) cout<<arr<<" "<<"is NOT a multiple of "<<n<<"."<<'\n';
                else    cout<<arr<<" "<<"is a multiple of "<<n<<"."<<'\n';
                cin>>arr;
        }
}