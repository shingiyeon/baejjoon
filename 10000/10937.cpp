//# Author : nuclear852 ========================#
//# Solution : 21822526 ========================#
//# Time Stamp : 2020-08-17 23:08:10 ===========#
//# Problem Title : 두부 모판 자르기 ==============#
//# Language : C++11 ===========================#

#include <stdio.h>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;


int S = 0, E = 130;
int parent[131];
bool inQ[131];
int dist[131];

vector<int> adj[131];
map< pair<int, int>, int> c;
map< pair<int, int>, int> f;
map< pair<int, int>, int> d;

int MCMF() {
	int min_cost = 0;
	int flow = 0, cost = 0;
	while(1) {	
		queue<int> q;
		for(int i=S; i<=E; i++) {
			parent[i] = -1;
			inQ[i] = 0;
			dist[i] = 999999999;
		}
		q.push(S);
		inQ[S] = 1;
		dist[S] = 0;
		while(!q.empty()) {
			int cur = q.front(); q.pop();
			inQ[cur] = 0;
			for(auto next : adj[cur]) {
				if(c[{cur, next}] > f[{cur, next}] && dist[next] > dist[cur] + d[{cur, next}]) {
					parent[next] = cur;
					dist[next] = dist[cur] + d[{cur, next}];
					if(!inQ[next]) {
						q.push(next);
						inQ[next] = 1;
					}
				}
			}
		}
	
		if(parent[E] == -1) break;
		for(int i=E; i!=S; i=parent[i]) {
			cost += d[{parent[i], i}] ;
			f[{parent[i], i}]++;
			f[{i, parent[i]}]--;
		}
		if(min_cost < cost ) break;
		min_cost = min(min_cost, cost);
	}
	return min_cost;
}

int value(char x, char y) {
	if( x == 'A' && y == 'A') {
		return 100;
	}
	else if( (x == 'A' && y == 'B') || (x == 'B' && y == 'A')) {
		return 70;
	}
	else if( (x == 'A' && y == 'C') || (x == 'C' && y == 'A')) {
		return 40;
	}
	else if( x == 'B' && y == 'B') {
		return 50;
	}
	else if( (x == 'B' && y == 'C') || (x == 'C' && y == 'B')) {
		return 30;
	}
	else if( x == 'C' && y == 'C') {
		return 20;
	}
	return 0;
}

int main() {
	
	int N;
	char arr[15][15];
	
	int dx[4] = {-1, 0, 1, 0};
	int dy[4] = {0, -1, 0, 1};
	
	
	scanf("%d", &N);
	for(int i=0; i<N; i++) {
		scanf("%s", arr[i]);
	}
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			if( !((i+j)%2)) {
				for(int k=0; k<4; k++){
				 	if( i+dx[k] < 0 || i+dx[k] >= N || j+dy[k] < 0 || j+dy[k] >= N) continue;
				 	adj[i*N + j + 1].push_back(   ( (i+dx[k]) * N) + j+dy[k]+1 );
				 	adj[( (i+dx[k]) * N) + j+dy[k]+1].push_back(i*N+j+1);
				 	c[{i*N+j+1, ( (i+dx[k]) * N) + j+dy[k]+1}] = 1;
				 	d[{i*N+j+1, ( (i+dx[k]) * N) + j+dy[k]+1}] = -value(arr[i][j], arr[i+dx[k]][j+dy[k]]);
				 	d[{( (i+dx[k]) * N) + j+dy[k]+1, i*N+j+1}] = value(arr[i][j], arr[i+dx[k]][j+dy[k]]);
				}
				adj[S].push_back(i*N + j+1);
				adj[i*N + j+1].push_back(S);
				c[{S, i*N + j+1}] = 1;
			}
			else {
				adj[i*N + j+1].push_back(E);
				adj[E].push_back(i*N + j+1);
				c[{i*N + j+1, E}] = 1;
			}
		}
	}
	
	printf("%d", -MCMF());
	
}