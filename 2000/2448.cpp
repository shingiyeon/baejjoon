#include <stdio.h>
#include <math.h>
char star[3073][6145];

void make_star(int x, int y, int N){
	if (N==3){
		star[x][y+2] = '*';
		star[x+1][y+1] = '*';
		star[x+1][y+3] = '*';
		for(int i=0; i<5; i++) star[x+2][y+i] = '*';
	}
	else{
		make_star(x + N/2, y, N/2);
		make_star(x, y + N/2, N/2 );
		make_star(x + N/2, y + N, N/2);
	}
}

int main(){
	
	int N; scanf("%d",&N);
	int K = log2(N/3);
	make_star(0,0,N);
	for(int i=0; i<N; i++){
		for(int j=0; j<N*2; j++){
			if(star[i][j] == '*')
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
}
