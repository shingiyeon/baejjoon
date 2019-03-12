#include <stdio.h>

bool map[64][64];

void dy(int x, int y, int N){
	bool cmp = map[x][y];
	for(int i=x; i<x+N; i++){
		for(int j=y; j<y+N; j++){
			if(cmp != map[i][j]){
				printf("(");
				dy(x,y,N/2); dy(x,y+N/2,N/2);
				dy(x+N/2,y,N/2); dy(x+N/2,y+N/2,N/2);
				printf(")");
				return;
			}
		}
	}
	printf("%d", cmp);
}
int main(){
	int N; scanf("%d",&N);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			scanf("%1d",&map[i][j]);
		}
	}
	dy(0,0,N);
}
