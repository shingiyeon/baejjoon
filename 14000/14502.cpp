//# Author : nuclear852 ========================#
//# Solution : 11704317 ========================#
//# Time Stamp : 2019-02-09 11:37:46 ===========#
//# Problem Title : 연구소 ====================#
//# Language : C++98 ===========================#

#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>
using namespace std;
typedef pair<int, int> p;

int c_map[8][8];
int map[8][8];
bool visited[8][8];
vector< pair<int, int> > v;
int N, M;

void clean_map(){
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			c_map[i][j] = map[i][j];
			visited[i][j] = 0;
		}
	}
}

void bfs(){
	int dx[4] = {-1, 1, 0, 0};
	int dy[4] = {0, 0, -1, 1};
	queue<p> q;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(c_map[i][j]==2){
				q.push( p(i,j) );
				visited[i][j] = 1;
			}
		}
	}
	
	while(!q.empty()){
		p point = q.front(); q.pop();
		int x = point.first, y = point.second;
		for(int i=0; i<4; i++){
			if(x+dx[i]<0 || x+dx[i] >= N || y+dy[i] < 0 || y+dy[i] >= M) continue;
			if(visited[x+dx[i]][y+dy[i]]) continue;
			if(c_map[x+dx[i]][y+dy[i]]) continue;
			visited[x+dx[i]][y+dy[i]] = 1;
			q.push(p(x+dx[i], y+dy[i]));
		}
	}
}

int checked(){
	int ans = 0;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(visited[i][j] == 0 && c_map[i][j] == 0) ans++;
		}
	}	
	return ans;
}

int main(){
	scanf("%d%d",&N,&M);
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			scanf("%d", &map[i][j]);
			if(!map[i][j]) v.push_back(p(i,j));
		}
	}
	
	int MAX = 0;
	
	for(int x=0; x<v.size(); x++){
		for(int y=x+1; y<v.size(); y++){
			for(int z=y+1; z<v.size(); z++){
				clean_map();
				c_map[v[x].first][v[x].second] = 1;
				c_map[v[y].first][v[y].second] = 1;
				c_map[v[z].first][v[z].second] = 1;
				bfs();
				int temp = checked();
				MAX = MAX > temp? MAX : temp;
			}
		}
	}
	printf("%d", MAX);

	
}