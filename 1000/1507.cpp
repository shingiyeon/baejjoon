//# Author : nuclear852 ========================#
//# Solution : 5216323 =========================#
//# Time Stamp : 2017-02-14 14:42:34 ===========#
//# Problem Title : 궁금한 민호 =================#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
#include <utility>
#include <string.h>
#include <algorithm>
#define MAX 250000
using namespace std;
int main(){
        int N; cin>>N;
        int sum = 0;
        int asmap[21][21];
        int map[21][21];
        bool visited[21][21];
        memset(visited,0,sizeof(visited));
        for(int i=0; i<N; i++) for(int j=0; j<N; j++) scanf("%d",&asmap[i][j]);
        for(int i=0; i<N; i++) for(int j=0; j<N; j++) { if(i==j) {map[i][j]=0; visited[i][j] = 1;} else map[i][j] = MAX;}
        bool pos = 1;
        int ans = 0;
        do{
                pos = 1;
                pair<int, int> p;
                int mn = MAX;
                for(int i=0; i<N; i++){
                        for(int j=0; j<N; j++){
                                for(int k=0; k<N; k++){
                                        if( map[j][k] > map[j][i] + map[i][k] ){
                                                map[j][k] = map[j][i] + map[i][k];
                                        }
                                }
                        }
                }
                for(int i=0; i<N; i++){
                        for(int j=0; j<N; j++){
                                if( map[i][j] < asmap[i][j]) {cout<<"-1"; return 0;}
                                if( map[i][j] != asmap[i][j]) pos = 0;
                        }
                }
                if(!pos){
                        for(int i=0; i<N; i++){
                                for(int j=0; j<N; j++){
                                        if( map[i][j] != asmap[i][j] &&mn > asmap[i][j] && !visited[i][j]){
                                                mn = asmap[i][j];
                                                p.first = i; p.second = j;
                                        }
                                }
                        }
                        visited[p.first][p.second] = 1;
                        map[p.first][p.second] = mn;
                        ans += mn;
                }
        }while(!pos);
        cout<<ans/2;
}