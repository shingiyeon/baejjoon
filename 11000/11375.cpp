//# Author : nuclear852 ========================#
//# Solution : 5257025 =========================#
//# Time Stamp : 2017-02-21 11:02:12 ===========#
//# Problem Title : 열혈강호 ===================#
//# Language : C++98 ===========================#

#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
int N, M;
int aMatch[1005], bMatch[1005];
bool adj[1005][1005];
bool visited[1005];

bool dfs(int p){
        if(visited[p]) return 0;
        visited[p] = 1;
        for(int i=1; i<=M; i++){
                if(adj[p][i]){
                        if(bMatch[i] == -1 || dfs(bMatch[i])){
                                bMatch[i] = p;
                                aMatch[p] = i;
                                return 1;
                        }
                }
        }
        return 0;
}

int main(){
        cin>>N>>M;
        for(int i=1; i<=N; i++){
                int temp; scanf("%d",&temp);
                for(int j=0; j<temp; j++){
                        int tm; scanf("%d",&tm);
                        adj[i][tm] = 1;
                }
        }
        int size = 0;
        memset(bMatch,-1,sizeof(bMatch));
        for(int i=1; i<=N; i++){
                memset(visited,0,sizeof(visited));
                size += dfs(i);
        }
        printf("%d",size);
}