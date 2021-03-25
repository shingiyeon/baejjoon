//# Author : nuclear852 ========================#
//# Solution : 5057308 =========================#
//# Time Stamp : 2017-01-19 14:03:52 ===========#
//# Problem Title : 로봇 =====================#
//# Language : C++98 ===========================#

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <utility>
using namespace std;
struct inf{
        int x, y, d;
        int num;
}info;
int main(){
        int dirx[5] = {0, 0, 0, 1, -1};
        int diry[5] = {0, 1, -1, 0, 0};
        int M, N;       cin>>M>>N;
        bool map[103][103];
        bool visited[103][103][5];      memset(visited,0,sizeof(visited));
        queue< struct inf > q;
        for(int i=1; i<=M; i++) for(int j=1; j<=N; j++) scanf("%d",&map[i][j]);
        int sx, sy, sd, fx, fy, fd, tx, ty, td, tn;
        int tdx, tdy;
        scanf("%d %d %d",&sx,&sy,&sd);
        scanf("%d %d %d",&fx,&fy,&fd);
        info.x = sx;    info.y = sy;    info.d = sd;    info.num = 0;   q.push(info);
        visited[sx][sy][sd] = 1;
        while(!q.empty()){
                info = q.front();
                tx = info.x;    ty = info.y;    td = info.d;    tn = info.num;  q.pop();
                if(tx==fx&&ty==fy&&td==fd){     cout<<tn;       return 0;}
                int temp = 1;
                while(1){
                        tdx = tx+(temp*dirx[td]);       tdy = ty+(temp*diry[td]);
                        if( tdx < 1 || tdx > M || tdy < 1 || tdy > N)   break;
                        if( map[tdx][tdy] == 1) break;
                        if(temp>= 4) break;
                        if( visited[tdx][tdy][td] == 1) temp++;
                        else{
                                visited[tdx][tdy][td] = 1;
                                info.x = tdx;   info.y = tdy;   info.d = td;    info.num = tn+1;
                                q.push(info);
                                temp++;
                        }
                }

                int i = ((td == 3 || td == 4) ? 1 : 3);
                if( visited[tx][ty][i] == 0){
                        visited[tx][ty][i] = 1;
                        info.x = tx;    info.y = ty;    info.d = i;     info.num = tn+1;
                        q.push(info);
                }
                i++;
                if(visited[tx][ty][i] == 0){
                        visited[tx][ty][i] = 1;
                        info.x = tx;    info.y = ty;    info.d = i;     info.num = tn+1;
                        q.push(info);
                }
        }
}