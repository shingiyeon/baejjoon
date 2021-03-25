//# Author : nuclear852 ========================#
//# Solution : 11589406 ========================#
//# Time Stamp : 2019-01-30 13:54:42 ===========#
//# Problem Title : 노트북의 주인을 찾아서 ===========#
//# Language : C++98 ===========================#

#include <stdio.h>
#include <vector>
using namespace std;

int N;
bool map[101][101];
int bmatched[101];
int amatched[101];
bool visited[101];
bool dfs(int x){
	if (visited[x]) return 0;
	visited[x] = 1;
	for(int i=1; i<=N; i++){
		if(map[x][i]){
			if(bmatched[i] == -1 || dfs(bmatched[i])){
				bmatched[i] = x;
				amatched[x] = i;
				return 1;
			}
		}
	}
	return 0;
}

int main(){
	int M; scanf("%d%d",&N,&M);
	for(int i=1; i<=N; i++){
		bmatched[i] = -1;
	}
	for(int i=0; i<M; i++){
		int s,f;
		scanf("%d%d",&s,&f);
		map[s][f] = 1;
	}
	int ans = 0;
	for(int i=1; i<=N; i++)	{ for(int j=1; j<=N; j++) visited[j] = 0; ans += dfs(i);}
	printf("%d", ans);
	
}