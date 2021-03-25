//# Author : nuclear852 ========================#
//# Solution : 5048028 =========================#
//# Time Stamp : 2017-01-18 13:18:50 ===========#
//# Problem Title : 빙산 =====================#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
#include <vector>
#include <utility>
#include <queue>
#include <string.h>
using namespace std;
int main(){
        int N,M;        cin>>N>>M;
        bool visited[305][305];
        int map[305][305];
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = { 0, 1, 0,-1};
        pair<int, int> xy;
        queue< pair<int, int> > q;
        int x, y, qdx, qdy;
        int year = 0;
        for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) scanf("%d", &map[i][j]);
        while(1){
                vector< pair<int, int> > bye;
                vector< pair<int, int> > zero;
                memset(visited, 0, sizeof(visited));
                int num = 0;
                for(int i=1; i<=N; i++){
                        for(int j=1; j<=M; j++){
                                if( visited[i][j] == 0 && map[i][j] != 0){
                                        xy.first = i;   xy.second = j; bye.push_back(xy); q.push(xy); visited[i][j] = 1;
                                        while( !q.empty()){
                                                xy = q.front(); x = xy.first;   y = xy.second;  q.pop();
                                                for(int k=0; k<4; k++){
                                                        qdx = x + dx[k];        qdy = y + dy[k];
                                                        if( qdx < 1 || qdx > N || qdy < 1 || qdy > M)   continue;
                                                        if( map[qdx][qdy] == 0) continue;
                                                        if( visited[qdx][qdy] == 1) continue;
                                                        xy.first = qdx; xy.second = qdy; visited[qdx][qdy]=1; bye.push_back(xy);        q.push(xy);
                                                }
                                        }
                                        num++;
                                }
                        }
                }
                if(num >= 2)    {cout<<year<<endl; return 0;}
                if(bye.size() == 0){cout<<"0"<<endl;   return 0;}
                for(int i=0; i<bye.size(); i++){
                        xy = bye[i];    int zeronum = 0;
                        x = xy.first;   y = xy.second;
                        for(int j=0; j<4; j++){
                                qdx = x + dx[j];        qdy = y+dy[j];
                                if(map[qdx][qdy] == 0)  zeronum++;}
                        if( zeronum >= map[x][y] )      zero.push_back(xy);
                        else    map[x][y] -= zeronum;
                }
                for(int i=0; i<zero.size(); i++){
                        xy = zero[i];   x = xy.first;   y= xy.second;
                        map[x][y] = 0;}
                year++;
        }
        return 0;
}