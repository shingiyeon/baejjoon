//# Author : nuclear852 ========================#
//# Solution : 5215857 =========================#
//# Time Stamp : 2017-02-14 13:49:45 ===========#
//# Problem Title : 상어의 저녁식사 ===============#
//# Language : C++98 ===========================#

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
int map[2005][2005];
int N;
bool visited[2005];
struct shark{
        int size;
        int speed;
        int IQ;
};
bool dfs(int p){
        //cout<<p<<" "<<mn<<"\n";
        if( p == 2*N+1) return 1;
        visited[p] = 1;
        bool pos = 0;
        for(int i=1; i<=2*N+1; i++){
                if(!visited[i] && map[p][i] > 0){
                        visited[i] = 1;
                        pos = dfs(i);
                        if(pos) { map[p][i]--; map[i][p]++; break;}
                }
        }
        return pos;
}

int main(){
        cin>>N;
        struct shark s[1005];
        for(int i=1; i<=N; i++){
                scanf("%d%d%d", &s[i].size, &s[i].speed, &s[i].IQ);
                map[0][i] = 2;
                map[N+i][2*N+1] = 1;
        }
        for(int i=1; i<=N; i++){
                for(int j=1; j<=N; j++){
                        if(i==j) continue;
                        else if(i>j && s[i].size==s[j].size && s[i].speed==s[j].speed && s[i].IQ == s[j].IQ) continue;
                        else if(s[i].size >= s[j].size && s[i].speed >= s[j].speed && s[i].IQ >= s[j].IQ) map[i][N+j] = 1;
                }
        }
        int cnt = 0;
        while(1){
                memset(visited,0,sizeof(visited));
                bool pos = dfs(0);
                if(!pos) break;
                else cnt++;
        }
        //int ans = 0;
        //for(int i=1; i<=N; i++) ans += map[2*N+1][N+i];
        cout<<N-cnt;
}