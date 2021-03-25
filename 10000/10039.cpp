//# Author : nuclear852 ========================#
//# Solution : 2162081 =========================#
//# Time Stamp : 2016-03-07 23:10:49 ===========#
//# Problem Title : 평균 점수 ==================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(void){
        int arr[5];
        int sum=0;
    for(int i=0; i<5; i++){
            cin>>arr[i];
             if(arr[i]<=40)
                    arr[i]=40;
            sum=sum+arr[i];
    }
       cout<<sum/5<<endl;
}