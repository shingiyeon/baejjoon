//# Author : nuclear852 ========================#
//# Solution : 5257802 =========================#
//# Time Stamp : 2017-02-21 13:39:19 ===========#
//# Problem Title : 열혈강호 2 =================#
//# Language : C++98 ===========================#

#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
using namespace std;

int map[3005][3005];
int N, M;
bool visited[3005];

int dfs(int p, int mn){
        //cout<<p<<" "<<mn<<"\n";
        if( p == M+N+1) return mn;
        visited[p] = 1;
        int pos = 0;
        for(int i=1; i<=M+N+1; i++){
                if(!visited[i] && map[p][i] > 0){
                        mn = min(mn, map[p][i]);
                        visited[i] = 1;
                        pos = dfs(i, mn);
                        if(pos) { map[p][i]-=pos; map[i][p]+=pos; break;}
                }
        }
        return pos;
}

int main(){
        cin>>N>>M;
        for(int i=1; i<=N; i++){
                map[0][i] = 2;
                int temp; scanf("%d",&temp);
                for(int j=0; j<temp; j++){
                        int x; scanf("%d",&x);
                        map[i][x+N] = 1;
                }
        }
        for(int i=N+1; i<=M+N; i++) map[i][M+N+1]=1;
        while(1){
                memset(visited,0,sizeof(visited));
                int pos = dfs(0, 99999999);
                if(!pos) break;
        }
        int ans = 0;
        for(int i=N+1; i<=M+N; i++) ans += map[M+N+1][i];
        cout<<ans;
}