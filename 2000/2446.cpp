#include <stdio.h>
int main(){
	int N; scanf("%d", &N);
	for(int i=1; i<=N; i++){
		for(int j=1; j<=i-1; j++) printf(" ");
		for(int j=1; j<=2*(N-i+1)-1; j++) printf("*");
		printf("\n");
	}
	for(int i=1; i<=N-1; i++){
		for(int j=1; j<(N-i); j++) printf(" ");
		for(int j=1; j<=2*i+1; j++) printf("*");
		printf("\n");
	}
}
