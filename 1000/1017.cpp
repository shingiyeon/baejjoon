//# Author : nuclear852 ========================#
//# Solution : 5258519 =========================#
//# Time Stamp : 2017-02-21 15:14:42 ===========#
//# Problem Title : 소수 쌍 ===================#
//# Language : C++98 ===========================#

#include <iostream>
#include <string.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N;
bool adj[55][55];
int aMatched[55], bMatched[55];
bool visited[55];
bool sosu[2005];

bool dfs(int p){
        if(visited[p]) return 0;
        visited[p] = 1;
        for(int i=0; i<N; i++){
                if(adj[p][i]){
                        if( bMatched[i] == -1 || dfs(bMatched[i])){
                                bMatched[i] = p;
                                aMatched[p] = i;
                                return 1;
                        }
                }
        }
        return 0;
}

int main(){
        cin>>N;
        vector<int> ans;
        sosu[0] = 1; sosu[1] = 1;
        for(int i=2; i<=2000; i++){
                if( sosu[i] == 0){
                        for(int j=2*i; j<=2000; j+=i){
                                sosu[j] = 1;
                        }
                }
        }
        int arr[51];
        for(int i=0; i<N; i++)  scanf("%d",&arr[i]);
        for(int i=0; i<N; i++){
                for(int j=0; j<N; j++){
                        if( sosu[arr[i]+arr[j]] == 0){
                                adj[i][j] = 1;
                        }
                }
                adj[i][i] = 0;
        }

        for(int i=0; i<N; i++){
                if(adj[0][i]){
                        int size = 2;
                        memset(bMatched,-1,sizeof(bMatched));
                        for(int j=1; j<N; j++){
                                memset(visited,0,sizeof(visited));
                                aMatched[0] = i; aMatched[i] = 0;
                                visited[0] = 1; visited[i] = 1;
                                bMatched[i] = 0; bMatched[0] = i;
                                size += dfs(j);
                        }
                        if(size == N) ans.push_back(arr[i]);
                }
        }
        sort(ans.begin(),ans.end());
        for(int i=0; i<ans.size(); i++) cout<<ans[i]<<" ";
        if(ans.size() == 0) cout<<"-1";
}