//# Author : nuclear852 ========================#
//# Solution : 5054181 =========================#
//# Time Stamp : 2017-01-19 00:52:45 ===========#
//# Problem Title : 적록색약 ===================#
//# Language : C++98 ===========================#

#include <iostream>
#include <queue>
#include <utility>
#include <stdio.h>
#include <string.h>
using namespace std;
struct inf{
        int x, y; char c;
}info;
int N;
bool visited[103][103];
char map[103][103];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int ax, ay, ac;
queue< struct inf > q;
int ans = 0;
void bfs();

int main(){
        cin>>N;
        memset(visited,0,sizeof(visited));
        for(int i=0; i<N; i++)  scanf("%s",map[i]);
        bfs();  cout<<ans<<" "; memset(visited,0,sizeof(visited)); ans = 0;
        for(int i=0; i<N; i++){
                for(int j=0; j<N; j++){
                        if(map[i][j] == 'G')
                                map[i][j] = 'R';
                }
        }
        bfs();  cout<<ans<<endl;
}

void bfs(){
        for(int i=0; i<N; i++){
                for(int j=0; j<N; j++){
                        if(visited[i][j] == 0){
                                info.x = i; info.y = j; info.c = map[i][j]; q.push(info); visited[i][j] = 1;
                                while(!q.empty()){
                                        info = q.front(); ax = info.x; ay=info.y; ac = info.c; q.pop();
                                        for(int a=0; a<4; a++){
                                                if( dx[a]+ax < 0 || dx[a]+ax >= N || dy[a]+ay < 0 || dy[a]+ay >=N)      continue;
                                                if( visited[dx[a]+ax][dy[a]+ay] == 1)   continue;
                                                if( map[dx[a]+ax][dy[a]+ay] != ac )     continue;
                                                info.x = dx[a]+ax;      info.y = dy[a]+ay;      info.c = ac;
                                                visited[ dx[a]+ax ][ dy[a]+ay ] = 1;    q.push(info);
                                        }
                                }
                                ans++;
                        }
                }
        }
}