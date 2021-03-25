//# Author : nuclear852 ========================#
//# Solution : 5143109 =========================#
//# Time Stamp : 2017-02-01 17:25:22 ===========#
//# Problem Title : Mini Fantasy War =======#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
        int T; cin>>T;
        while(T--){
                int arr[8];
                for(int i=0; i<8; i++)  scanf("%d",&arr[i]);
                arr[0] = arr[0] + arr[4] < 1 ? 1 : arr[0] + arr[4];
                arr[1] = arr[1] + arr[5] < 1 ? 1 : arr[1] + arr[5];
                arr[2] = arr[2] + arr[6] < 0 ? 0 : arr[2] + arr[6];
                arr[3] = arr[3] + arr[7];
                printf("%d\n",arr[0]+5*arr[1]+2*arr[2]+2*arr[3]);
        }
}