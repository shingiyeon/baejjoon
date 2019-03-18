#include <stdio.h>
int r, c;
int N;

void f(int x, int y, int size, int num){
	if(size == 1){
		if(x==r&&y==c)
			printf("%d", num);
		else if(x==r&&y+1==c)
			printf("%d", num+1);
		if(x+1==r&&y==c)
			printf("%d", num+2);
		if(x+1==r&&y+1==c)
			printf("%d", num+3);
		return;
	}
	int k = 1;
	for(int i=1; i<=size-1; i++) k *= 2;
	f(x,y,size-1,num);
	f(x,y+k,size-1,num+(k*k));
	f(x+k,y,size-1,num+2*(k*k));
	f(x+k,y+k,size-1,num+3*(k*k));
	return;
}

int main(){
	scanf("%d%d%d",&N,&r,&c);
	f(0,0,N,0);
}
