//# Author : nuclear852 ========================#
//# Solution : 5062127 =========================#
//# Time Stamp : 2017-01-19 23:00:25 ===========#
//# Problem Title : 물통 =====================#
//# Language : C++98 ===========================#

#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#include <stdio.h>
using namespace std;
struct water{
        int A, B, C;
};
bool visited[203][203][203];
queue< struct water > q;
struct water w;

int main(){
        memset(visited,0,sizeof(visited));
        cin>>w.A>>w.B>>w.C;
        bool pos[203];  memset(pos,0,sizeof(pos));
        struct water s; s.A = 0;        s.B = 0;        s.C = w.C;
        struct water r; struct water t;
        q.push(s);
        visited[0][0][w.C] = 1;
        while(!q.empty()){
                s  = q.front(); q.pop();
                r.A = w.A - s.A;        r.B = w.B - s.B;        r.C = w.C-s.C;
                if(s.A == 0){ pos[s.C] = 1;}
                if( s.A >= r.B){
                        if(visited[s.A-r.B][w.B][s.C] == 0){
                                visited[s.A-r.B][w.B][s.C] = 1;
                                t.A = s.A-r.B;  t.B = w.B; t.C = s.C;
                                q.push(t);
                        }
                }
                if( s.A < r.B){
                        if(visited[0][s.B+s.A][s.C] == 0){
                                visited[0][s.B+s.A][s.C] = 1;
                                t.A = 0;        t.B = s.B+s.A;  t.C = s.C;
                                q.push(t);
                        }
                }
                if( s.A >= r.C){
                        if(visited[s.A-r.C][s.B][w.C ] == 0){
                                visited[s.A-r.C][s.B][w.C] = 1;
                                t.A = s.A-r.C;  t.B=s.B;        t.C = w.C;
                                q.push(t);
                        }
                }
                if( s.A < r.C){
                        if(visited[0][s.B][s.C+s.A] == 0){
                                visited[0][s.B][s.C+s.A] = 1;
                                t.A = 0; t.B=s.B;       t.C = s.C+s.A;
                                q.push(t);}}
                if( s.B >= r.A){
                        if(visited[w.A][s.B-r.A][s.C] == 0){
                                visited[w.A][s.B-r.A][s.C] = 1;
                                t.A=w.A; t.B=s.B-r.A; t.C=s.C; q.push(t);}}
                if( s.B < r.A){
                        if(visited[s.A+s.B][0][s.C] == 0){
                                visited[s.A+s.B][0][s.C] = 1;
                                t.A=s.A+s.B; t.B=0; t.C = s.C; q.push(t);}}
                if( s.B >= r.C){
                        if(visited[s.A][s.B-r.C][w.C] == 0){
                                visited[s.A][s.B-r.C][w.C] = 1;
                                t.A=s.A; t.B=s.B-r.C; t.C = w.C; q.push(t);}}
                if(s.B < r.C){
                        if(visited[s.A][0][s.C+s.B] == 0){
                                visited[s.A][0][s.C+s.B] = 1;
                                t.A=s.A; t.B=0; t.C=s.C+s.B; q.push(t);}}
                if(s.C >= r.A){
                        if(visited[w.A][s.B][s.C-r.A] == 0){
                                visited[w.A][s.B][s.C-r.A] = 1;
                                t.A=w.A; t.B=s.B; t.C=s.C-r.A; q.push(t);}}
                if(s.C < r.A){
                        if(visited[s.A+s.C][s.B][0] == 0){
                                visited[s.A+s.C][s.B][0] == 1;
                                t.A=s.A+s.C; t.B=s.B; t.C=0; q.push(t);}}
                if(s.C >=r.B){
                        if(visited[s.A][w.B][s.C-r.B] == 0){
                                visited[s.A][w.B][s.C-r.B] = 1;
                                t.A= s.A; t.B=w.B; t.C=s.C-r.B; q.push(t);}}
                if(s.C <r.B){
                        if(visited[s.A][s.B+s.C][0] == 0){
                                visited[s.A][s.B+s.C][0] = 1;
                                t.A=s.A; t.B=s.B+s.C; t.C=0;    q.push(t);}}
        }
        for(int i=0; i<=200; i++){
                if(pos[i] == 1){
                        cout<<i<<" ";
                }
        }
        return 0;
}