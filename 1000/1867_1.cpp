//# Author : nuclear852 ========================#
//# Solution : 5223222 =========================#
//# Time Stamp : 2017-02-15 15:24:55 ===========#
//# Problem Title : 돌멩이 제거 =================#
//# Language : C++98 ===========================#

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int n, k;

int aMatch[505], bMatch[505];
bool adj[505][505];
bool visited[505];

bool dfs(int a){
        if(visited[a]) return 0;
        visited[a] = 1;
        for(int i=1; i<=n; i++){
                if( adj[a][i] ){
                        if( bMatch[i] == -1 || dfs(bMatch[i]) ){
                                aMatch[a] = i;
                                bMatch[i] = a;
                                return 1;
                        }
                }
        }
        return 0;
}

int bipartiteMatch(){
        int size = 0;
        for(int i=1; i<=n; i++) bMatch[i] = -1;
        for(int i=1; i<=n; i++){
                memset(visited,0,sizeof(visited));
                size += dfs(i);
        }
        return size;
}

int main(){
        cin>>n>>k;
        for(int i=0; i<k; i++){
                int x, y; cin>>x>>y;
                adj[x][y] = 1;
        }
        cout<< bipartiteMatch();
}