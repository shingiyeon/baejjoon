//# Author : nuclear852 ========================#
//# Solution : 15279406 ========================#
//# Time Stamp : 2019-09-23 16:12:41 ===========#
//# Problem Title : 토렌트 ====================#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> adj[101];
bool pos[101];
int A[101], B[101], lv[101];
int T;
int ans = -1;

int n, m;

void bfs(int size){
	queue<int> q;
	
	for(int i=0; i<size; i++){
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

bool dfs(int n, int size){
	if(!pos[n]) return pos[n];
	
	for(auto x : adj[n]){
		if(B[x] == -1 || (lv[B[x]] == lv[n] + 1 && dfs(B[x], size))){
			A[n] = x;
			B[x] = n;
			return 1;
		}
	}
	
	return pos[n] = 0;
}

void bs(int s, int e){
	
	if(s>e) return;
	
	for(int i=0; i<=100; i++){
		A[i] = -1;
		B[i] = -1;
		pos[i] = 1;
	}
	
	int mid = (s+e) / 2;
	
	int match = 0;
	while(1){
		for(int i=0; i<=100; i++) pos[i] = 1;
		int flow = 0;
		bfs(mid);
		
		for(int i=0; i<mid; i++)
			if(A[i] == -1 && dfs(i, mid)) flow++;
		if(!flow) break;
		match += flow;
	}
	
	if(match == n){
		ans = mid;
		bs(s, mid-1);
	}
	else{
		bs(mid+1, e);
	}
}

int main(){
	scanf("%d", &T);
	
	while(T--){
		for(int i=0; i<=100; i++) 
			adj[i].clear();
		scanf("%d%d", &n, &m);
		
		for(int i=0; i<m; i++){
			int s, e; scanf("%d%d",&s,&e);
			int a; scanf("%d", &a);
			for(int j=0; j<a; j++){
				int tmp; scanf("%d", &tmp);
				
				for(int t=s; t<e; t++){
					adj[t].push_back(tmp);
				}
			}
		}
		
		bs(0, 100);
		printf("%d\n", ans);
		ans = -1;
		
			
	}
}