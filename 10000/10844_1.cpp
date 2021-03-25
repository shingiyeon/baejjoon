//# Author : nuclear852 ========================#
//# Solution : 1736168 =========================#
//# Time Stamp : 2016-02-16 15:58:29 ===========#
//# Problem Title : 쉬운 계단 수 ================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(void)
{
        int N;
        cin >> N;
        int dy[N+1][10];
        dy[1][0]=0;
        for(int i=1; i<10; i++)
                dy[1][i]=1;
        for(int i=2; i<=N; i++)
        {
                dy[i][0] = dy[i-1][1] % 1000000000;
                dy[i][9] = dy[i-1][8] % 1000000000;
                for(int j=1; j<=8; j++)
                        dy[i][j] = (dy[i-1][j+1] + dy[i-1][j-1]) % 1000000000;

        }
        int ans = 0;
        for(int i=0; i<10; i++)
                ans = (ans + dy[N][i]) % 1000000000;

        cout<<ans<<endl;
}