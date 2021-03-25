//# Author : nuclear852 ========================#
//# Solution : 5047767 =========================#
//# Time Stamp : 2017-01-18 12:37:05 ===========#
//# Problem Title : 벽 부수고 이동하기 =============#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

struct inf{
        int x, y, t;
        bool b;
};
int main(){
        int N, M;       cin>>N>>M;
        int dx[4] = {-1, 0, 1 , 0};
        int dy[4] = {0, -1, 0, 1};
        char map[1005][1005];
        bool visited[1005][1005][2];    memset(visited,0,sizeof(visited));
        struct inf a;
        int qx, qy, qt; bool qb;
        int dqx, dqy;
        queue< struct inf > q;
        for(int i=0; i<N; i++)  scanf("%s",map[i]);
        a.x = 0; a.y =0; a.t = 1; a.b = 0;
        visited[0][0][0] = 1;
        q.push(a);
        while( !q.empty()){
                a = q.front();  qx = a.x; qy = a.y; qt = a.t; qb = a.b; q.pop();
                if( qx == N-1 && qy == M-1){    cout<<qt;       return 0;}
                for(int i=0; i<4; i++){
                        dqx = qx + dx[i];       dqy = qy + dy[i];
                        if( dqx<0 || dqx>=N || dqy<0 || dqy>=M) continue;
                        if(qb == 0){
                                if( map[dqx][dqy] == '1'){
                                        a.x = dqx;      a.y = dqy;      a.t = qt+1;     a.b = 1;
                                        visited[dqx][dqy][1] = 1;       q.push(a);}
                        }
                        if( map[dqx][dqy] == '1' || visited[dqx][dqy][qb] == 1) continue;
                        a.x = dqx;      a.y = dqy;      a.t = qt+1;     a.b = qb;
                        visited[dqx][dqy][qb] = 1;      q.push(a);
                }
        }
        cout<<"-1"<<endl;
        return 0;
}