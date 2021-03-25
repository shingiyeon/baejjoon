//# Author : nuclear852 ========================#
//# Solution : 4993784 =========================#
//# Time Stamp : 2017-01-11 17:26:34 ===========#
//# Problem Title : 점프 =====================#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
        int N;
        int map[101][101];
        long long dy[101][101];
        scanf("%d", &N);
        for(int i=1; i<=N; i++)
                for(int j=1; j<=N; j++)
                        scanf("%d", &map[i][j]);
        for(int i=1; i<=N; i++)
                for(int j=1; j<=N; j++)
                        dy[i][j] = 0;
        dy[1][1] = 1;

        for(int i=1; i<=N; i++)
        {
                for(int j=1; j<=N; j++)
                {
                        if(i==N && j==N)
                                break;
                        if( j + map[i][j] <= N && map[i][j] != 0)
                                dy[i][ j+map[i][j] ] += dy[i][j];
                        if( i + map[i][j] <= N && map[i][j] != 0)
                                dy[i + map[i][j]][j] += dy[i][j];
                }
        }
/*      
        for(int i=1; i<=N; i++)
        {
                for(int j=1; j<=N; j++)
                        printf("%d ", dy[i][j]);
                printf("\n");
        }
*/
        printf("%lld\n",dy[N][N]);
}