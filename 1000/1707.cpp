//# Author : nuclear852 ========================#
//# Solution : 5047073 =========================#
//# Time Stamp : 2017-01-18 10:53:40 ===========#
//# Problem Title : 이분 그래프 =================#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
#include <utility>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;
int main(){
        int K; cin>>K;
        while(K--){
                int V, E; cin>>V>>E;
                vector<int> v[20005];
                pair<int ,int> p;       queue< pair<int, int> > q;
                bool visited[20005]; memset(visited,0,sizeof(visited)); bool num[20005];
                int x, y;
                for(int i=0; i<E; i++){
                        scanf("%d %d",&x, &y);  v[x].push_back(y); v[y].push_back(x);}
                for(int j=1; j<=V; j++){
                        if( visited[j] == 0){
                                p.first = j; p.second = 0; q.push(p); visited[j] = 1; num[j] = 0;
                                while( !q.empty()){
                                        p = q.front(); x = p.first; y = p.second; q.pop();
                                        for(int i=0; i<v[x].size(); i++){
                                                if( visited[ v[x][i] ] == 1) continue;
                                                p.first = v[x][i]; p.second = (y+1)%2; visited[ v[x][i]] = 1; num[ v[x][i] ] = (y+1)%2; q.push(p);
                                        }
                                }
                        }
                }
                bool pos = 1;
                for(int i=1; i<=V; i++){
                        for(int j=0; j<v[i].size(); j++){
                                if( num[i] == num[ v[i][j]] )
                                        pos = 0;
                        }
                }
                if(pos) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
        }
}