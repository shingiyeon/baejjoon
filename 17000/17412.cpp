//# Author : nuclear852 ========================#
//# Solution : 16238628 ========================#
//# Time Stamp : 2019-11-24 19:18:26 ===========#
//# Problem Title : 도시 왕복하기 1 ==============#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <queue>
#include <stack>

using namespace std;

int c[820][820];
int f[820][820];
int S = 0, E = 810;
int N, P;

bool pos[820];
int lv[820];

void bfs() {
	queue<int> q;
	for(int i=0; i<820; i++) lv[i] = -5;
	lv[S] = 0;
	q.push(S);
	while(!q.empty()){
		int idx = q.front(); q.pop();
		for(int i=0; i<820; i++) {
			if(lv[i] == -5 && c[idx][i] - f[idx][i] > 0) {
				lv[i] = lv[idx] + 1;
				q.push(i);
			}
		}
	}
}

int dfs(int p, int mn) {
	if(p == E) return mn;
	if(!pos[p]) return pos[p];
	
	int flow = 0;
	for(int i=0; i<820; i++) {
		if(lv[i] == lv[p] + 1 && c[p][i] > f[p][i]){
			flow = dfs(i, min(mn, c[p][i] - f[p][i]));
			if(flow){
				f[p][i] += flow;
				f[i][p] -= flow;
				return flow;
			}
		}
	}
	return pos[p] = 0;
}
int main() {
	scanf("%d%d", &N, &P);
	int x, y;
	for(int i=1; i<=N; i++) {
		c[2*i][2*i+1] = 800;
	}
	for(int i=0; i<P; i++) {
		scanf("%d%d", &x, &y);
		c[x*2+1][y*2] = 1;
	}
	c[S][2] = 800;
	c[5][E] = 800;
	
	int ans = 0;
	while(1) {
		bfs();
		for(int i=0; i<820; i++) pos[i] = 1;
		int flow = dfs(S, 999999999);
		if(!flow) break;
		ans += flow;
	}
 	printf("%d", ans);
}