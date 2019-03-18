#include <stdio.h>
int arr[1001][1001];
int main(){
	int C, R, K; scanf("%d%d%d",&C,&R,&K);
	if(K>C*R) {printf("0");return 0;}
	
	int idx = 0;
	int x=1, y=0;
	int dy[4] = {1, 0, -1, 0};
	int dx[4] = {0, 1, 0, -1};
	int dir = 0;
	int garo = R, sero = C-1;
	while(idx<K){
		if(!(dir%2)){
			for(int i=0; i<garo; i++)
			{
				idx++; y += dy[dir];
				arr[x][y] = idx;
				if(idx == K)
					break;
			}
			garo--;
		}
		else{
			for(int i=0; i<sero; i++){
				idx++; x += dx[dir];
				arr[x][y] = idx;
				if(idx == K)
					break;
			}
			sero--;
		}
		if(idx == K){
			printf("%d %d",x,y);
			return 0;
		}
		dir = (dir+1)%4;
	}
	
	printf("%d %d",x,y);
}
