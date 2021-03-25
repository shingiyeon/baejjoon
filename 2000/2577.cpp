//# Author : nuclear852 ========================#
//# Solution : 5046957 =========================#
//# Time Stamp : 2017-01-18 10:37:59 ===========#
//# Problem Title : 숫자의 개수 =================#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
using std::string;
int main(){
        long long a, x, y, z; cin>>x>>y>>z; a = z*x*y;
        char c[14];     int arr[10];    memset(arr,0,sizeof(arr));
        int temp = 1000000000;
        int num = 0;
        while(1){ if( !(int)(a/temp) ){ temp /= 10; continue;} break;}
        while(temp!=0){ c[num] = (int)(a/temp) + '0'; num++;    a = a-((int)(a/temp)*temp); temp /= 10; }
        for(int i=0; i<num; i++)        arr[ c[i]-'0' ]++;
        for(int i=0; i<10; i++) cout<<arr[i]<<endl;
}