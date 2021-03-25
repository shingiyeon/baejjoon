//# Author : nuclear852 ========================#
//# Solution : 5055978 =========================#
//# Time Stamp : 2017-01-19 10:55:09 ===========#
//# Problem Title : 역사 =====================#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
vector<int> v[403];
bool bfs(int a, int b);
int main(){
        int n, k;       cin>>n>>k;
        int a, b;
        for(int i=0; i<k; i++){
                scanf("%d %d",&a,&b);
                v[a].push_back(b);}
        int s;  cin>>s;
        while(s--){
                scanf("%d %d", &a, &b);
                int ans = 0;
                if( bfs(a,b) == 1)      ans = -1;
                if( bfs(b,a) == 1)      ans = 1;
                cout<<ans<<'\n';
        }
}


bool bfs(int a, int b){
        bool visited[403];      memset(visited,0, sizeof(visited));
        queue<int> q;
        bool ans = 0;   int m;
        q.push(a);      visited[a] = 1;
        while(!q.empty()){
                m = q.front();  q.pop();
                if(m==b)        {ans = 1; break;}
                for(int i=0; i<v[m].size(); i++){
                        if( visited[ v[m][i] ] == 1)    continue;
                        q.push( v[m][i] );      visited[ v[m][i] ] = 1;
                }
        }
        return ans;
}