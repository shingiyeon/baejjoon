//# Author : nuclear852 ========================#
//# Solution : 15401729 ========================#
//# Time Stamp : 2019-09-29 19:12:07 ===========#
//# Problem Title : 도시 왕복하기 2 ==============#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

int N, P;
int c[851][851];
int f[851][851];

int lv[851];
bool pos[851];

int S = 0, E = 850;

void bfs(){
	queue<int> q;
	for(int i=0; i<=850; i++) lv[i] = -5;
	lv[S] = 0;
	q.push(S);
	while(!q.empty()){
		int idx = q.front(); q.pop();
		for(int i=0; i<=850; i++){
			if(lv[i] == -5 && c[idx][i] > f[idx][i]){
				lv[i] = lv[idx] + 1;
				q.push(i);
			}
		}
	}
}

int dfs(int p, int mn){
	if(p == E) return mn;
	if(!pos[p]) return pos[p];
	
	int flow = 0;
	for(int i=0; i<=850; i++){
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

int main(){
	scanf("%d%d", &N, &P);
	for(int i=1; i<=N; i++){
		c[(2*i)-1][2*i] = 1;
	}
	int a, b;
	while(P--) {
		scanf("%d%d", &a, &b);
		c[2*a][(2*b)-1] = 1;
		c[2*b][(2*a)-1] = 1; 
	}
	c[S][2] = N;
	c[3][E] = N;
	
	int ans = 0;
	while(1){
		bfs();
		for(int i=0; i<=850; i++) pos[i] = 1;
		int flow = dfs(S, 999999999);
		if(!flow) break;
		ans += flow;
	}
	printf("%d", ans);
}