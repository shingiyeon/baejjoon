#include <stdio.h>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int visited[25][25];
int map[25][25];
int idxa[5000];
int main(){
	int N; scanf("%d",&N);
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
			scanf("%1d",&map[i][j]);
	}

	queue< pair<int,int> > q;
	pair<int,int> p;
	int dx[4] = {-1, 1, 0, 0};
	int dy[4] = {0, 0, -1, 1};
	int idx = 1;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(!visited[i][j] && map[i][j]){
				p.first = i; p.second = j;
				q.push(p);
				visited[i][j] = idx;
				while(!q.empty()){
					int tx = q.front().first; int ty = q.front().second; q.pop();
					//printf("%d %d\n",tx,ty);
					for(int k=0; k<4; k++){
						if(tx+dx[k]<0 || tx+dx[k]>=N || ty+dy[k]<0 || ty+dy[k]>=N) continue;
						if(visited[tx+dx[k]][ty+dy[k]]!=0) continue;
						if(map[tx+dx[k]][ty+dy[k]]==0) continue;
						p.first = tx+dx[k]; p.second = ty+dy[k];
						visited[tx+dx[k]][ty+dy[k]] = idx;
						q.push(p);
					}
				}
				idx++;
			}
		}
	}
	printf("%d\n", idx-1);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(visited[i][j])	idxa[visited[i][j]]++;
		}
	}
	sort(idxa, idxa+5000);
	for(int i=0; i<5000; i++){
		if(idxa[i]) printf("%d\n",idxa[i]);
	}
}
