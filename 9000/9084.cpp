//# Author : nuclear852 ========================#
//# Solution : 4980177 =========================#
//# Time Stamp : 2017-01-10 10:39:44 ===========#
//# Problem Title : 동전 =====================#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
        int dy[21][10001];
        int T;
        int N;
        int M;
        int arr[21];
        scanf("%d",&T);
        while(T--)
        {
                scanf("%d",&N);
                for(int i=1; i<=N; i++)
                        scanf("%d", &arr[i]);
                scanf("%d", &M);
                for(int i=0; i<=N; i++)
                        for(int j=1; j<=M; j++)
                                dy[i][j] = 0;
                for(int j=0; j<=N; j++)
                        dy[j][0] = 1;
                for(int i=1; i<=N; i++)
                {
                        for(int j=1; j<=M; j++)
                        {
                                int temp = 0;
                                while(temp * arr[i] <= j)
                                {
                                        dy[i][j] += dy[i-1][j - (temp* arr[i])];
                                        temp++;
                                }
                        }
                }
                printf("%d\n",dy[N][M]);
        }
}