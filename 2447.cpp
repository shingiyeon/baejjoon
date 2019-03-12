#include <stdio.h>

bool star[2188][2188];

void d(int x, int y, int size){
	if(size == 3){
		for(int i=0; i<3; i++)
			for(int j=0; j<3; j++)
				star[x+i][y+j] = 1;
		star[x+1][y+1] = 0;
		return;
	}
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(i==1 && j==1) continue;
			d(x + size/3*i, y+size/3*j, size/3);
		}
	}
	return;
}
int main(){
	int N; scanf("%d",&N);
	if(N==1) {printf("*"); return 0;}
	d(0,0,N);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(!star[i][j]) printf(" ");
			else printf("*");
		}
		printf("\n");
	}
}
