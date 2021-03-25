//# Author : nuclear852 ========================#
//# Solution : 5035926 =========================#
//# Time Stamp : 2017-01-17 00:52:59 ===========#
//# Problem Title : 토마토 ====================#
//# Language : C++98 ===========================#

#include <iostream>
#include <queue>
#include <utility>
#include <string.h>
#include <stdio.h>
using namespace std;
int main(){
        int M, N;       cin>>M>>N;
        int arr[1002][1002];
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0 ,1};
        pair< pair<int, int>, int > p; pair<int, int> map; queue< pair< pair<int, int>, int> > q;
        int x, y, day;
        int tom = 0;    int tottom = 0;
        for(int i=1; i<=N; i++){
                for(int j=1; j<=M; j++){
                         scanf("%d",&arr[j][i]);
                         if( arr[j][i] == 1 || arr[j][i] == 0)
                                tottom++;
                         if( arr[j][i] == 1){
                                tom++;
                                map.first = j; map.second = i; p.first=map; p.second = 0; q.push(p);
                         }
                }
        }
        while(!q.empty()){
                p = q.front(); map = p.first; day = p.second; x = map.first; y = map.second; q.pop();
                if( tom == tottom){
                        cout<<day<<endl; return 0;}
                for(int i=0; i<4; i++){
                        if( x+dx[i] < 1 || x+dx[i] > M || y+dy[i] < 1 || y+dy[i] > N)
                                continue;
                        if( arr[ x+dx[i] ][ y+dy[i] ] != 0)
                                continue;
                        arr[ x+dx[i] ][ y+dy[i] ] = 1;
                        p.second = day+1;       map.first = x+dx[i];    map.second = y+dy[i];   p.first = map;
                        q.push(p);      tom++;
                        if(tom == tottom){ cout<<day+1<<endl; return 0;}
                }
        }
        cout<<"-1"<<endl;
        return 0;
}