#include <stdio.h>
char star[1024][2046];
int dy[11] = {0,1,5,13,29,61,125,253,509,1021,2045};
int dx[11] = {0,1,3,7,15,31,63,127,255,511,1023};
void s(int x, int y, int num){
	if(num==1) { star[x][y]='*'; return;}
	if(!(num%2)){
		for(int i=0; i<dy[num]; i++) star[x][y+i] = '*';
		for(int j=1; j<dx[num]; j++){
			star[x+j][y+j] = '*';
			star[x+j][y+dy[num]-1-j] = '*';
		}
		s(x+1, y+(dy[num]-1)/4+1, num-1);
		return;
	}
	for(int i=0; i<dy[num]; i++) star[x+dx[num]-1][y+i] = '*';
	for(int i=0; i<dx[num]-1; i++){
		star[x+i][y+dx[num]-1-i] ='*';
		star[x+i][y+dx[num]-1+i] ='*';
	}
	s(x+dx[num]/2, y+(dy[num]-1)/4+1, num-1);
	return;
}
int main(){
	int N; scanf("%d" ,&N);
	s(0,0,N);
	if(N%2){
		for(int i=0; i<dx[N]; i++){
			for(int j=0; j<dy[N]/2+i+1; j++){
				if(star[i][j]) printf("*");
				else printf(" ");
			}
			printf("\n");
		}
	}
	else{
		for(int i=0; i<dx[N]; i++){
			for(int j=0; j<dy[N]-i; j++){
				if(star[i][j]) printf("*");
				else printf(" ");
			}
			printf("\n");
		}
	}
}


