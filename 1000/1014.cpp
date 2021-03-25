//# Author : nuclear852 ========================#
//# Solution : 5262741 =========================#
//# Time Stamp : 2017-02-22 10:48:01 ===========#
//# Problem Title : 컨닝 =====================#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <utility>
using namespace std;

int M, N;
bool visited[105];
bool map[105][105];
int aMatched[105], bMatched[105];
char arr[15][15];
pair<int, int> pleft[105];
pair<int, int> pright[105];

bool dfs(int p){
        if(visited[p]) return 0;
        visited[p] = 1;
        for(int i=0; i<N; i++){
                if( map[p][i] ){
                        if( bMatched[i] == -1 || dfs(bMatched[i]) ){
                                bMatched[i] = p;
                                aMatched[p] = i;
                                return 1;
                        }
                }
        }
        return 0;
}

int main(){
        int T; cin>>T;
        int dy[4] = {-1, -1, 1, 1};
        int dx[4] = {-1, 0, 0, -1};
        while(T--){
                memset(map,0,sizeof(map));
                M=0; N=0;
                int n, m;
                scanf("%d%d",&n,&m);
                for(int i=0; i<n; i++) scanf("%s",arr[i]);
                for(int i=0; i<m; i+=2){
                        for(int j=0; j<n; j++){
                                if(arr[j][i] == '.')
                                        pleft[M++] = make_pair(j,i);
                        }
                }
                for(int i=1; i<m; i+=2){
                        for(int j=0; j<n; j++){
                                if(arr[j][i] == '.')
                                        pright[N++] = make_pair(j,i);
                        }
                }
                for(int i=0; i<M; i++){
                        for(int j=0; j<N; j++){
                                int lx = pleft[i].first; int ly = pleft[i].second;
                                int rx = pright[j].first; int ry = pright[j].second;

                                for(int k=0; k<4; k++){
                                        if( lx+dx[k] == rx && ly+dy[k] == ry)  map[i][j] = 1;
                                        if( rx+dx[k] == lx && ry+dy[k] == ly)  map[i][j] = 1;
                                }
                        }
                }
                int size = 0;
                memset(bMatched,-1,sizeof(bMatched));
                for(int i=0; i<M; i++){
                        memset(visited,0,sizeof(visited));
                        size += dfs(i);
                }
                printf("%d\n",M+N-size);
        }
}