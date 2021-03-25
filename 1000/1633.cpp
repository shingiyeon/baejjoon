//# Author : nuclear852 ========================#
//# Solution : 21796744 ========================#
//# Time Stamp : 2020-08-16 22:30:37 ===========#
//# Problem Title : 최고의 팀 만들기 ==============#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int parent[3021];
bool inQ[3021];
int dist[3021];


map< pair<int, int>, int > c;
map< pair<int, int>, int > f;
map< pair<int, int>, int > d;

vector<int> adj[3021];

const int S = 0, E = 3020;
const int W = 3018, B = 3019;

pair<int, int> MCMF() {
	int flow = 0, cost = 0;

	
	while(1) {
		for(int i=S; i<=E; i++) {
			parent[i] = -1;
			inQ[i] = 0;
			dist[i] = 999999999;
		}
		
		queue<int> q;
		q.push(S);
		inQ[S] = 1;
		dist[S] = 0;
		while(!q.empty()) {
			int cur = q.front(); q.pop();
			inQ[cur] = 0;
			
			for(auto next : adj[cur]) {
				if(c[{cur, next}] > f[{cur, next}] && dist[next] > dist[cur] + d[{cur, next}]) {
					dist[next] = dist[cur] + d[{cur, next}];
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
			cur_flow = min(cur_flow, c[{parent[i], i}] - f[{parent[i], i}]);
		}
		
		flow += cur_flow;
		for(int i=E; i!=S; i=parent[i]) {
			cost += d[{parent[i], i}] * cur_flow;
			f[{parent[i], i}] += cur_flow;
			f[{i, parent[i]}] -= cur_flow;
		}
		
	}
	
	return {flow, cost};
}


int main() {
	int w, b;
	int idx = 1;
	
	c[{W, E}] = 15;
	adj[W].push_back(E);
	adj[E].push_back(W);
	c[{B, E}] = 15;
	adj[B].push_back(E);
	adj[E].push_back(B);
	
	while(scanf("%d%d", &w, &b) != EOF) {
		c[{S, idx}] = 1;
		adj[S].push_back(idx);
		adj[idx].push_back(S);
		
		c[{idx, idx+1000}] = 1;
		d[{idx, idx+1000}] = -w;
		d[{idx+1000, idx}] = w;
		adj[idx].push_back(idx+1000);
		adj[idx+1000].push_back(idx);
		
		c[{idx, idx+2000}] = 1;
		d[{idx, idx+2000}] = -b;
		d[{idx+2000, idx}] = b;
		adj[idx].push_back(idx+2000);
		adj[idx+2000].push_back(idx);
		
		c[{idx+1000, W}] = 1;
		adj[idx+1000].push_back(W);
		adj[W].push_back(idx+1000);
		
		c[{idx+2000, B}] = 1;
		adj[idx+2000].push_back(B);
		adj[B].push_back(idx+2000);
	
		idx++;
	}
	
	pair<int, int> p = MCMF();
	printf("%d", -p.second);
}