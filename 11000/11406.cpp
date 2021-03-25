//# Author : nuclear852 ========================#
//# Solution : 15330053 ========================#
//# Time Stamp : 2019-09-25 20:29:14 ===========#
//# Problem Title : 책 구매하기 2 ===============#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;

int c[205][205];

int level[205];
int N, M;
bool visited[205];
bool pos[205];

void bfs(){
	queue<int> q;
	for(int i=0; i<=M+N+1; i++) level[i] = -5;
	level[0] = 0;
	q.push(0);
	while(!q.empty()){
		int idx = q.front(); q.pop();
		for(int i=0; i<=M+N+1; i++){
			if(level[i] == -5 && c[idx][i] > 0){
				level[i] = level[idx] + 1;
				q.push(i);
			}
		}
	}
}

int dfs(int p, int mn){
	if(p == M+N+1) return mn;
	if(!pos[p]) return pos[p];
	
	int flow = 0;
	for(int i=0; i<=M+N+1; i++){
		if(level[i] == level[p] + 1 && c[p][i] > 0){
			flow = dfs(i, min(mn, c[p][i]));
			if(flow) {
				c[p][i] -= flow;
				c[i][p] += flow;
				return flow;
			}
		}
	}
	return pos[p] = 0;
}

int main(){
	scanf("%d%d", &N, &M);
	for(int i=1; i<=N; i++) scanf("%d", &c[0][i]);
	for(int i=N+1; i<=N+M; i++) scanf("%d", &c[i][N+M+1]);
	for(int i=N+1; i<=N+M; i++){
		for(int j=1; j<=N; j++){
			scanf("%d", &c[j][i]);
		}
	}
	
	int ans = 0;
	while(1){
		bfs();
		for(int i=0; i<=M+N+1; i++) pos[i] = 1;
		int flow = dfs(0, 99999999);
		if(!flow) break;
		ans += flow;
	}
	printf("%d", ans);
}