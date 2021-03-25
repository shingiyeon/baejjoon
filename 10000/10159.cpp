//# Author : nuclear852 ========================#
//# Solution : 12616219 ========================#
//# Time Stamp : 2019-04-06 13:19:36 ===========#
//# Problem Title : 저울 =====================#
//# Language : C++98 ===========================#

#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
bool visited[101];
bool mapping[101];
int N, M; 

void i_visited(){
	for(int i=0; i<101; i++) visited[i] = 0;
}

int dfs(int i, vector<int> a[]){
	int num = 0;
	queue<int> q;
	q.push(i);
	i_visited();
	visited[i] = 1;
	while(!q.empty()){
		int idx  = q.front();
		q.pop();
		for(int j=0; j<a[idx].size(); j++){
			if(!visited[a[idx][j]]){
				visited[a[idx][j]] = 1;
				q.push(a[idx][j]);
			}
		}
	}
	for(int j=1; j<=N; j++){
		if(visited[j]==1)
			num++;
	}
	return num;
}

int main(){
	int a, b;
	scanf("%d%d", &N,&M);
	vector<int> v[101];
	vector<int> rv[101];
	for(int i=0; i<M; i++){
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		rv[b].push_back(a);
	}
	for(int i=1; i<=N; i++){
		int num = 0;
		num += dfs(i, v);
		num += dfs(i, rv);
		printf("%d\n", N-num+1);
	}
}