//# Author : nuclear852 ========================#
//# Solution : 2087232 =========================#
//# Time Stamp : 2016-03-03 21:10:00 ===========#
//# Problem Title : 다리 놓기 ==================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(void){
        int T;
        cin>>T;
        while(T--){
                int N,M;
                cin>>N>>M;
                int K= M-N;
                long long unsigned ans = 1;
                if(K > N)
                {
                        for(long long unsigned i=K+1; i<=M; i++)
                                ans = ans * i;
                        for(long long unsigned i=1; i<=N; i++)
                                ans = ans/i;
                }
                else
                {
                        for(long long unsigned i=N+1; i<=M; i++)
                                ans = ans*i;
                        for(long long unsigned i=1; i<=K; i++)
                                ans= ans/i;
                }
                cout<<ans<<endl;
        }
}