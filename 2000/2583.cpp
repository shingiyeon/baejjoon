//# Author : nuclear852 ========================#
//# Solution : 22026354 ========================#
//# Time Stamp : 2020-08-25 23:28:05 ===========#
//# Problem Title : 영역 구하기 =================#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

vector<int> v;
bool visited[100][100];
int map[100][100];

int M, N, K;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(int x, int y){
	int area = 0;
	queue< pair<int,int> > q;
	q.push({x,y});
	visited[x][y] = 1;
	while(!q.empty()) {
		pair<int, int> p = q.front(); q.pop();
		area++;
		int x = p.first; int y = p.second;
		for(int k=0; k<4; k++) {
			if(x+dx[k]<0 || x+dx[k]>=N || y+dy[k]<0 || y+dy[k]>=M) continue;
			if(visited[x+dx[k]][y+dy[k]] || map[x+dx[k]][y+dy[k]]) continue;
			q.push({x+dx[k], y+dy[k]});
			visited[x+dx[k]][y+dy[k]] = 1;
		}
	}
	return area;
}

int main(){
	scanf("%d%d%d", &M, &N, &K);
	int x1, y1, x2, y2;
	while(K--) {
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		for(int x=x1; x<x2; x++){
			for(int y=y1; y<y2; y++){
				map[x][y] = 1;
			}
		}
	}
	
	int answer = 0;
	for(int x=0; x<N; x++) {
		for(int y=0; y<M; y++){
			if(!map[x][y] && !visited[x][y]) {
				v.push_back(bfs(x,y));
				answer++;
			}
		}
	}
	sort(v.begin(), v.end());
	printf("%d\n", answer);
	for(auto val: v) {
		printf("%d ", val);
	}
	
}