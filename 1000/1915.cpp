//# Author : nuclear852 ========================#
//# Solution : 4928634 =========================#
//# Time Stamp : 2017-01-03 23:07:42 ===========#
//# Problem Title : 가장 큰 정사각형 ==============#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>

using namespace std;
int min(int a, int b)
{
        return a > b? b : a;
}
int main(){
        int n, m;
        cin>>n>>m;
        bool arr[1001][1001];
        int dy[1001][1001];
        char buff[2001];
        int max = 0;
        for(int i=1; i<=n; i++)
        {
                scanf("%s",buff+1);
                for(int j=1; j<=m; j++)
                {
                        arr[i][j] = buff[j] - '0';
                        dy[i][j]=0;
                }
        }
        for(int j=1; j<=m; j++)
        {
                for(int i=1; i<=n; i++)
                {
                        if(arr[i][j] == 1)
                        {
                                int temp = min(dy[i-1][j-1], min(dy[i][j-1], dy[i-1][j]));
                                dy[i][j] = temp+1;
                                if(dy[i][j] > max)
                                        max = dy[i][j];
                        }
                }
        }
        cout<<max*max<<endl;
}