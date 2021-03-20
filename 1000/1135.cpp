#include <stdio.h>
#include <vector>
#include <utility>
using namespace std;
vector<int> node[51];
int parent[51];
int max(int a, int b){return a>b?a:b;}
int dfs(int index, int num){
	int MAX = 0;
	if(!node[index].size()) return num;
	
	for(int i=0; i<node[index].size(); i++){
		MAX = max(MAX, dfs(node[index][i], num+i+1));
	}
	return MAX;
}

int main(){
	int N; scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d", &parent[i]);
	for(int i=0; i<N; i++){
		if(parent[i]!=-1)
			node[parent[i]].push_back(i);
	}
	int answer = 0;
	for(int i=0; i<N; i++){
		if(parent[i]==-1){
			answer = max(answer, dfs(i, 0));
		}
	}
	printf("%d", answer);
	
}
