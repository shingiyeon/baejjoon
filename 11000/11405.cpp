//# Author : nuclear852 ========================#
//# Solution : 21700050 ========================#
//# Time Stamp : 2020-08-12 23:18:29 ===========#
//# Problem Title : 책 구매하기 =================#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;

bool inQ[203];
int dist[203];
int parent[203];
int c[203][203];
int f[203][203];
int d[203][203];

vector<int> adj[203];
int S = 0;
int E = 202;


pair<int, int> MCMF() {
	int cost = 0;
	int flow = 0;

	while(1) {
		queue<int> q;
		for(int i=S; i<=E; i++) {
			dist[i] = 999999999;
			parent[i] = -1;
		}
		
		q.push(S);
		inQ[S] = 1;
		dist[S] = 0;
		
		while(!q.empty()) {
			int cur = q.front(); q.pop();
			inQ[cur] = 0;
			for(auto next : adj[cur]) {
				if(c[cur][next] > f[cur][next] && dist[next] > dist[cur] + d[cur][next]) {
					dist[next] = dist[cur] + d[cur][next];
					parent[next] = cur;
					if(!inQ[next]) {
						q.push(next);
						inQ[next] = 1;
					}
				}
			}
		}
		
		if(parent[E] == -1) break;
		
		int cur_flow = 999999999;
		for(int i=E; i!=S; i=parent[i]) {
			cur_flow = min(cur_flow, c[parent[i]][i] - f[parent[i]][i]);
		}
		
		for(int i=E; i!=S; i=parent[i]) {
			cost += d[parent[i]][i] * cur_flow;
			f[parent[i]][i] += cur_flow;
			f[i][parent[i]] -= cur_flow;
		}
	}
	return {cost, flow};
}

int main(){
	scanf("%d%d",&N,&M);
	for(int i=1; i<=N; i++) {
		scanf("%d", &c[S][i]);
		adj[S].push_back(i);
		adj[i].push_back(S);
	}
	for(int i=101; i<=100+M; i++) { 
		scanf("%d", &c[i][E]);
		adj[i].push_back(E);
		adj[E].push_back(i);
	}
	for(int j=101; j<=100+M; j++) {
		for(int i=1; i<=N; i++) {
			int tmp; scanf("%d", &tmp);
			
			d[i][j] = tmp;
			d[j][i] = -tmp;
			c[i][j] = 999999999;
			adj[i].push_back(j);
			adj[j].push_back(i);
		}
	}
	
	pair<int, int> p = MCMF();
	printf("%d", p.first);
	
	
}