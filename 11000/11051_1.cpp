//# Author : nuclear852 ========================#
//# Solution : 4980256 =========================#
//# Time Stamp : 2017-01-10 10:52:26 ===========#
//# Problem Title : 이항 계수 2 ================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int arr[1001][1001];

int dy(int n, int k){
        if(n<=0 || k<0)
                return 0;
        else if(arr[n][k] != -1)
                return arr[n][k];
        else if(n==k)
                return arr[n][k] = 1;
        else if(k==0)
                return arr[n][k] = 1;
        else
                return arr[n][k] = (dy(n-1,k) + dy(n-1,k-1)) % 10007;
}

int main()
{
        int N, K;
        for(int i=0; i<=1000; i++)
                for(int j=0; j<=1000; j++)
                        arr[i][j] = -1;
        cin>>N>>K;
        cout<<dy(N,K)<<endl;
}