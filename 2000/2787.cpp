//# Author : nuclear852 ========================#
//# Solution : 15388904 ========================#
//# Time Stamp : 2019-09-28 22:36:50 ===========#
//# Problem Title : 흔한 수열 문제 ===============#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <queue>

using namespace std;

int N, M;
int A[205], B[205], lv[205];
bool pos[205];

bool map[205][205];

void bfs(){
	queue<int> q;
	for(int i=1; i<=N; i++){
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
		
		for(int i=1; i<=N; i++){
			if(!map[idx][i]) continue;
			if(B[i] != -1 && lv[B[i]] == -5){
				lv[B[i]] = lv[idx] + 1;
				q.push(B[i]);
			}
		}
	}
}

bool dfs(int n){
	if(!pos[n]) return pos[n];
	for(int i=1; i<=N; i++){
		if(!map[n][i]) continue;
		if(B[i] == -1 || (lv[B[i]] == lv[n] + 1 && dfs(B[i]))){
			A[n] = i;
			B[i] = n;
			return 1;
		}
	}
	return pos[n] = 0;
}

int main(){
	scanf("%d%d", &N, &M);
	for(int i=0; i<205; i++){
		for(int j=0; j<205; j++)
			map[i][j] = 1;
	}
	
	for(int i=0; i<M; i++){
		int a, b, c, d; scanf("%d%d%d%d", &a,&b,&c,&d);
		if(a==1){
			for(int x=b; x<=c; x++){
				for(int y=d+1; y<=N; y++){
					map[x][y] = 0;
				}
			}
			for(int x=1; x<b; x++)
				map[x][d] = 0;
			for(int x=c+1; x<=N; x++)
				map[x][d] = 0;
		}
		else{
			for(int x=b; x<=c; x++){
				for(int y=1; y<=d-1; y++){
					map[x][y] = 0;
				}
			}
			for(int x=1; x<b; x++)
				map[x][d] = 0;
			for(int x=c+1; x<=N; x++)
				map[x][d] = 0;
		}
	}
	
	for(int i=1; i<=N; i++){
		A[i] = -1;
		B[i] = -1;
	}
	
	int ans = 0;
	while(1){
		bfs();
		for(int i=1; i<=N; i++) pos[i] = 1;
		int flow = 0;
		for(int i=1; i<=N; i++){
			if(A[i] == -1 && dfs(i)){
				flow++;
			}
		}
		if(!flow) break;
		ans += flow;
	}
	
	if(ans != N) printf("-1");
	else{
		for(int i=1; i<=N; i++) printf("%d ", A[i]);
	}
}