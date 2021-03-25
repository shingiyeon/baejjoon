//# Author : nuclear852 ========================#
//# Solution : 5038919 =========================#
//# Time Stamp : 2017-01-17 13:41:14 ===========#
//# Problem Title : 케빈 베이컨의 6단계 법칙 =========#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
#include <vector>
#include <utility>
#include <string.h>
#include <queue>
using namespace std;
int main(){
        int N, M; cin>>N>>M;
        vector<int> rel[103];
        bool visited[103];
        pair<int, int> p;
        queue< pair<int,int> > q;
        int x,y;
        for(int i=0; i<M; i++){
                scanf("%d %d",&x,&y);
                rel[x].push_back(y);
                rel[y].push_back(x);
        }
        int ans;
        int min = 99999999;
        for(int i=1; i<=N; i++){
                int tmpm = 0;
                memset(visited,0,sizeof(visited));
                p.first = i; p.second = 0; visited[i] = 1; q.push(p);
                while( !q.empty()){
                        p = q.front(); x = p.first; y = p.second; q.pop();
                        tmpm += y;
                        for(int j=0; j<rel[x].size(); j++)
                        {
                                if( visited[ rel[x][j] ] == 1) continue;
                                p.first = rel[x][j];
                                p.second = y+1;
                                visited[ rel[x][j] ] = 1;
                                q.push(p);
                        }
                }
                if(tmpm < min) {min = tmpm; ans = i;}
        }
        cout<<ans<<endl;
}