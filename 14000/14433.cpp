//# Author : nuclear852 ========================#
//# Solution : 5174033 =========================#
//# Time Stamp : 2017-02-07 10:47:32 ===========#
//# Problem Title : 한조 대기 중 ================#
//# Language : C++98 ===========================#

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int n, m, k1, k2;

int aMatch[305], bMatch[305];
bool adj[305][305];
bool visited[305];

bool dfs(int a){
        if(visited[a]) return false;
        visited[a] = true;
        for(int i=1; i<=m; i++){
                if( adj[a][i] ){
                        if( bMatch[i] == -1 || dfs(bMatch[i]) ){
                                aMatch[a] = i;
                                bMatch[i] = a;
                                return true;
                        }
                }
        }
        return false;
}

int bipartiteMatch(){
        int size = 0;
        for(int i=1; i<=m; i++) bMatch[i] = -1;
        for(int i=1; i<=n; i++){
                memset(visited,0,sizeof(visited));
                size += dfs(i);
        }
        return size;
}

int main(){
        int K1, K2;
        cin>>n>>m>>k1>>k2;
        memset(adj,0,sizeof(adj));
        for(int i=0; i<k1; i++){
                int x, y; cin>>x>>y;
                adj[x][y] = 1;
        }
        K1 = bipartiteMatch();
        memset(adj,0,sizeof(adj));
        for(int i=0; i<k2; i++){
                int x, y; cin>>x>>y;
                adj[x][y] = 1;
        }
        K2 = bipartiteMatch();
        K1 < K2 ? cout<<"네 다음 힐딱이":cout<<"그만 알아보자";
}