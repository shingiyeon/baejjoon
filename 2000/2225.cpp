//# Author : nuclear852 ========================#
//# Solution : 4960819 =========================#
//# Time Stamp : 2017-01-07 17:45:44 ===========#
//# Problem Title : 합분해 ====================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;

long long arr[201][201];

long long dy(int N, int K){
        if(N < 0 || K < 0)
                return 0;
        if(N==0){
                arr[N][K] = 1;
                return 1;
        }
        if(K==0 && N>0){
                arr[N][K] = 0;
                return 0;
        }
        if(K==1 && N>=0){
                arr[N][K] = 1;
                return arr[N][K];
        }
        if( arr[N][K] != -1)
                return arr[N][K];

        long long temp = 0;
        for(int i=0; i<=N; i++)
        {
                temp += dy(N-i,K-1) % 1000000000;
                temp = temp % 1000000000;
        }
        arr[N][K] = temp % 1000000000;
        return arr[N][K];
}
int main(void)
{
        int N, K;
        cin>>N>>K;
        for(int i=0; i<=N; i++)
                for(int j=0; j<=K; j++)
                        arr[i][j] = -1;
        cout<<dy(N,K)<<endl;
}