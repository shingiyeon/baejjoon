//# Author : nuclear852 ========================#
//# Solution : 5054256 =========================#
//# Time Stamp : 2017-01-19 01:06:36 ===========#
//# Problem Title : 트리의 지름 =================#
//# Language : C++98 ===========================#

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <stdio.h>
#include <string.h>
using namespace std;
int main(){
        bool visited[10005];
        pair<int ,int> node;
        vector< pair<int, int> > v[10005];      queue< pair<int, int> > q;
        int n;  cin>>n;
        int x, y, z, w;
        for(int i=1; i<n; i++){
                scanf("%d %d %d",&x, &y, &z);
                node.first = y; node.second = z;
                v[x].push_back(node);
                node.first = x; node.second = z;
                v[y].push_back(node);
        }
        int max = 0;
        for(int i=1; i<=n; i++){
                memset(visited, 0, sizeof(visited));
                visited[i] = 1; node.first = i; node.second = 0;
                q.push(node);
                while(!q.empty()){
                        node = q.front();       x = node.first; y = node.second; q.pop();
                        if( y> max) max = y;
                        for(int i=0; i<v[x].size(); i++){
                                z= v[x][i].first; w = v[x][i].second;
                                if(visited[z] == 1)     continue;
                                node.first = z; node.second = y+w;
                                visited[z] = 1; q.push(node);
                        }
                }
        }
        cout<<max<<endl;
}