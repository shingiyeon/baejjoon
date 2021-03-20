#include <stdio.h>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> p;

int N;
int map[100][100];
int MIN = 200;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int min(int a, int b){return a<b?a:b;}

bool bfs(int a, int b){
	if(map[0][0] < a || map[0][0]>b) return 0;
	
	bool visited[100][100];
	for(int i=0; i<100; i++){
		for(int j=0; j<100; j++) visited[i][j] = 0;
	}
	
	queue< p > q;
	q.push( p(0,0));
	visited[0][0] = 1;
	int minv = 200; int maxv = 0;
	while(!q.empty()){
		p t = q.front(); q.pop();
		int x = t.first, y = t.second;
		if(x==N-1 && y==N-1) return 1;
		if(map[x][y]>maxv) maxv = map[x][y];
		if(map[x][y]<minv) minv = map[x][y];
		for(int i=0; i<4; i++){
			if(x+dx[i]<0||x+dx[i]>=N||y+dy[i]<0||y+dy[i]>=N) continue;
			if(visited[x+dx[i]][y+dy[i]]) continue;
			if(map[x+dx[i]][y+dy[i]]<a || map[x+dx[i]][y+dy[i]]>b) continue;
			visited[x+dx[i]][y+dy[i]] = 1;
			q.push(p(x+dx[i],y+dy[i]));
		}
	}
	return 0;
}

void search(int s, int e){
	if(s>e) return;
	int mid = (s+e)/2;
	bool pos = 0;
	for(int i=0; i+mid<=200; i++){
		bool temp = bfs(i, i+mid);
		if(temp) {
			MIN = min(MIN, mid);
			pos = 1;
		}
	}
	if(pos)	{search(s,mid-1); return;}
	search(mid+1,e); return;
}


int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++)
			scanf("%d",&map[i][j]);
	}
	search(0,200);
	printf("%d", MIN);
}
