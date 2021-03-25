//# Author : nuclear852 ========================#
//# Solution : 5153115 =========================#
//# Time Stamp : 2017-02-03 10:24:18 ===========#
//# Problem Title : 에라토스테네스의 체 =============#
//# Language : C++98 ===========================#

#include <iostream>
#include <string.h>
using namespace std;
int main(){
        bool arr[1002]; memset(arr,0,sizeof(arr));
        int N, K; cin>>N>>K;
        int ans = 0;
        while(1){
                for(int i=2; i<=N; i++){
                        if(arr[i] == 0){
                                for(int j=i; j<=N; j+=i){
                                        if(arr[j] == 0){
                                                arr[j] = 1;
                                                ans++;
                                        }
                                        if(ans == K){
                                                cout<<j;
                                                return 0;
                                        }
                                }
                        }
                }
        }
}