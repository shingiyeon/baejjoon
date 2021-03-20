#include <stdio.h>
#include <utility>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> p;

struct cmp{
	bool operator()(p t, p u){
		return t.second > u.second;
	}
};

priority_queue<p,vector<p>,cmp> pq;

vector<p> v[1001];
int MAX = 0;
int come_back[1001];
int road[1001];
bool visited[1001];
int N, M, X; 
int max(int a, int b){return a>b?a:b;}

void clear(){
	for(int i=0; i<=1000; i++) visited[i] = 0;
}

void back(){
	for(int i=0; i<=1000; i++) come_back[i] = 1000000000;
	pq.push(p(X,0)); 
	come_back[X] = 0;
	while(!pq.empty()){
		p t = pq.top(); pq.pop();
		if(visited[t.first]) continue;
		visited[t.first] = 1;
		for(int i=0; i<v[t.first].size(); i++){
			int x = v[t.first][i].second;
			int y = v[t.first][i].first;
			if(visited[y]) continue;
			if(come_back[t.first]+x < come_back[y]){
				come_back[y] = come_back[t.first] + x;
				pq.push(p(y,come_back[y]));
			}
		}		
	}
	
}

int dijkstra(int s){
	while(!pq.empty()) pq.pop();
	for(int i=0; i<=1000; i++) road[i] = 1000000000;
	pq.push(p(s,0));
	road[s] = 0;
	while(!pq.empty()){
		p t = pq.top(); pq.pop();
		if(t.first==X) return t.second;
		if(visited[t.first]) continue;
		visited[t.first] = 1;
		for(int i=0; i<v[t.first].size(); i++){
			int x = v[t.first][i].second;
			int y = v[t.first][i].first;
			if(visited[y]) continue;
			if(road[t.first]+x < road[y]){
				road[y] = road[t.first] + x;
				pq.push(p(y,road[y]));
			}
		}		
	}
	return road[X];
	
}

int main(){
	scanf("%d%d%d",&N,&M,&X);
	int A, B, C;
	while(M--){
		scanf("%d%d%d",&A,&B,&C);
		v[A].push_back(p(B,C));
	}
	back();
	for(int i=1; i<=N; i++){
		clear();
		MAX = max(MAX, dijkstra(i)+come_back[i]);
	}
	printf("%d", MAX);
}

