//# Author : nuclear852 ========================#
//# Solution : 5045536 =========================#
//# Time Stamp : 2017-01-18 01:58:53 ===========#
//# Problem Title : 스타트링크 ==================#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
#include <queue>
#include <utility>
#include <string.h>
using namespace std;
int main(){
        int F,S,G,U,D;  cin>>F>>S>>G>>U>>D;
        pair<int, int> p;       queue< pair<int, int> > q;
        int x, y;
        bool visited[1000005];  memset(visited, 0, sizeof(visited));
        p.first = S;    p.second = 0;   q.push(p);      visited[S] = 1;
        while( !q.empty() ){
                p = q.front(); x = p.first; y = p.second; q.pop();
                if( x == G){ cout<<y; return 0;}
                if( x+U <= F){
                        if( visited[x+U] == 0){
                                p.first = x+U;  p.second = y+1; q.push(p); visited[x+U] = 1;}}
                if( x-D >= 1){
                        if( visited[x-D] == 0){
                                p.first = x-D;  p.second = y+1; q.push(p); visited[x-D] = 1;}}
        }
        cout<<"use the stairs"<<endl;
        return 0;
}