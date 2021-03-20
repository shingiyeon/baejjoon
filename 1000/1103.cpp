#include <stdio.h>
#define MIN -999999999
int d[55][55];
int visited[55][55];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int map[55][55];
int N, M;
int max(int x, int y){
	if(x<0 || y<0) return MIN;
	return x > y? x : y;
}


int dfs(int x, int y, int num)
{
    //printf("DFS || x: %d, y: %d, num: %d\n",x,y,num);
	if(visited[x][y] == -1) 	return MIN;
	if(visited[x][y] == 1) return  d[x][y];
	visited[x][y] = -1;
	int MAX = 0;
	int g = map[x][y];
	for(int i=0; i<4; i++){
		int k;
		if(!map[x+g*dx[i]][y+g*dy[i]]) k = 1;
		else if(x+g*dx[i]<0 || x+g*dx[i]>=N || y+g*dy[i]<0 || y+g*dy[i]>=M)
			k = 1;
		else k = dfs(x+g*dx[i], y+g*dy[i], num+1)+1;
		MAX = max(MAX,k);
	}
	visited[x][y] = 1;
	return d[x][y] = MAX;
}

int main(){
	scanf("%d%d",&N,&M);
	char m[55];
	for(int i=0; i<N; i++){
		scanf("%s", m);
		for(int j=0; m[j]!='\0'; j++){
			if(m[j]=='H')
				map[i][j] = 0;
			else
				map[i][j] = m[j] - '0';
		}
	}
	int tmp;
	printf("%d", (tmp = dfs(0,0,0))<0? -1 : tmp);

}
