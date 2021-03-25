//# Author : nuclear852 ========================#
//# Solution : 2195583 =========================#
//# Time Stamp : 2016-03-10 00:47:32 ===========#
//# Problem Title : ATM ====================#
//# Language : C++98 ===========================#

#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
        int N;
        cin>>N;
        int arr[N];
        int ans=0;
        for(int i=0; i<N; i++)
                cin>>arr[i];
        sort(arr,arr+N);
        for(int i=1; i<N; i++)
                arr[i] = arr[i] + arr[i-1];
        for(int i=0; i<N; i++)
                ans = ans+arr[i];
        cout<<ans;
}