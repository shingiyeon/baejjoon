//# Author : nuclear852 ========================#
//# Solution : 5026339 =========================#
//# Time Stamp : 2017-01-16 00:37:33 ===========#
//# Problem Title : 말이 되고픈 원숭이 =============#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>
#include <utility>
using namespace std;
int main()
{
        int dx[12] = {-1,0,1,0,-2,-1,1,2,2,1,-1,-2};
        int dy[12] = {0,1,0,-1,1,2,2,1,-1,-2,-2,-1};
        int K, W, H; cin>>K>>W>>H;
        bool visited[203][203][32]; memset(visited,0,sizeof(visited));
        bool map[203][203];     for(int i=1; i<=H; i++) for(int j=1; j<=W; j++) scanf("%d",&map[j][i]);
        queue< pair< pair<int, int>, pair<int, int> > > q;
        pair< pair<int, int>, pair<int, int> > inf;
        pair< int, int > xy;
        pair< int, int > infnum;
        int x; int y; int tmpk; int tmpn;
        xy.first = 1; xy.second = 1; inf.first=xy; infnum.first = 0; infnum.second = 0; inf.second = infnum; q.push(inf);
        visited[1][1][0] = 1;
        while( !q.empty()){
                inf = q.front();
                xy = inf.first; x = xy.first;   y = xy.second;  infnum = inf.second; tmpk = infnum.first; tmpn = infnum.second;
                q.pop();
                if (x == W && y == H){
                        cout<<tmpn<<endl;
                        return 0;
                }
                for(int i=0; i<12; i++){
                        if ( dx[i] + x < 1 || dx[i] + x > W || dy[i] + y < 1 || dy[i] + y > H ) continue;
                        if ( map[ dx[i]+ x ][ dy[i] + y] == 1)  continue;
                        if ( i >= 4 && visited[ dx[i]+x ][ dy[i]+y ][tmpk+1] == 1)      continue;
                        if ( i < 4 && visited[ dx[i]+x ][ dy[i]+y ][tmpk] == 1) continue;
                        if ( i >= 4 && tmpk+1 > K ) continue;
                        xy.first = x + dx[i];   xy.second = y + dy[i];  inf.first=xy; infnum.first = tmpk; infnum.second = tmpn+1;
                        if( i >= 4)
                                infnum.first = tmpk + 1;
                        inf.second = infnum;
                        visited[xy.first][xy.second][infnum.first] = 1;
                        q.push(inf);
                }
        }
        cout<<"-1"<<endl;
        return 0;
}