//# Author : nuclear852 ========================#
//# Solution : 5037525 =========================#
//# Time Stamp : 2017-01-17 10:15:09 ===========#
//# Problem Title : 나이트의 이동 ================#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
#include <queue>
#include <utility>
#include <string.h>
using namespace std;
int main(){
        int N; cin>>N;
        int l;
        int sx, sy;
        int fx, fy;
        int x, y, num;
        bool visited[305][305];
        int dx[8] = {-2,-1,1,2,2,1,-1,-2};
        int dy[8] = {1,2,2,1,-1,-2,-2,-1};
        pair<int, int> xy;
        pair< pair<int, int>, int> p;   queue< pair< pair<int, int>, int> > q;
        while(N--){
                cin>>l>>sx>>sy>>fx>>fy;
                while( !q.empty() ) q.pop();
                memset(visited,0,sizeof(visited));
                visited[sx][sy] = 1;
                xy.first = sx;  xy.second = sy; p.first = xy; p.second = 0; q.push(p);
                while(!q.empty()){
                        p = q.front();  xy = p.first; num = p.second; x = xy.first; y = xy.second; q.pop();
                        if( x==fx && y==fy){
                                cout<<num<<endl;
                                break;}
                        for(int i=0; i<8; i++){
                                if( x+dx[i] < 0 || x+dx[i] >= l || y+dy[i] < 0 || y+dy[i] >= l)
                                        continue;
                                if( visited[ x+dx[i] ][y +dy[i]] == 1)
                                        continue;
                                visited[x+dx[i]][y+dy[i]] = 1;xy.first = x+dx[i]; xy.second = y+dy[i]; p.first = xy; p.second = num+1; q.push(p);}
                }
        }
}