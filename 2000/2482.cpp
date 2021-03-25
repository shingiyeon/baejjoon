//# Author : nuclear852 ========================#
//# Solution : 4929120 =========================#
//# Time Stamp : 2017-01-04 00:18:06 ===========#
//# Problem Title : 색상환 ====================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;

long dy[1001][1001];

int dyna(int n, int k)
{
        int ans;
        if(k<0 || n<0)
                return 0;
        else if(dy[n][k] != -1)
                return dy[n][k];
        else if(k==1){
                dy[n][1] = n;
                return n;
        }
        else if(k*2 > n+1)
        {
                dy[n][k] = 0;
                return dy[n][k];
        }
        else{
                ans = (dyna(n-1,k) + dyna(n-2,k-1)) % 1000000003;
                dy[n][k] = ans;
                return dy[n][k];
        }
}

int main()
{
        int n,k;
        cin>>n>>k;
        for(int i=0; i<=n; i++){
                for(int j=0; j<=k; j++){
                        dy[i][j] = -1;
                        if(j==1)
                                dy[i][j] = i;
                }
        }
        if(k==1)
                cout<<dy[n][k]<<endl;
        else{
                int ans = (dyna(n-3,k-1) + dyna(n-1,k)) % 1000000003;
                cout << ans<<endl;
        }
}