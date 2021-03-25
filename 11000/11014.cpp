//# Author : nuclear852 ========================#
//# Solution : 15235854 ========================#
//# Time Stamp : 2019-09-20 23:57:14 ===========#
//# Problem Title : 컨닝 2 ===================#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int C, N, M;
char map[81][81];

int A[6401], B[6401];
int lv[6401];

bool pos[6401];
vector<int> adj[6401];

int dx[6] = {-1, 0, 1, -1, 0, 1};
int dy[6] = {-1, -1, -1, 1, 1, 1};

void bfs(){
	queue<int> q;
	for(int i=0; i<6400; i++) {
		if(A[i]==-1) {
			lv[i] = 0;
			q.push(i);
		}
		else{
			lv[i] = -5;
		}	
	}
	
	while(!q.empty()){
		int idx = q.front(); q.pop();
		for(auto f : adj[idx]){
			if(B[f] != -1 && lv[B[f]] == -5){
				lv[B[f]] = lv[idx] + 1;
				q.push(B[f]);
			}
		}
	}
	
}

bool dfs(int n){
	if(!pos[n]) return 0;
	for(auto b: adj[n]){
		if(B[b] == -1) {
			A[n] = b;
			B[b] = n;
			return 1;
		}
		if(lv[B[b]] == lv[n] + 1){
			if(dfs(B[b])){
				A[n] = b;
				B[b] = n;
				return 1;
			}
		}
	}
	return pos[n] = 0;
}

int main(){
	scanf("%d", &C);
	while(C--){
		scanf("%d%d", &N, &M);
		for(int i=0; i<N; i++) scanf("%s", map[i]);
		int people = 0;
		
		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++){
				if(map[i][j] == '.') people++;
			}
		}
		
		for(int i=0; i<=6400; i++){
			A[i] = -1;
			B[i] = -1;
			adj[i].clear();
		}
		
		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j+=2){
				for(int k=0; k<6; k++) {
					if( i+dx[k] < 0 || i+dx[k] >= N) continue;
					if( j+dy[k] < 0 || j+dy[k] >= M) continue;
					if( map[i][j] != '.') continue;
					if( map[i+dx[k]][j+dy[k]] == '.')
						adj[i*M + j].push_back( (i+dx[k]) * M + j+dy[k]);
					
				}
			}
		}
		
		int match = 0;
		while(1){
			int flow = 0;
			bfs();
			for(int i=0; i<=6400; i++) pos[i] = 1;
			for(int i=0; i<=6400; i++) if(A[i]==-1 && dfs(i)) flow++;
			
			if(!flow) break;
			match += flow;
		}
		
		printf("%d\n", people - match);
	}
}