//# Author : nuclear852 ========================#
//# Solution : 5159961 =========================#
//# Time Stamp : 2017-02-04 17:22:04 ===========#
//# Problem Title : 블랙잭 ====================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(){
        int N,M; cin>>N>>M;
        int arr[100];
        int ans = 0;
        for(int i=0; i<N; i++) cin>>arr[i];
        for(int i=0; i<N; i++){
                for(int j=i+1; j<N; j++){
                        for(int k=j+1; k<N; k++){
                                if(arr[i]+arr[j]+arr[k] <= M && arr[i]+arr[j]+arr[k] >= 0)
                                        ans = max(ans,arr[i]+arr[j]+arr[k]);
                        }
                }
        }
        cout<<ans;
}