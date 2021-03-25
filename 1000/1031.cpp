//# Author : nuclear852 ========================#
//# Solution : 15386834 ========================#
//# Time Stamp : 2019-09-28 20:40:37 ===========#
//# Problem Title : 스타 대결 ==================#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int c[102][102];
int f[102][102];
int N, M;

bool pos[102];
int lv[102];

vector<pair<int, int> > v;

void bfs(){
	queue<int> q;
	for(int i=0; i<102; i++) lv[i] = -5;
	lv[0] = 0;
	q.push(0);
	while(!q.empty()){
		int idx = q.front(); q.pop();
		for(int i=M+N+1; i>=0; i--){
			if(c[idx][i] > f[idx][i] && lv[i] == -5){
				lv[i] = lv[idx] + 1;
				q.push(i);
			}
		}
	}
}

int dfs(int n, int mn){
	if(n==M+N+1) return mn;
	if(!pos[n]) return pos[n];
	
	int flow;
	for(int i=M+N+1; i>=0; i--){
		if(c[n][i] > f[n][i] && lv[i] == lv[n] + 1){
			flow = dfs(i, min(mn, c[n][i] - f[n][i]));
			if(flow){
				f[n][i] += flow;
				f[i][n] -= flow;
				return flow;
			}
		}
	}
	
	return pos[n] = 0;
}

void flipping(int i, int j){
	f[0][i]--; f[i][0]++;
	f[i][j]--; f[j][i]++;
	f[j][M+N+1]--; f[M+N+1][j]++;
	
	queue<int> q;
	q.push(i);
	vector<int> prev(N+M+2, -1);
	while(!q.empty()){
		int idx = q.front(); q.pop();
		for(int nxt=0; nxt<=N+M+1; nxt++){
			if(idx == i && nxt <= j) continue;
			if(nxt <= i) continue;
			if(c[idx][nxt] > f[idx][nxt] && prev[nxt] == -1){
				q.push(nxt);
				prev[nxt] = idx;
				if(nxt == N+M+1) break;
			}
		}
	}
	
	if(prev[N+M+1] == -1){
		f[0][i]++; f[i][0]--;
		f[i][j]++; f[j][i]--;
		f[j][M+N+1]++; f[M+N+1][j]--;
		
		return;
	}
	
	for(int idx=N+M+1; idx != 0; idx = prev[idx]){
		f[prev[idx]][idx] += 1;
		f[idx][prev[idx]] -= 1;
	}
}


int main(){
	scanf("%d%d", &N, &M);
	int cmp1 = 0;
	int cmp2 = 0;
	for(int i=1; i<=N; i++) {scanf("%d", &c[0][i]); cmp1 += c[0][i];}
	for(int i=N+1; i<=N+M; i++) {scanf("%d", &c[i][N+M+1]); cmp2+=c[i][N+M+1];}
	for(int i=1; i<=N; i++){
		for(int j=N+1; j<=N+M; j++)
			c[i][j] = 1;
	}
	
	if(cmp1 != cmp2){
		printf("-1");
		return 0;
	}
	
	int ans = 0;
	while(1) {
		bfs();
		for(int i=0; i<=M+N+1; i++) pos[i] = 1;
		int flow = dfs(0, 999999999);
		if(!flow) break;
		ans += flow;
	}
	
	if(cmp1 != ans){
		printf("-1");
		return 0;
	}
	
	
	for(int i=1; i<=N; i++){
		for(int j=N+1; j<=N+M; j++){
			if(f[i][j]){
				flipping(i, j);
			}
		}
	}
	
	for(int i=1; i<=N; i++){
		for(int j=N+1; j<=N+M; j++){
			printf("%d", f[i][j]);
		}
		printf("\n");
	}
	
}