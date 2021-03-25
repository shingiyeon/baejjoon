//# Author : nuclear852 ========================#
//# Solution : 15261647 ========================#
//# Time Stamp : 2019-09-22 16:50:40 ===========#
//# Problem Title : 책 나눠주기 =================#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int T, N, M;
int a[1001], b[1001], lv[1001];
bool pos[1001];

vector<int> adj[1001]; // people to books

void bfs() {
	queue<int> q;
	for(int i=1; i<=M; i++){
		if(a[i] == -1){
			lv[i] = 0;
			q.push(i);
		}
		else
			lv[i] = -5;
	}
	while(!q.empty()){
		int idx = q.front(); q.pop();
		for(auto x : adj[idx]){
			if(b[x] != -1 && lv[b[x]] == -5){
				lv[b[x]] = lv[idx] + 1;
				q.push(b[x]);
			}
		}
	}
}

bool dfs(int n){
	if(!pos[n]) return pos[n];
	
	for(auto x: adj[n]){
		if(b[x] == -1 || (lv[b[x]] == lv[n]+1 && dfs(b[x]))){
			a[n] = x;
			b[x] = n;
			return 1;
		}
	}
	return pos[n] = 0;
}

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &N, &M);
		
		for(int i=1; i<=1000; i++){
			a[i] = -1;
			b[i] = -1;
			adj[i].clear();
		}
		
		for(int i=1; i<=M; i++){
			int a, b; scanf("%d%d", &a, &b);
			for(int j=a; j<=b; j++)
				adj[i].push_back(j);
		}
		
		
		int ans = 0;
		while(1){
			int flow = 0;
			bfs();
			for(int i=1; i<=M; i++) pos[i] = 1;
			for(int i=1; i<=M; i++)
				if(a[i] == -1 && dfs(i)) flow++;
			if(!flow) break;
			ans += flow;
		}
		printf("%d\n", ans);
	}
}