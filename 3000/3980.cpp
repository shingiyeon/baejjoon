//# Author : nuclear852 ========================#
//# Solution : 21587549 ========================#
//# Time Stamp : 2020-08-08 22:21:23 ===========#
//# Problem Title : 선발 명단 ==================#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <utility>
#include <queue>

using namespace std;

int T;

int S = 0;
int E = 24;

vector<int> adj[25];
int c[25][25];
int f[25][25];
int d[25][25];

bool inQ[25];
int dist[25];
int p[25];

void clear() {
	for(int i=0; i<25; i++) {
		for(int j=0; j<25; j++){
			c[i][j] = 0;
			f[i][j] = 0;
			d[i][j] = 0;
		}
	}
}

pair<int, int> SPFA() {
	int flow = 999999999;
	int cost = 0;
	while(1){
		for(int i=0; i<25; i++) {
			dist[i] = 999999999;
			p[i] = -1;
			inQ[i] = 0;
		}
		queue<int> q;
		q.push(S);
		dist[0] = 0;
		while(!q.empty()) {
			int cur = q.front(); q.pop();
			inQ[cur] = 0;
			for(auto next: adj[cur]) {
				if(c[cur][next] > f[cur][next] && dist[next] > dist[cur] + d[cur][next]){
					dist[next] = dist[cur] + d[cur][next];
					p[next] = cur;
					if(!inQ[next]) {
						q.push(next);
						inQ[next] = 1;
					}
				}
			}
		}
		
		if (p[E] == -1) break;
		for(int i=E; i!=S; i=p[i]) {
			flow = min(flow, c[p[i]][i] - f[p[i]][i]);
		}
		
		for(int i=E; i!=S; i=p[i]) {
			cost += d[p[i]][i] * flow;
			f[p[i]][i] += flow;
			f[i][p[i]] -= flow;
		}
	}
	return {cost, flow};
}

int main() {
	scanf("%d", &T);
	while(T--) {
		clear();
		for(int i=1; i<=11; i++) {
			c[0][i] = 1;
			adj[0].push_back(i);
			adj[i].push_back(0);
			c[i+11][E] = 1;
			adj[i+11].push_back(E);
			adj[E].push_back(i+11);
			for(int j=12; j<=22; j++) {
				int tmp; scanf("%d", &tmp);
				if(!tmp) continue;
				adj[i].push_back(j);
				adj[j].push_back(i);
				c[i][j] = 1;
				d[i][j] = -tmp;
				d[j][i] = tmp;
			}
		}
		pair<int, int> p = SPFA();
		printf("%d\n", -p.first);
	}
}