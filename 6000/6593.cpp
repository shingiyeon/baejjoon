//# Author : nuclear852 ========================#
//# Solution : 5085815 =========================#
//# Time Stamp : 2017-01-23 15:16:32 ===========#
//# Problem Title : 상범 빌딩 ==================#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;
struct i{
        int x,y,z,n;
};

int main(){
        int L,R,C;      cin>>L>>R>>C;
        while( !(L==0&&R==0&&C==0)){
                bool visited[32][32][32];       memset(visited,0,sizeof(visited));
                char map[32][32][32];
                int dx[6] = { -1, 1, 0, 0, 0, 0};
                int dy[6] = { 0, 0, -1, 1, 0, 0};
                int dz[6] = {0, 0,  0, 0, -1, 1};
                int ans=-1;
                struct i p;     struct i temp;
                queue<struct i> q;
                for(int i=0; i<L; i++) for(int j=0; j<R; j++){
                        scanf("%s",map[i][j]);
                        for(int k=0; k<C; k++){
                                if(map[i][j][k] == 'S'){
                                        p.x = i; p.y = j; p.z = k; p.n = 0;
                                        visited[i][j][k] = 1;
                                }
                        }
                }
                q.push(p);
                while(!q.empty()){
                        p = q.front(); q.pop();
                        if( map[p.x][p.y][p.z] == 'E')  {ans=p.n; break;}
                        for(int i=0; i<6; i++){
                                if(p.x+dx[i]<0||p.x+dx[i]>=L||p.y+dy[i]<0||p.y+dy[i]>=R||p.z+dz[i]<0||p.z+dz[i]>=C) continue;
                                if(visited[p.x+dx[i]][p.y+dy[i]][p.z+dz[i]] == 1) continue;
                                if(map[p.x+dx[i]][p.y+dy[i]][p.z+dz[i]] == '#') continue;
                                temp.x = p.x+dx[i]; temp.y = p.y+dy[i]; temp.z = p.z+dz[i]; temp.n = p.n+1;
                                visited[p.x+dx[i]][p.y+dy[i]][p.z+dz[i]] = 1;
                                q.push(temp);
                        }
                }
                if(ans+1) cout<<"Escaped in "<<ans<<" minute(s)."<<'\n';
                else    cout<<"Trapped!"<<'\n';
                cin>>L>>R>>C;
        }
}