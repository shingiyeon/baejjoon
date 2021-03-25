//# Author : nuclear852 ========================#
//# Solution : 5089956 =========================#
//# Time Stamp : 2017-01-23 23:38:45 ===========#
//# Problem Title : 트리의 높이와 너비 =============#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
using namespace std;
int N, ans=0, anslev, m=0;
int T[10005][2], f[10005][2], P[10005];
int maxdepth = 0;

void go(int v, int depth){
        if( T[v][0] != -1)      go( T[v][0], depth+1);
        m++;
        if(depth > maxdepth) maxdepth = depth;
        if( m < f[depth][0] ) f[depth][0] = m;
        if( m > f[depth][1] ) f[depth][1] = m;
        if( T[v][1] != -1)      go( T[v][1], depth+1);
}

int main(){
        cin>>N;
        int x,y,z;
        for(int i=1; i<=N; i++){
                scanf("%d %d %d",&x,&y,&z);
                T[x][0] = y;    T[x][1] =z;
                P[y] = x;       P[z] = x;
                f[i][0] = N;    f[i][1] = 0;
        }
        int top = 1;
        while( P[top] != 0)
                top = P[top];
        go(top,1);
        for(int i=1; i<=maxdepth; i++){
                if( ans < f[i][1] - f[i][0] + 1){
                        ans = f[i][1] - f[i][0] + 1;
                        anslev = i;
                }
        }
        cout<<anslev<<" "<<ans;
}