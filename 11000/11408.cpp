//# Author : nuclear852 ========================#
//# Solution : 21589565 ========================#
//# Time Stamp : 2020-08-08 23:50:27 ===========#
//# Problem Title : 열혈강호 5 =================#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <utility>
#include <queue>
#include <vector>
#include <map>

using namespace std;

int N, M;

int S = 0, E = 810;
int p[811];
bool inQ[811];
int dist[811];

vector<int> adj[811];
int c[811][811];
int f[811][811];
int d[811][811];
//map<pair<int, int>, int> c;
//map<pair<int, int>, int> f;
//map<pair<int, int>, int> d;

pair<int, int> SPFA() {
	int cost = 0;
	int flow = 0;
	
	while(1) {
		for(int i=0; i<=810; i++) {
			p[i] = -1;
			inQ[i] = 0;
			dist[i] = 999999999;
		}
		
		queue<int> q;
		q.push(S);
		dist[S] = 0;
		while(!q.empty()) {
			int cur = q.front(); q.pop();
			inQ[cur] = 0;
			for(auto next: adj[cur]) {
				//if(c[{cur, next}] > f[{cur, next}] && dist[next] > dist[cur] + d[{cur, next}]) {
				if(c[cur][next] > f[cur][next] && dist[next] > dist[cur] + d[cur][next]) {
					dist[next] = dist[cur] + d[cur][next];
					p[next] = cur;
					if(!inQ[next]) {
						q.push(next);
						inQ[next] = 1;
					}
				}
			}	
		}
		
		if( p[E] == -1) break;
		
		flow += 1;
		
		for(int i=E; i!=S; i=p[i]) {
			cost += d[p[i]][i];
			f[p[i]][i] += 1;
			f[i][p[i]] -= 1;
		}
	}
	return {cost, flow};
}

int main() {
	scanf("%d%d", &N, &M);
	int num, idx, cst;
	for(int i=1; i<=N; i++) {
		adj[S].push_back(i);
		adj[i].push_back(S);
		c[S][i] = 1;
		scanf("%d", &num);
		for(int j=0; j<num; j++) {
			scanf("%d%d", &idx, &cst);
			adj[i].push_back(400+idx);
			adj[400+idx].push_back(i);
			c[i][400+idx] = 1;
			d[i][400+idx] = cst;
			d[400+idx][i] = -cst;
		}	
	}
	for(int i=1; i<=M; i++) {
		adj[400+i].push_back(E);
		adj[E].push_back(400+i);
		c[400+i][E] = 1;
	}
	pair<int, int> p = SPFA();
	printf("%d\n%d", p.second, p.first);
}