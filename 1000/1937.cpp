//# Author : nuclear852 ========================#
//# Solution : 4942493 =========================#
//# Time Stamp : 2017-01-05 14:59:05 ===========#
//# Problem Title : 욕심쟁이 판다 ================#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
using namespace std;

int dy[501][501];
int n;
int arr[501][501];

int dyna(int x, int y)
{
        if(dy[x][y] != -1)
                return dy[x][y];

        int max = 1;
        if(x-1>=1 && arr[x-1][y] > arr[x][y])
        {
                int temp = dyna(x-1,y) + 1;
                if( temp > max)
                        max = temp;

        }
        if(x+1 <=n && arr[x+1][y] > arr[x][y])
        {
                int temp = dyna(x+1,y) + 1;
                if( temp > max)
                        max = temp;
        }
        if(y+1 <= n && arr[x][y+1] > arr[x][y])
        {
                int temp = dyna(x,y+1) + 1;
                if(temp > max)
                        max = temp;
        }
        if(y-1 >=1 && arr[x][y-1] > arr[x][y])
        {
                int temp = dyna(x,y-1) + 1;
                if(temp > max)
                        max = temp;
        }
        dy[x][y] = max;
        return max;
}
int main()
{
        cin>>n;
        for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                        scanf("%d", &arr[i][j]);
                        dy[i][j] = -1;
                }
        }
        int max = 0;

        for(int i=1; i<=n; i++)
        {
                for(int j=1; j<=n; j++)
                {
                        int temp = dyna(i,j);
                        if (temp > max)
                                max = temp;
                }
        }
        cout << max<< endl;
}