//# Author : nuclear852 ========================#
//# Solution : 5271765 =========================#
//# Time Stamp : 2017-02-23 17:22:57 ===========#
//# Problem Title : 소수 구하기 =================#
//# Language : C++98 ===========================#

#include <iostream>
#include <string.h>
using namespace std;
int main(){
        bool arr[1000005];
        memset(arr,1,sizeof(arr));
        arr[1] = 0; arr[2] = 1;
        for(int i=2; i<=1000000; i++){
                if( arr[i] ){
                        for(int j= i*2; j<=1000000; j+=i){
                                arr[j] = 0;
                        }
                }
        }
        int M, N; cin>>M>>N;
        for(int i=M; i<=N; i++){
                if(arr[i]){
                        cout<<i<<"\n";
                }
        }
}