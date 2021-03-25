//# Author : nuclear852 ========================#
//# Solution : 5054341 =========================#
//# Time Stamp : 2017-01-19 01:22:12 ===========#
//# Problem Title : 다리 만들기 =================#
//# Language : C++98 ===========================#

#include <iostream>
#include <utility>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
int main(){
        bool visited[103][103]; memset(visited, 0, sizeof(visited));
        int map[103][103];
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        int n; cin>>n;
        int cmap[103][103]; int num = 1;
        int x, y;
        pair<int, int> xy;      queue< pair<int, int> > q;
        for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) {scanf("%d",&map[i][j]); if(map[i][j] == 0) cmap[i][j] = 0;}
        for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                        if(map[i][j] ==1 && visited[i][j] == 0){
                                xy.first = i;   xy.second = j; q.push(xy); visited[i][j] = 1; cmap[i][j] =num;
                                while(!q.empty()){
                                        xy = q.front();
                                        x = xy.first; y = xy.second; q.pop();
                                        for(int a=0; a<4; a++){
                                                if( visited[x+dx[a]][y+dy[a]] == 1)     continue;
                                                if( map[x+dx[a]][y+dy[a]] == 0) continue;
                                                xy.first = x+dx[a]; xy.second = y+dy[a];
                                                visited[x+dx[a]][y+dy[a]] = 1;
                                                cmap[x+dx[a]][y+dy[a]] = num;
                                                q.push(xy);
                                        }
                                }
                                num++;
                        }
                }
        }
        int len = 99999999;
        for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                        if(map[i][j] != 0){
                                for(x=1; x<=n; x++){
                                        for(y=1; y<=n; y++){
                                                if( cmap[i][j] != cmap[x][y] && cmap[x][y] != 0){
                                                        int templen = abs(x-i)+abs(y-j)-1;
                                                        if(templen < len)       len = templen;
                                                }
                                        }
                                }
                        }
                }
        }
        cout<<len<<endl;
}