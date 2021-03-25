//# Author : nuclear852 ========================#
//# Solution : 5047305 =========================#
//# Time Stamp : 2017-01-18 11:23:06 ===========#
//# Problem Title : 탈출 =====================#
//# Language : C++98 ===========================#

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <utility>
#include <queue>
using namespace std;
int main(){
        int fx, fy, x, y, t, wx, wy;
        int wt = -1;
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        pair<int, int> xy;
        pair< pair<int, int>, int > inf;
        queue< pair<int, int> > water;
        queue< pair< pair<int, int>, int> > q;
        int R, C;       cin>>R>>C;
        char map[53][53];
        bool v[53][53]; memset(v,0,sizeof(v));
        for(int i=0; i<R; i++) scanf("%s",map[i]);
        for(int i=0; i<R; i++){
                for(int j=0; j<C; j++){
                        if( map[i][j] == 'S'){
                                xy.first = i; xy.second = j; inf.first = xy; inf.second = 0; q.push(inf); v[i][j] = 1;}
                        else if( map[i][j] == 'D'){
                                fx = i; fy = j;}
                        else if( map[i][j] == '*'){
                                xy.first = i; xy.second = j; water.push(xy);}
                }
        }
        while( !q.empty()){
                inf = q.front(); xy = inf.first; t= inf.second; x = xy.first; y = xy.second; q.pop();
                if( x==fx && y==fy){    cout<<t<<endl; return 0; }
                if(wt<t){
                        int tmp = water.size();
                        for(int i=0; i<tmp; i++)
                        {
                                xy = water.front(); wx = xy.first; wy = xy.second; water.pop();
                                for(int j=0; j<4; j++){
                                        if( wx+dx[j] < 0 || wx+dx[j]>=R || wy+dy[j] < 0 || wy+dy[j] >=C )  continue;
                                        if( map[ wx+dx[j] ][ wy+dy[j]] == '*')  continue;
                                        if( map[ wx+dx[j] ][ wy+dy[j]] == 'X' || map[ wx+dx[j] ][wy+dy[j]] == 'D') continue;
                                        xy.first = wx+dx[j]; xy.second = wy+dy[j]; map[wx+dx[j]][wy+dy[j]] = '*'; water.push(xy);
                                }
                        }
                        wt = t;
                }
                for(int i=0; i<4; i++)
                {
                        if( x+dx[i] < 0 || x+dx[i] >=R || y+dy[i] < 0 || y+dy[i] >=C)   continue;
                        if( map[ x+dx[i]][y+dy[i]] == '*' || map[ x+dx[i]][y+dy[i]] == 'X') continue;
                        if( v[ x+dx[i]][y+dy[i]] == 1)  continue;
                        xy.first = x+dx[i];     xy.second = y+dy[i];    inf.first= xy;  inf.second = t+1;       v[ x+dx[i]][y+dy[i]] = 1;       q.push(inf);
                }
        }

        cout<<"KAKTUS"<<endl;
        return 0;
}