//# Author : nuclear852 ========================#
//# Solution : 12765062 ========================#
//# Time Stamp : 2019-04-13 14:28:47 ===========#
//# Problem Title : 토마토 ====================#
//# Language : C++98 ===========================#

#include <stdio.h>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> p;
typedef pair<p, int> pd;
int map[1000][1000];
bool visited[1000][1000];
int M, N;
int main(){
	int answer = -1;
	scanf("%d%d", &M, &N);
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			scanf("%d", &map[i][j]);
		}
	}
	queue<pd> q;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(map[i][j]==1){
				q.push(make_pair(make_pair(i,j), 0));
				visited[i][j] = 1;
			}
		}
	}
	
	while( !q.empty() ){
		int i = q.front().first.first;
		int j = q.front().first.second;
		int day = q.front().second;
		answer = day;
		q.pop();
		
		if(i-1 >= 0 && map[i-1][j] == 0 && !visited[i-1][j]){
			q.push(make_pair(make_pair(i-1,j), day+1));
			map[i-1][j] = 1;
			visited[i-1][j] = 1;
		}
		if(i+1 < N && map[i+1][j] == 0 && !visited[i+1][j]){
			q.push(make_pair(make_pair(i+1,j), day+1));
			map[i+1][j] = 1;
			visited[i+1][j] = 1;
		}
		if(j-1 >= 0 && map[i][j-1] == 0 && !visited[i][j-1]){
			q.push(make_pair(make_pair(i,j-1), day+1));
			map[i][j-1] = 1;
			visited[i][j-1] = 1;
		}
		if(j+1 < M && map[i][j+1] == 0 && !visited[i][j+1]){
			q.push(make_pair(make_pair(i,j+1), day+1));
			map[i][j+1] = 1;
			visited[i][j+1] = 1;
		}
	}
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(map[i][j]==0)
				answer = -1;
		}
	}
	printf("%d", answer);
}