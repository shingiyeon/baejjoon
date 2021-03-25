//# Author : nuclear852 ========================#
//# Solution : 5141496 =========================#
//# Time Stamp : 2017-02-01 14:39:56 ===========#
//# Problem Title : 소풍 =====================#
//# Language : C++98 ===========================#

#include <iostream>
#include <vector>
using namespace std;
int main(){
        int N, M, K; cin>>N>>M>>K;
        int ans = 0;
        int num = 0;
        K--;
        while(1){
                ans++;
                int p = (num+M-1)%(N-ans+1);
                if( p == K)     break;
                if( p < K) K--;
                num = (num+M-1)%(N-ans+1);
        }
        cout<<ans<<endl;
}