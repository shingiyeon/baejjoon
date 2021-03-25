//# Author : nuclear852 ========================#
//# Solution : 5143145 =========================#
//# Time Stamp : 2017-02-01 17:29:01 ===========#
//# Problem Title : 색종이 ====================#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main(){
        bool map[100][100];     memset(map,0,sizeof(map));
        int ans = 0;
        int n;  cin>>n;
        for(int i=0; i<n; i++){
                int x, y; scanf("%d %d",&x,&y);
                for(int i=x; i<x+10; i++)
                        for(int j=y; j<y+10; j++)
                                map[i][j] = 1;
        }
        for(int i=0; i<100; i++)
                for(int j=0; j<100; j++)
                        ans += map[i][j];
        cout<<ans;
}