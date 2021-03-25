//# Author : nuclear852 ========================#
//# Solution : 15288738 ========================#
//# Time Stamp : 2019-09-23 22:39:08 ===========#
//# Problem Title : N-Rook =================#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int M, N;
int map[101][101];
int gmap[101][101];
int smap[101][101];

int garo = 1;
int sero = 1;


int A[5001], B[5001], lv[5001];
bool pos[5001];
vector<int> adj[5001];

void bfs(){
	queue<int> q;
	for(int i=1; i<=garo; i++){
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
	
	for(auto x: adj[n]){
		if(B[x] == -1 || (lv[B[x]] == lv[n] + 1 && dfs(B[x]))){
			A[n] = x;
			B[x] = n;
			return 1;
		}
	}
	return pos[n] = 0;
}

int main(){
	scanf("%d%d", &M, &N);
	
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			scanf("%d", &map[i][j]);
		}
	}
	
	for(int i=0; i<=5000; i++){
		A[i] = -1;
		B[i] = -1;
		pos[i] = 1;
	}
	
	
	bool flag = 0;
	for(int i=0; i<M; i++){
		if(flag){
			garo++;
			flag = 0;
		}
		for(int j=0; j<N; j++){
			if(map[i][j] == 0){
				gmap[i][j] = garo;
				flag = 1;
			}
			else if(map[i][j] == 2 && flag == 1){
				garo++;
				flag = 0;
			}
		}
	}
	flag = 0;
	for(int j=0; j<N; j++){
		if(flag){
			sero++;
			flag = 0;
		}
		for(int i=0; i<M; i++){
			if(map[i][j] == 0){
				smap[i][j] = sero;
				flag = 1;
			}
			else if(map[i][j] == 2 && flag == 1){
				sero++;
				flag = 0;
			}
		}
	}	
	
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			if(map[i][j] == 0){
				adj[gmap[i][j]].push_back(smap[i][j]);
			}
		}
	}

	
	int match = 0;
	while(1){
		int flow = 0;
		bfs();
		for(int i=1; i<=5000; i++) pos[i] = 1;
		
		for(int i=1; i<=garo; i++){
			if(A[i] == -1 && dfs(i)) flow++;
		}
		if(!flow) break;
		match += flow;
		
	}
	
	printf("%d", match);
}