//# Author : nuclear852 ========================#
//# Solution : 5039227 =========================#
//# Time Stamp : 2017-01-17 14:12:57 ===========#
//# Problem Title : 보물섬 ====================#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
#include <utility>
#include <queue>
#include <string.h>
using namespace std;
int main(){
        bool visited[52][52];
        char map[53][53];
        pair<int, int> xy;      pair< pair<int, int>, int > p;
        queue< pair< pair<int, int>, int> > q;
        int M, N;       cin>>M>>N;
        int x, y, num;
        int dx[4] = { -1, 0, 1, 0};
        int dy[4] = { 0, 1, 0, -1};
        int max = 0;
        for(int i=0; i<M; i++) scanf("%s",map[i]);
        for(int i=0; i<M; i++){
                for(int j=0; j<N; j++){
                        if( map[i][j] == 'L'){
                                memset(visited,0,sizeof(visited));
                                visited[i][j] = 1;
                                xy.first = i;   xy.second = j;  p.first = xy;   p.second = 0;   q.push(p);
                                while( !q.empty()){
                                        p = q.front(); xy=p.first; x = xy.first; y = xy.second; num = p.second; q.pop();
                                        for(int a = 0; a<4; a++){
                                                if( x+dx[a] < 0 || x+dx[a] >= M || y+dy[a] < 0 || y+dy[a] >= N) continue;
                                                if( visited[ x+dx[a] ][ y+dy[a] ] == 1) continue;
                                                if( map[ x+dx[a] ][ y+dy[a] ] == 'W') continue;
                                                xy.first = x+dx[a]; xy.second = y+dy[a]; p.second = num+1; p.first = xy; visited[ x+dx[a] ][y+dy[a]] = 1; q.push(p);
                                        }
                                }
                                if( num > max)  max = num;
                        }
                }
        }
        cout<<max<<endl;
}