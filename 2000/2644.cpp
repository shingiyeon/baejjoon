//# Author : nuclear852 ========================#
//# Solution : 5045507 =========================#
//# Time Stamp : 2017-01-18 01:50:22 ===========#
//# Problem Title : 촌수계산 ===================#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
#include <utility>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
int main(){
        int n; cin>>n;
        bool visited[105];      memset(visited,0,sizeof(visited));
        int x, y;       cin>>x>>y;
        pair<int, int> p;       queue< pair<int, int> >q;
        vector<int> v[105];
        int m;  cin>>m;
        int a, b;
        for(int i=1; i<=m; i++){
                scanf("%d %d",&a,&b);
                v[a].push_back(b);      v[b].push_back(a);}
        p.first = x; p.second = 0; q.push(p);   visited[x] = 1;
        while( !q.empty() ){
                p = q.front();  a = p.first;    b = p.second; q.pop();
                if(a==y){       cout<<b;        return 0;}
                for(int i=0; i<v[a].size(); i++)
                {
                        if( visited[ v[a][i] ] == 1)    continue;
                        p.first = v[a][i];      p.second = b+1;
                        q.push(p);      visited[ v[a][i] ] = 1;
                }
        }
        cout<<"-1"<<endl;
        return 0;
}