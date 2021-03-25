//# Author : nuclear852 ========================#
//# Solution : 5062823 =========================#
//# Time Stamp : 2017-01-20 00:56:40 ===========#
//# Problem Title : 불 ======================#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <utility>
using namespace std;
struct inf{
        int x, y, t;
};

int main(){
        int T; cin>>T;
        while(T--){
                int w, h; cin>>w>>h;
                char map[1003][1003];
                bool visited[1003][1003];       memset(visited,0,sizeof(visited));
                bool fvisited[1003][1003];      memset(fvisited,0,sizeof(fvisited));
                int dx[4] = {-1, 0, 1, 0};
                int dy[4] = { 0, 1, 0,-1};
                int tx, ty, tt;
                int fx, fy;
                struct inf info;
                bool pos = 0;
                int ans;
                int ft = -1;
                queue< struct inf > dog;
                queue< pair<int,int> > fire;
                for(int i=0; i<h; i++){
                        scanf("%s", map[i]);
                        for(int j=0; j<w; j++){
                                if(map[i][j] == '@'){
                                        info.x = i; info.y = j; info.t = 0;
                                        visited[i][j] = 1; dog.push(info);}
                                if(map[i][j] == '*'){
                                        fvisited[i][j] = 1;
                                        fire.push(make_pair(i,j));}
                        }
                }
                while( !dog.empty() ){
                        info = dog.front();     dog.pop();
                        tx=info.x; ty=info.y; tt=info.t;
                        if(tx<0 || tx>=h || ty<0 || ty>=w){
                                pos = 1; ans = tt; break;}
                        if(ft < tt){
                                int num = fire.size();
                                for(int i=0; i<num; i++){
                                        fx = fire.front().first; fy = fire.front().second; fire.pop();
                                        for(int j=0; j<4; j++){
                                                if( fx+dx[j] < 0 || fx+dx[j] >= h || fy+dy[j] <0 || fy+dy[j] >= w)      continue;
                                                if( fvisited[fx+dx[j]][fy+dy[j]] == 1)  continue;
                                                if( map[fx+dx[j]][fy+dy[j]] == '#')     continue;
                                                fire.push(make_pair(fx+dx[j],fy+dy[j])); fvisited[fx+dx[j]][fy+dy[j]] = 1;
                                                map[fx+dx[j]][fy+dy[j]] = '*';
                                        }
                                }
                                ft++;
                        }
                        for(int i=0; i<4; i++){
                                if( tx+dx[i] < 0 || tx+dx[i] >= h || ty+dy[i] < 0 || ty+dy[i] >= w){
                                        pos = 1; ans=tt+1; break;}
                                if(visited[tx+dx[i]][ty+dy[i]] == 1) continue;
                                if( map[tx+dx[i]][ty+dy[i]] == '#' || map[tx+dx[i]][ty+dy[i]] == '*') continue;
                                info.x = tx+dx[i]; info.y=ty+dy[i]; info.t=tt+1; dog.push(info); visited[tx+dx[i]][ty+dy[i]] = 1;
                        }
                        if(pos==1) break;
                }
                if(pos) cout<<ans<<'\n';
                else cout<<"IMPOSSIBLE"<<'\n';
        }
}