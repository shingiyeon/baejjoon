//# Author : nuclear852 ========================#
//# Solution : 15267603 ========================#
//# Time Stamp : 2019-09-22 22:27:58 ===========#
//# Problem Title : 게시판 구멍 막기 ==============#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
 
using namespace std;
 
int A[2501], B[2501], lv[2501];
bool pos[2501];
vector<int> adj[2501];
 
int garo = 1;
int sero = 1;
 
char map[51][51];
int gmap[51][51];
int smap[51][51];
 
void bfs(){
	queue<int> q;
 
	for(int i=1; i<=garo; i++){
		if(A[i] == -1){
			lv[i] = 0;
			q.push(i);
		}
		else
			lv[i] = -5;
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
		if(B[x] == -1 || (lv[B[x]] == lv[n] + 1 && dfs(B[x])) ){
			A[n] = x;
			B[x] = n;
			return 1;
		}
	}
	return pos[n] = 0;
}
 
 
int main() {
	int N, M; scanf("%d%d", &N, &M);
	for(int i=0; i<=2500; i++){
		A[i] = -1; B[i] = -1;
		pos[i] = 1;
	}
 
	for(int i=0; i<N; i++) scanf("%s", map[i]);
 
	bool flag = 0;
	for(int i=0; i<N; i++){
		if(flag == 1){
			garo++;
			flag = 0;
		}
		for(int j=0; j<M; j++){
			if(map[i][j] == '*'){
				gmap[i][j] = garo;
				flag = 1;
			}
			else if(map[i][j] == '.' && flag == 1){
				garo++;
				flag = 0;
			}
		}
	}
 
	flag = 0;
 
	for(int j=0; j<M; j++){
		if(flag == 1){
			sero++;
			flag = 0;
		}
		for(int i=0; i<N; i++){
			if(map[i][j] == '*'){
				smap[i][j] = sero;
				flag = 1;
			}
			else if(map[i][j] == '.' && flag == 1){
				sero++;
				flag = 0;
			}
		}
	}
 
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(map[i][j] == '*'){
				adj[gmap[i][j]].push_back(smap[i][j]);
			}
		}
	}
 
	int ans = 0;
	while(1){
		int flow = 0;
		bfs();
		for(int i=0; i<=2500; i++) pos[i] = 1;
		for(int i=1; i<=garo; i++)
			if(A[i] == -1 && dfs(i)) flow++;
		if(!flow) break;
 
		ans += flow;
	}
	printf("%d", ans);
}