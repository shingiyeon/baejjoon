#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

vector< vector<int> > t(100001);
int parent[100001];
bool visited[100001];
void bfs(){
	queue<int> q;
	q.push(1);
	visited[1] = 1;
	while(!q.empty()){
		int v = q.front(); q.pop();
		for(int i=0; i<t[v].size(); i++){
			if(visited[t[v][i]]) continue;
			visited[t[v][i]] = 1;
			parent[t[v][i]] = v;
			q.push(t[v][i]);
		}
	}
}

int main(){
	int a, b;
	int N; scanf("%d", &N);
	for(int i=1; i<N; i++){
		scanf("%d%d",&a,&b);
		t[a].push_back(b);
		t[b].push_back(a);		
	}
	bfs();
	for(int i=2; i<=N; i++){
		printf("%d\n", parent[i]);
	}
}
