//# Author : nuclear852 ========================#
//# Solution : 2160695 =========================#
//# Time Stamp : 2016-03-07 21:48:36 ===========#
//# Problem Title : 카드 =====================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(){
        int n;
        cin>>n;
        int arr[n];
        int sum=0;
        int max=0;
        for(int i=0; i<n; i++){
                cin>>arr[i];
                sum = sum+arr[i];
                if(arr[i]>max)
                        max = arr[i];
        }
        cout<<sum-max<<endl;
}