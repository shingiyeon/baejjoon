//# Author : nuclear852 ========================#
//# Solution : 5077426 =========================#
//# Time Stamp : 2017-01-22 11:14:46 ===========#
//# Problem Title : 맥주 마시면서 걸어가기 ===========#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
#include <utility>
#include <queue>
#include <stdlib.h>
#include <string.h>
using namespace std;
struct sp{
        int x; int y;
};

int main(){
        int T; cin>>T;
        while(T--){
                bool pos = 0;
                int n; cin>>n;
                queue<struct sp> q;
                bool visited[102];      memset(visited,0,sizeof(visited));
                struct sp p[102];
                struct sp s;    scanf("%d %d",&s.x,&s.y);
                struct sp e;
                for(int i=0; i<n; i++)
                        scanf("%d %d",&p[i].x,&p[i].y);
                scanf("%d %d",&e.x, &e.y);
                q.push(s);
             /*   for(int i=0; i<n; i++){
                        if( abs(p[i].x-s.x) + abs(p[i].y-s.y) <= 1000 ){
                                q.push(p[i]);
                                visited[i] = 1;
                        }
                }*/
                while(!q.empty()){
                        struct sp temp = q.front(); q.pop();
                        if( abs(temp.x-e.x) + abs(temp.y-e.y) <= 1000 ){ pos = 1; break;}
                        for(int i=0; i<n; i++){
                                if( visited[i] == 1)    continue;
                                if( abs(p[i].x-temp.x) + abs(p[i].y-temp.y) > 1000 ) continue;
                                q.push(p[i]); visited[i] = 1;
                        }
                }
                if(pos) cout<<"happy"<<'\n';
                else cout<<"sad"<<'\n';
        }
}