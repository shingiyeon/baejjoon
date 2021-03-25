//# Author : nuclear852 ========================#
//# Solution : 5235806 =========================#
//# Time Stamp : 2017-02-17 17:02:23 ===========#
//# Problem Title : 환승 =====================#
//# Language : C++98 ===========================#

#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <string.h>
#include <utility>
using namespace std;
int main(){
        int N,K,M; cin>>N>>K>>M;
        bool visited[200005]; memset(visited,0,sizeof(visited));
        queue< pair<int, int> > q;
        vector<int> map1[200005];
        for(int i=N+1; i<=N+M; i++){
                int temp;
                for(int j=0; j<K; j++){
                         scanf("%d",&temp);
                         map1[temp].push_back(i);
                         map1[i].push_back(temp);
                }
        }
        q.push(make_pair(1,1)); visited[1] = 1;
        while(!q.empty()){
                int n = q.front().first;
                int num = q.front().second;
                q.pop();
                if( n == N){ cout<<num/2+1; return 0;}
                for(int i=0; i<map1[n].size(); i++){
                        if( visited[ map1[n][i]] == 1) continue;
                        visited[map1[n][i]] = 1;
                        q.push( make_pair(map1[n][i],num+1));
                }
        }
        cout<<"-1";
}