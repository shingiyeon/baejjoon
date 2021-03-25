//# Author : nuclear852 ========================#
//# Solution : 5086546 =========================#
//# Time Stamp : 2017-01-23 16:23:20 ===========#
//# Problem Title : 달이 차오른다, 가자. ===========#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;

struct state{
        int x, y;
        int key;
        int num;
};

int main(){
        struct state s;
        int N, M;       cin>>N>>M;
        bool visited[51][51][1<<7];     memset(visited,0,sizeof(visited));
        char map[51][51];
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = { 0, 0, -1, 1};
        int ans=-1;
        queue<struct state> q;
        for(int i=0; i<N; i++){
                scanf("%s",map[i]);
                for(int j=0; j<M; j++){
                        if(map[i][j] == '0'){
                                s.x = i; s.y = j; s.key = 0;
                                s.num=0;
                        }
                }
        }
        q.push(s);      visited[s.x][s.y][0] = 1;
        while(!q.empty()){
                s = q.front();  q.pop();
                int tmpstate = s.key;
                if( map[s.x][s.y] == '1'){      ans = s.num; break; }
                if( map[s.x][s.y] >= 'a' && map[s.x][s.y] <= 'f')
                        tmpstate = (tmpstate | (1<<(map[s.x][s.y]-'a')));
        //      cout<<s.x<<" "<<s.y<<" "<<tmpstate<<" "<<s.num<<endl;
                for(int i=0; i<4; i++){
                        int qdx = s.x+dx[i];    int qdy=s.y+dy[i];
                        if(qdx<0||qdx>=N||qdy<0||qdy>=M)        continue;
                        if(visited[qdx][qdy][tmpstate] == 1)    continue;
                        if(map[qdx][qdy] >= 'A' && map[qdx][qdy] <='F')
                                if( (tmpstate & (1<<(map[qdx][qdy]-'A'))) == 0) continue;
                        if(map[qdx][qdy] == '#')        continue;
                        visited[qdx][qdy][tmpstate] = 1;
                        struct state temp;
                        temp.x=qdx;     temp.y=qdy;     temp.key=tmpstate;      temp.num = s.num+1;
                        q.push(temp);
                }
        }
        cout<<ans<<endl;
}