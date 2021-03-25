//# Author : nuclear852 ========================#
//# Solution : 5173977 =========================#
//# Time Stamp : 2017-02-07 10:32:55 ===========#
//# Problem Title : 한조 대기 중 ================#
//# Language : C++98 ===========================#

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int N, M, K1, K2;

bool adj[305][305];

vector<int> aMatch, bMatch;
vector<bool> visited;

bool dfs(int a){
        if( visited[a])
                return false;
        visited[a] = true;
        for(int b=1; b<M+1; b++)
        {
                if(adj[a][b]){
                        if(bMatch[b] == -1 || dfs(bMatch[b])){
                                aMatch[a] = b;
                                bMatch[b] = a;
                                return true;
                        }
                }
        }
        return false;
}

int bipartiteMatch()
{
        aMatch = vector<int>(N+1, -1);
        bMatch = vector<int>(M+1, -1);
        int size = 0;
        for( int start = 1; start < N+1; start++){
                visited = vector<bool>(N+1,false);
                if(dfs(start))  size++;
        }
        return size;
}

int main(){
        cin>>N>>M>>K1>>K2;
        for(int i=0; i<K1; i++){
                int x, y; cin>>x>>y;
                adj[x][y] = 1;
        }
        int k1, k2;
        k1 = bipartiteMatch();
        memset(adj,0,sizeof(adj));
        for(int i=0; i<K2; i++){
                int x, y; cin>>x>>y;
                adj[x][y] = 1;
        }
        k2 = bipartiteMatch();
        k1 < k2 ? cout<<"네 다음 힐딱이" : cout<<"그만 알아보자";
}