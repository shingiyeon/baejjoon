#include <stdio.h>
char star[400][400];

void s(int x, int y, int num){
	if(num==1){
		star[x][y] = '*';
		return;
	}
	int size = (num-1)*4+1;
	for(int i=0; i<size; i++){
		star[x][y+i] = '*';
		star[x+size-1][y+i] = '*';
		star[x+i][y] = '*';
		star[x+i][y+size-1] = '*';	
	}
	s(x+2,y+2,num-1);
	return;
}
int main(){
	int N; scanf("%d",&N);
	s(0,0,N);
	int size = (N-1)*4+1;
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			if(star[i][j]) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
}
