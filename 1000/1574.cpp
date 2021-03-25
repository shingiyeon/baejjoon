//# Author : nuclear852 ========================#
//# Solution : 15333175 ========================#
//# Time Stamp : 2019-09-25 22:42:09 ===========#
//# Problem Title : 룩 어택 ===================#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

bool map[301][301];

int A[301], B[301], lv[301];
bool pos[301];
vector<int> adj[301];
int R, C, N;

void bfs(){
	queue<int> q;
	for(int i=0; i<R; i++){
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
	scanf("%d%d%d", &R, &C, &N);
	for(int i=0; i<N; i++){
		int x, y; scanf("%d%d", &x, &y);
		map[x-1][y-1] = 1;
	}
	
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			if(!map[i][j]){
				adj[i].push_back(j);
			}
		}
	}
	for(int i=0; i<R; i++){
		A[i] = -1;
	}
	for(int i=0; i<C; i++){
		B[i] = -1;
	}
	
	int match = 0;
	while(1){
		bfs();
		for(int i=0; i<R; i++) pos[i] = 1;
		int flow = 0;
		for(int i=0; i<R; i++){
			if(A[i] == -1 && dfs(i)) flow++;
		}
		if(!flow) break;
		match += flow;
	}
	printf("%d", match);
}