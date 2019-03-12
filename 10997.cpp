#include <stdio.h>
char star[410][410];

void s(int n, int x, int y){
	if(n==2){
		for(int i=0; i<5; i++) {star[x][y+i] = '*'; star[x+6][y+i] = '*';}
		for(int i=0; i<7; i++) star[x+i][y] = '*';
		for(int i=2; i<7; i++) star[x+i][y+4] = '*';
		star[x+2][y+2] = '*';star[x+2][y+3] = '*';
		star[x+3][y+2] = '*';star[x+4][y+2] = '*';
		return ;
	}
	for(int i=0; i<1+(4*(n-1)); i++)
	{	star[x][y+i] = '*'; star[x+2+(4*(n-1))][y+i] = '*';}
	for(int i=0; i<3+(4*(n-1)); i++)
	{	star[x+i][y] = '*'; if(i>=2) star[x+i][y+(4*(n-1))] ='*';}
	star[x+2][y+(4*(n-1))-1] = '*';
	s(n-1, x+2, y+2);
}
int main(){
	int n; scanf("%d", &n);
	if(n==1) {printf("*"); return 0;}
	s(n, 0, 0);
	for(int x=0; x<3+(4*(n-1)); x++){
		if(x==1){
			printf("*\n"); continue;
		}
		for(int y=0; y<1+(4*(n-1)); y++){
			if(!star[x][y]) printf(" ");
			else printf("*");
		}
		printf("\n");
	}
}
