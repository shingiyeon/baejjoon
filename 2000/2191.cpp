//# Author : nuclear852 ========================#
//# Solution : 15278665 ========================#
//# Time Stamp : 2019-09-23 15:38:05 ===========#
//# Problem Title : 들쥐의 탈출 =================#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <queue>
#include <math.h>
#include <vector>
#include <utility>
 
using namespace std;
 
int N, M, S, V;
int A[101], B[101], lv[101];
bool pos[101];
 
pair<double, double> mouse[101];
 
vector<int> adj[101];
 
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
 
		for(int x : adj[idx]){
			if(B[x] != -1 && lv[B[x]] == -5){
				lv[B[x]] = lv[idx] + 1;
				q.push(B[x]);
			}
		}
	}
}
 
int dfs(int n){
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
	scanf("%d%d%d%d", &N, &M, &S, &V);
 
	for(int i=0; i<N; i++){
		scanf("%lf%lf", &mouse[i].first, &mouse[i].second);
	}
 
	for(int i=0; i<M; i++){
		double x, y;
		scanf("%lf%lf", &x, &y);
 
		for(int j=0; j<N; j++){
			double a = x - mouse[j].first;
			double b = y - mouse[j].second;
			if( (double)V * S * V * S >=  a*a + b*b )
				adj[j].push_back(i);
		}
	}
 
	for(int i=0; i<101; i++){
		A[i] = -1;
		B[i] = -1;
		pos[i] = 1;
	}
	int ans = 0;
	while(1){
		bfs();
		int flow = 0;
 
		for(int i=0; i<101; i++) pos[i] = 1;
 
		for(int i=0; i<N; i++)
			if(A[i] == -1 && dfs(i)) flow++;
		if(!flow) break;
		ans += flow;
	}
	printf("%d", N-ans);
}