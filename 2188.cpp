#include <stdio.h>
#include <vector>
using namespace std;

vector<int> a[201];

bool visited[201];
int bmatched[201];
bool dfs(int x){
	if(visited[x]) return 0;
	visited[x] = 1;
	
	for(int i=0; i<a[x].size(); i++){
		if(bmatched[a[x][i]]==-1 || dfs(bmatched[a[x][i]])){
			bmatched[a[x][i]] = x;
			return 1;
		}
	}
	return 0;
}

int main(){
	int N, M; scanf("%d%d",&N,&M);
	for(int i=1; i<=N; i++){
		int K; scanf("%d",&K);
		int temp;
		while(K--){
			scanf("%d",&temp);
			a[i].push_back(temp);
		}
	}
	for(int i=0; i<=200; i++) bmatched[i] = -1;
	int ans = 0;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++) visited[j] = 0;
		ans += dfs(i);
	}
	
	printf("%d",ans);
}
