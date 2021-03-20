#include <stdio.h>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
typedef pair<int, int> p;
bool visited[100][100];
int map[100][100];
int N, M; 
bool checked(){
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(map[i][j])	return 0;
		}
	}
	return 1;
}
void melt(){
	int dx[4] = {-1, 1, 0, 0};
	int dy[4] = {0, 0, 1, -1};
	vector< p > v;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			visited[i][j] = 0;
		}
	}
	
	queue< p > q;
	p start(0,0);
	q.push(start); visited[0][0] = 1;
	while(!q.empty()){
		p t = q.front(); q.pop();
		int x= t.first, y=t.second;
		for(int k=0; k<4; k++){
			if(x+dx[k]<0 || x+dx[k]>=N || y+dy[k]<0 || y+dy[k]>=M)continue;
			if(visited[x+dx[k]][y+dy[k]]) continue;
			if(map[x+dx[k]][y+dy[k]]) continue;
			t.first = x+dx[k]; t.second = y+dy[k];
			visited[x+dx[k]][y+dy[k]] = 1;
			q.push(t);
		}
	}
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(!map[i][j]) continue;
			int num = 0;
			for(int k=0; k<4; k++){
				if(visited[i+dx[k]][j+dy[k]])	num++;
			}
			if(num>=2){
				pair<int,int> p(i,j);
				v.push_back(p);
			}
		}
	}
	for(int i=0; i<v.size(); i++){
		map[v[i].first][v[i].second] = 0;
	}
}

int main(){
	scanf("%d%d",&N,&M);
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++)
			scanf("%d", &map[i][j]);
	}
	int k = 0;
	while(!checked()){
		k++;
		melt();
	}
	printf("%d", k);
}
