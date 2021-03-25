//# Author : nuclear852 ========================#
//# Solution : 15389631 ========================#
//# Time Stamp : 2019-09-28 23:09:48 ===========#
//# Problem Title : 고양이와 개 =================#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int T, c, d, v;
int A[501], B[501], lv[501];
bool pos[501];
int N;

vector< pair<char ,pair<int, int> > > vec;
vector<int> adj[501];

void bfs(){
	queue<int> q;
	for(int i=0; i<N; i++){
		if(A[i] == -1){
			lv[i] = 0;
			q.push(i);
		}
		else{
			lv[i] = -5;
		}
	}
	while(!q.empty()){
		int idx = q.front(); q.pop();
		for(auto x : adj[idx]){
			if(B[x] != -1 && lv[B[x]] == -5){
				lv[B[x]] = lv[idx] + 1;
				q.push(B[x]);
			}
		}
	}
}

bool dfs(int n){
	if(!pos[n]) return pos[n];
	
	for(auto x : adj[n]){
		if(B[x] == -1 || (lv[B[x]] == lv[n] + 1 && dfs(B[x]))){
			A[n] = x;
			B[x] = n;
			return 1;
		}
	}	
	
	return pos[n] = 0;
}


int main(){
	scanf("%d", &T);
	while(T--){
		vec.clear();
		for(int i=0; i<=500; i++) adj[i].clear();
		scanf("%d%d%d", &c, &d, &v);
		for(int i=0; i<=v; i++) A[i] = B[i] = -1;
		char x, y; int a, b;
		for(int i=0; i<v; i++){
			scanf(" %c%d %c%d", &x,&a,&y,&b);
			vec.push_back(make_pair(x, make_pair(a, b)));
		}
		N = 0;
		
		for(auto p : vec){
			if(p.first == 'D') continue;
			int idx = 0;
			for(auto q : vec){
				if(p.first == q.first) continue;
				
				if(p.second.first == q.second.second || p.second.second == q.second.first){
					adj[N].push_back(idx);
				}
				idx++;
			}
			N++;
		}
		
		int ans = 0;
		while(1){
			bfs();
			for(int i=0; i<N; i++) pos[i] = 1;
			int flow = 0;
			for(int i=0; i<N; i++){
				if(A[i] == -1 && dfs(i)) flow++;
			}
			if(!flow) break;
			ans += flow;
		}
		printf("%d\n", v - ans);
	}
}