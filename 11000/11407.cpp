//# Author : nuclear852 ========================#
//# Solution : 21946117 ========================#
//# Time Stamp : 2020-08-22 23:34:54 ===========#
//# Problem Title : 책 구매하기 3 ===============#
//# Language : C++11 ===========================#

#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

int S = 0, E = 204;
int dist[205];
int parent[205];
bool inQ[205];
int N, M;

vector<int> adj[205];
int c[205][205];
int f[205][205];
int d[205][205];
//map< pair<int, int>, int > c;
//map< pair<int, int>, int > f;
//map< pair<int, int>, int > d;

pair<int, int> SPFA() {
	int flow = 0;
	int cost = 0;
	
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
			int cur = q.front(); q.pop(); inQ[cur] = 0;
			for(auto next: adj[cur]) {
				//if(c[{cur,next}] > f[{cur,next}] && dist[next] > dist[cur] + d[{cur, next}]) {
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
		
		flow += cur_flow;
		
		for(int i=E; i!=S; i=parent[i]) {
			cost += d[parent[i]][i] * cur_flow;
			f[parent[i]][i] += cur_flow;
			f[i][parent[i]] -= cur_flow;
		}
		
	}
	
	return {flow, cost};
	
}

int main() {
	scanf("%d%d",&N,&M);
	int tmp;
	for(int i=1; i<=N; i++) {
		scanf("%d", &tmp);
		c[S][i] = tmp;
		adj[S].push_back(i);
		adj[i].push_back(S);
	}
	for(int i=1; i<=M; i++) {
		scanf("%d", &tmp);
		c[i+100][E] = tmp;
		adj[E].push_back(i+100);
		adj[i+100].push_back(E);
	}
	
	for(int i=1; i<=M; i++) {
		for(int j=1; j<=N; j++) {
			scanf("%d", &tmp);
			c[j][100+i] = tmp;
			if(c[j][100+i]){
				adj[j].push_back(100+i);
				adj[100+i].push_back(j);
			}
		}
	}
	for(int i=1; i<=M; i++) {
		for(int j=1; j<=N; j++) {
			scanf("%d", &tmp);
			d[j][100+i] = tmp;
			d[100+i][j] = -tmp;
		}
	}
	
	pair<int, int> p = SPFA();
	printf("%d\n%d",p.first,p.second);
}