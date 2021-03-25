//# Author : nuclear852 ========================#
//# Solution : 5235964 =========================#
//# Time Stamp : 2017-02-17 17:25:43 ===========#
//# Problem Title : 거짓말 ====================#
//# Language : C++98 ===========================#

#include <vector>
#include <iostream>
#include <cstdio>
#include <map>
#include <queue>
#include <string.h>
using namespace std;
int main(){
        vector<int> ini;
        vector<int> map[105];
        bool visited[105]; memset(visited,0,sizeof(visited));
        int N,M; cin>>N>>M;
        int p; cin>>p;
        for(int i=0; i<p; i++){
                int temp; scanf("%d",&temp);
                ini.push_back(temp);
        }
        for(int i=N+1; i<=N+M; i++){
                scanf("%d",&p); int temp;
                for(int j=0; j<p; j++){
                        scanf("%d",&temp);
                        map[i].push_back(temp);
                        map[temp].push_back(i);
                }
        }
        for(int i=0; i<ini.size(); i++){
                if(visited[ini[i]] == 0){
                        queue<int> q;
                        q.push(ini[i]); visited[ini[i]] = 1;
                        while(!q.empty()){
                                int n = q.front(); q.pop();
                                for(int j=0; j<map[n].size(); j++){
                                        if(visited[map[n][j]]) continue;
                                        visited[map[n][j]] = 1;
                                        q.push(map[n][j]);
                                }
                        }
                }
        }
        int ans = 0;
        for(int i=N+1; i<=N+M; i++)
                if(visited[i] == 0 ) ans++;
        cout<<ans;
}