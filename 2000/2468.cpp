//# Author : nuclear852 ========================#
//# Solution : 5037822 =========================#
//# Time Stamp : 2017-01-17 10:57:42 ===========#
//# Problem Title : 안전 영역 ==================#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <queue>
using namespace std;
int main(){
        int N; cin>>N;
        int num = 0;
        int map[105][105];
        bool visited[105][105];
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) scanf("%d",&map[i][j]);
        pair<int, int> xy; queue< pair<int, int> > q;
        int x, y;
        int max = 0;
        for(int k=0; k<=100; k++)
        {
                num = 0;
                memset(visited,0,sizeof(visited));
                for(int i=1; i<=N; i++){
                        for(int j=1; j<=N; j++){
                                if( map[i][j] <= k ) visited[i][j] = 1;}}
                for(int i=1; i<=N; i++){
                        for(int j=1; j<=N; j++){
                                if(visited[i][j] == 0){
                                        xy.first = i; xy.second = j; q.push(xy); visited[i][j] = 1;
                                        while( !q.empty()){
                                                xy = q.front(); x= xy.first; y= xy.second; q.pop();
                                                for(int a=0; a<4; a++){
                                                        if( x+dx[a] <=0 || x+dx[a] >N || y+dy[a] <=0 || y+dy[a] >N)
                                                                continue;
                                                        if( visited[ x+dx[a]][y+dy[a]] == 1)
                                                                continue;
                                                        xy.first = x+dx[a]; xy.second = y+dy[a]; q.push(xy); visited[x+dx[a]][y+dy[a]] = 1;
                                                }
                                        }
                                        num++;
                                }
                        }
                }
                if(num > max) max = num;
        }
        cout<<max<<endl;
}