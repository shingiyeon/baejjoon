//# Author : nuclear852 ========================#
//# Solution : 5070681 =========================#
//# Time Stamp : 2017-01-21 01:40:13 ===========#
//# Problem Title : 성곽 =====================#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
#include <queue>
#include <utility>
#include <string.h>
using namespace std;

bool v1[54][54];
int ans1=0;
int map[54][54];
int SENW[4] = {8,4,2,1};
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
queue< pair<int, int> > q;
int m,n,x,y;

int dfs(){
        int ans2=0;
        memset(v1,0,sizeof(v1));
        for(int i=1; i<=n; i++){
                for(int j=1; j<=m; j++){
                        if(v1[i][j] == 0){
                                int temp = 0;
                                q.push(make_pair(i,j)); v1[i][j] = 1;
                                while(!q.empty()){
                                        x = q.front().first; y = q.front().second; temp++; q.pop();
                                        int info = map[x][y];
                                        for(int i=0; i<4; i++){
                                                if(info >= SENW[i]) {info-=SENW[i]; continue;}
                                                if( x+dx[i]<1 || x+dx[i]>n || y+dy[i]<1 || y+dy[i]>m) continue;
                                                if(v1[x+dx[i]][y+dy[i]] == 1)   continue;
                                                q.push(make_pair(x+dx[i],y+dy[i]));  v1[x+dx[i]][y+dy[i]] = 1;
                                        }
                                }
                                if(temp>ans2) ans2=temp;
                                ans1++;
                        }
                }
        }
        return ans2;
}

int main(){
        cin>>m>>n;
        int ans = 0; int ans2 = 0; int ans3 = 0;
        for(int i=1; i<=n; i++){
                for(int j=1; j<=m; j++){
                        scanf("%d",&map[i][j]);
                }
        }
        int temp;
        ans2 = dfs();
        ans = ans1;
        for(int i=1; i<=n; i++){
                for(int j=1; j<=m; j++){
                        int info = map[i][j];
                        for(int a=0; a<4; a++){
                                if(info>=SENW[a]){
                                        map[i][j]-=SENW[a]; temp = dfs();
                                        if(temp>ans3)   ans3 = temp;
                                        map[i][j]+=SENW[a]; info -=SENW[a];
                                }
                        }
                }
        }
        cout<<ans<<'\n'<<ans2<<'\n'<<ans3;
}