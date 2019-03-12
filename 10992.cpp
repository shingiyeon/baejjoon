#include <stdio.h>
int main(){
	int N; scanf("%d", &N);
	for(int i=1; i<=N-1; i++) printf(" ");
	printf("*\n");
	for(int i=2; i<=N-1; i++){
		for(int j=1; j<=N-i; j++) printf(" ");
		printf("*");
		for(int j=1; j<=(2*(i-1))-1; j++) printf(" ");
		printf("*\n");
	}
	if(N!=1) for(int i=1; i<=2*N-1; i++) printf("*");
}
