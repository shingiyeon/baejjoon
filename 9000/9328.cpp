//# Author : nuclear852 ========================#
//# Solution : 5064819 =========================#
//# Time Stamp : 2017-01-20 11:13:01 ===========#
//# Problem Title : 열쇠 =====================#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
#include <queue>
#include <utility>
#include <string.h>
#include <vector>
using namespace std;
using std::string;
int main(){
        int T; cin>>T;
        while(T--){
                int h, w; cin>>h>>w;
                bool visited[103][103]; memset(visited,0,sizeof(visited));
                char map[103][103];
                bool key[28];   memset(key, 0 , sizeof(key));
                int keynum = 0; int ans = 0; int tempans = 0;
                int x, y;
                int dx[4] = {-1, 0, 1, 0};
                int dy[4] = { 0, 1, 0, -1};
                char skey[30];
                vector< pair<int, int> > sp;
                vector< pair<int, int> > hubo;
                queue< pair<int, int> > q;
                for(int i=0; i<h; i++){
                        scanf("%s",map[i]);
                        for(int j=0; j<w; j++){
                                if(i==0 || i==h-1 || j==0 || j==w-1){
                                        if(map[i][j] == '$')
                                                sp.push_back(make_pair(i,j));
                                        if(map[i][j] == '.')
                                                sp.push_back(make_pair(i,j));
                                        if(map[i][j] >= 'a' && map[i][j] <= 'z')
                                                sp.push_back(make_pair(i,j));
                                        if(map[i][j] >= 'A' && map[i][j] <= 'Z')
                                                hubo.push_back(make_pair(i,j));
                                }
                        }
                }
                scanf("%s",skey);
                for(int i=0; i<strlen(skey); i++){
                        if(skey[i] == '0')      break;
                        if(key[skey[i]-'a'] == 0){
                                key[skey[i]-'a'] = 1;
                                keynum++;
                        }
                }
                for(int i=0; i<hubo.size(); i++){
                        if( key[ map[hubo[i].first][hubo[i].second]-'A'] == 1){
                                map[hubo[i].first][hubo[i].second] = '.';
                                sp.push_back(make_pair(hubo[i].first,hubo[i].second));
                        }
                }
                for(int i=0; i<sp.size(); i++){
                        q.push(sp[i]);
                        visited[sp[i].first][sp[i].second]= 1;}

                while(!q.empty()){
                        x = q.front().first; y = q.front().second; q.pop();
                        if( 'a'<=map[x][y] && map[x][y] <='z'){
                                key[map[x][y]-'a'] = 1;
                                map[x][y] = '.';
                                while(!q.empty()) q.pop();
                                memset(visited,0,sizeof(visited));
                                for(int j=0; j<hubo.size(); j++){
                                        if( key[map[hubo[j].first][hubo[j].second] - 'A'] == 1){
                                                map[hubo[j].first][hubo[j].second] = '.';
                                                sp.push_back(make_pair(hubo[j].first,hubo[j].second));
                                        }
                                }
                                for(int j=0; j<sp.size(); j++){
                                        q.push(sp[j]);
                                        visited[sp[j].first][sp[j].second] = 1;
                                        tempans = 0;}
                                tempans = 0;
                        }
                        else{
                                if(map[x][y] == '$')    tempans++;
                                if(tempans > ans)       ans = tempans;
                                for(int i=0; i<4; i++){
                                        if( x+dx[i] < 0 || x+dx[i] >= h || y+dy[i] < 0 || y+dy[i] >= w ) continue;
                                        char mapinfo = map[x+dx[i]][y+dy[i]];
                                        if( visited[x+dx[i]][y+dy[i]] == 1)     continue;
                                        if( mapinfo == '*')     continue;
                                        if( mapinfo != '.'){
                                                if( 'A'<=mapinfo && mapinfo<='Z'){
                                                         if( key[mapinfo-'A'] == 1){
                                                                map[x+dx[i]][y+dy[i]] = '.';
                                                                visited[x+dx[i]][y+dy[i]] = 1;
                                                                q.push(make_pair(x+dx[i],y+dy[i]));
                                                         }
                                                         else   continue;
                                                }
                                        }
                                        visited[x+dx[i]][y+dy[i]] = 1;
                                        q.push(make_pair(x+dx[i],y+dy[i]));
                                }
                        }
                }
                cout<<ans<<'\n';
        }
}