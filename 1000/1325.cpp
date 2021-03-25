//# Author : nuclear852 ========================#
//# Solution : 5062258 =========================#
//# Time Stamp : 2017-01-19 23:21:02 ===========#
//# Problem Title : 효율적인 해킹 ================#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
int main(){
        int N, M; cin>>N>>M;
        bool visited[10005];
        vector<int> v[10005];
        vector<int> ans;
        int Max = 0;
        queue<int> q;
        int a, b, n;
        for(int i=0; i<M; i++){
                scanf("%d %d",&a,&b);
                v[b].push_back(a);
        }
        for(int i=1; i<=N; i++){
                int num = 0;
                memset(visited, 0, sizeof(visited));
                visited[i] = 1;
                q.push(i);
                while(!q.empty()){
                        n = q.front(); q.pop();
                        num++;
                        for(int i=0; i<v[n].size(); i++){
                                if(visited[ v[n][i]] == 1) continue;
                                visited[v[n][i]] = 1;
                                q.push(v[n][i]);
                        }
                }
                if(num > Max) {ans.clear(); Max = num; ans.push_back(i);}
                else if(num == Max) {ans.push_back(i);}
        }
        for(int i=0; i<ans.size(); i++)
                cout<<ans[i]<<" ";
}