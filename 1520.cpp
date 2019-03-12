#include <stdio.h>

int d[500][500];
int map[500][500];
int M, N; 

int dfs(int x, int y){
	if (x==M-1 && y==N-1)
		return 1;
	if (x<0 || x>=M || y<0 || y>=N)
		return 0;
	if (d[x][y] != -1)
		return d[x][y];
	int dx[4] = {-1, 1, 0, 0};
	int dy[4] = {0, 0, -1, 1};
	int sum = 0;
	for(int k=0; k<4; k++){
		if(x+dx[k]<0 || x+dx[k]>=M || y+dy[k]<0 || y+dy[k]>=N) continue;
		if(map[x][y] > map[x+dx[k]][y+dy[k]]){
			sum = sum + dfs(x+dx[k], y+dy[k]);
		}
	}
	return d[x][y] = sum;
}

int main(){
	scanf("%d%d",&M,&N);
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			scanf("%d", &map[i][j]);
			d[i][j] = -1;
		}
	}

	printf("%d",dfs(0,0));
}
