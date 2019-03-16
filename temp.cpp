#include <stdio.h>

int main(){
	int N; scanf("%d", &N);
	int j;
	int x;
	for(j=2; j<=N-2; j++){
		x = N % j;
		if(x==0){
			printf("소수가 아닙니다\n");
			break;
		}
	}
	if(x>=1)
		printf("소수입니다.\n");
}
