//# Author : nuclear852 ========================#
//# Solution : 5158883 =========================#
//# Time Stamp : 2017-02-04 12:47:28 ===========#
//# Problem Title : 섬의 개수 ==================#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <utility>
using namespace std;
int main(){
        int w,h; cin>>w>>h;
        int dx[8]={-1,-1,-1,0,0,1,1,1};
        int dy[8]={-1,0,1,1,-1,-1,0,1};
        while( !(w==0&&h==0) ){
                int map[50][50];
                bool visited[50][50];  memset(visited,0,sizeof(visited));
                for(int i=0; i<h; i++) for(int j=0; j<w; j++) scanf("%d",&map[i][j]);
                int num = 0;
                queue<pair<int, int> > q;
                for(int i=0; i<h; i++){
                        for(int j=0; j<w; j++){
                                if(map[i][j] == 1 && visited[i][j] == 0){
                                        visited[i][j] = 1;
                                        q.push(make_pair(i,j));
                                        while(!q.empty()){
                                                int x = q.front().first; int y = q.front().second;
                                                q.pop();
                                                for(int k=0; k<8; k++){
                                                        if(x+dx[k] < 0 || x+dx[k] >= h || y+dy[k] < 0 || y+dy[k] >= w) continue;
                                                        if(visited[x+dx[k]][y+dy[k]]==1) continue;
                                                        if(map[x+dx[k]][y+dy[k]] == 0) continue;
                                                        q.push(make_pair(x+dx[k],y+dy[k])); visited[x+dx[k]][y+dy[k]] = 1;
                                                }
                                        }
                                        num++;
                                }
                        }
                }
                printf("%d\n",num);
                scanf("%d %d",&w,&h);
        }
}