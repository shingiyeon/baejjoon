//# Author : nuclear852 ========================#
//# Solution : 24276138 ========================#
//# Time Stamp : 2020-12-08 23:29:30 ===========#
//# Problem Title : 도미노 ====================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

vector< vector<int> > adj;
int cnt = 0;
int s_cnt = 0;
int num[100001];
int groupNum[100001];
int indeg[100001];
int scc[100001];
bool inQ[100001];
stack<int> S;
int T, N, M;

void dfs(int cur) {
	S.push(cur);
	inQ[cur] = true;
	num[cur] = ++cnt;
	groupNum[cur] = cnt;
	
	for(auto next: adj[cur]) {
		if(!num[next]) {
			dfs(next);
			groupNum[cur] = min(groupNum[cur], groupNum[next]);
		}
		else if(inQ[next]) {
			groupNum[cur] = min(groupNum[cur], num[next]);
		}
	}
	
	if(groupNum[cur] == num[cur]) {
		++s_cnt;
		 while(!S.empty()) {
		 	int s_cur = S.top(); S.pop();
		 	inQ[s_cur] = false;
		 	scc[s_cur] = s_cnt; 
		 	if(s_cur == cur) break;
		 }
	}
}

int main() {
	scanf("%d", &T);
	while(T--) {
		adj.clear(); 
		int ans = 0;
		for(int i=0; i<=100000; i++) {
			num[i] = groupNum[i] = indeg[i] = inQ[i] = scc[i] = 0;
		}
		cnt = s_cnt = 0;
		
		scanf("%d%d", &N, &M);
		adj.resize(N+1);
		for(int i=1; i<=M; i++) {
			int a, b; scanf("%d%d", &a, &b);
			adj[a].push_back(b);
		}
		
		for(int i=1; i<=N; i++) {
			if(!num[i]) dfs(i);
		}
		
		for(int i=1; i<=N; i++) {
			for(auto next: adj[i]) {
				if(scc[i] != scc[next]) {
					indeg[scc[next]]++;
				}
			}
		}
		for(int i=1; i<=s_cnt; i++) {
			if(!indeg[i]) {
				ans++;
			}
		}
		printf("%d\n", ans);
	}
}