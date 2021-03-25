//# Author : nuclear852 ========================#
//# Solution : 4980076 =========================#
//# Time Stamp : 2017-01-10 10:21:18 ===========#
//# Problem Title : 팰린드롬? ==================#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
using namespace std;

int arr[2001][2001];
int str[2001];

int dy(int s, int e)
{
        if(s>e)
                return 1;
        if(arr[s][e] != -1)
                return arr[s][e];
        if(s==e){
                arr[s][e] = 1;
                return arr[s][e];
        }
        else if( str[s] != str[e] )
        {
                arr[s][e] = 0;
                return arr[s][e];
        }
        else
        {
                arr[s][e] = dy(s+1, e-1);
                return arr[s][e];
        }
}

int main()
{
        int N;
        int M;
        cin>>N;
        for(int i=1; i<=2000; i++)
                for(int j=1; j<=2000; j++)
                        arr[i][j] = -1;
        for(int i=1; i<=N; i++){
                scanf("%d", &str[i]);
        }
        cin>>M;
        for(int i=1; i<=M; i++)
        {
                int x, y;
                scanf("%d %d",&x,&y);
                printf("%d\n",dy(x,y));
        }
}