//# Author : nuclear852 ========================#
//# Solution : 24274527 ========================#
//# Time Stamp : 2020-12-08 22:28:55 ===========#
//# Problem Title : Strongly Connected Component #
//# Language : C++17 ===========================#

#include <stdio.h>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int V, E;
vector< vector<int> > adj;
vector< vector<int> > SCC;
int nodeNum[10001];
int groupNum[10001];
bool visited[10001];
stack<int> S;
int cnt = 0;
void dfs(int cur) {
	visited[cur] = true;
	nodeNum[cur] = ++cnt;
	S.push(cur);
	groupNum[cur] = cnt;
	
	for(auto next: adj[cur]) {
		if(!nodeNum[next]) {
			dfs(next);
			groupNum[cur] = min(groupNum[cur], groupNum[next]);
		}
		else if(visited[next]) {
			groupNum[cur] = min(groupNum[cur], nodeNum[next]);
		}
	}
	
	if(groupNum[cur] == nodeNum[cur]) {
		vector<int> sSCC;
		while(!S.empty()) {
			int t_cur = S.top(); S.pop();
			sSCC.push_back(t_cur);
			visited[t_cur] = 0;
			if(t_cur == cur) break;
		}
		sort(sSCC.begin(), sSCC.end());
		SCC.push_back(sSCC);
	}
}

int main() {
	scanf("%d%d", &V,&E);
	adj.resize(V+1);
	
	for(int i=1; i<=E; i++) {
		int a, b; scanf("%d%d", &a, &b);
		adj[a].push_back(b); 
	}
	
	for(int i=1; i<=V; i++) {
		if(!nodeNum[i]) {
			dfs(i);
		}
	}
	sort(SCC.begin(), SCC.end());
	printf("%d\n", SCC.size());
	for(auto sSCC : SCC) {
		for(auto val : sSCC) {
			printf("%d ", val);
		}
		printf("-1\n");
	}
	
}