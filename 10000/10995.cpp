#include <stdio.h>
int main(){
	int N; scanf("%d", &N);
	for(int i=1; i<=N; i++){
		if(i%2==0) printf(" ");
		for(int j=1; j<N; j++) printf("* ");
		printf("*\n");
	}
}
