//# Author : nuclear852 ========================#
//# Solution : 15443150 ========================#
//# Time Stamp : 2019-10-01 19:15:24 ===========#
//# Problem Title : 비숍2 ====================#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int N;
bool map[103][103];
int gmap[103][103];
int smap[103][103];

int garo = 1;
int sero = 1;

int A[10004], B[10004], lv[10004];
bool pos[10004];

vector<int> adj[10004];

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
	
	for(auto x : adj[n]){
		if(B[x] == -1 || (lv[B[x]] == lv[n] + 1 && dfs(B[x]))) {
			A[n] = x;
			B[x] = n;
			return 1;
		}
	}
	
	return pos[n] = 0;
}

int main(){
	scanf("%d", &N);
	int temp; scanf("%d", &temp);
	int x,y;
	while(temp--){
		scanf("%d%d", &x, &y);
		map[x][y] = 1;
	}
	
	x = N, y = 1;
	
	for(int i=1; i<10004; i++){
		A[i] = -1;
		B[i] = -1;
	}
	
	while(1)
	{
		if(!map[x][y]){
			gmap[x][y] = garo;
			x--; y--;
		}
		else {
			garo++;
			x--; y--;
		}
		if(x == 0 && y == N-1) break;
		if(x == 0 && y == 0){
			x = N-1; y = N;
			garo++;
		}
		if(y == 0) {
			y = N - x + 1;
			x = N;
			garo++;
		}
		if(x == 0) {
			x = N - y - 1;
			y = N;
			garo++;
		}
	}
	
	x = N; y = N;
	while(1)
	{
		if(!map[x][y]){
			smap[x][y] = sero;
			x--; y++;
		}
		else {
			sero++;
			x--; y++;
		}
		if(x == 0 && y == 2) break;
		if(x == 0 && y == N+1){
			x = N-1; y = 1; sero++;
		}
		if(y == N+1){
			y = x; x = N;
			sero++;
		}
		if(x == 0) {
			x = y - 2; y = 1;
			sero++;
		}
	}
	
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			if(!map[i][j]) {
				adj[ gmap[i][j] ].push_back(smap[i][j]);
			}
		}
	}
	
	int ans = 0;
	while(1) {
		bfs();
		for(int i=0; i<=garo; i++) pos[i] = 1;
		int flow = 0;
		for(int i=0; i<=garo; i++){
			if(A[i] == -1 && dfs(i)) flow++;
		}
		if(!flow) break;
		ans += flow;
	}
	
	printf("%d", ans);
	
}