#include <stdio.h>
int main(){
	int N; scanf("%d",&N);
	if(N==1){
		printf("*"); return 0;
	}
	for(int i=1; i<=N*2; i++){
		if(i%2){	
			for(int j=1; j<=(N+1)/2-1; j++)
				printf("* ");
		}
		else{
			printf(" ");
			for(int j=1; j<=N/2-1; j++)
				printf("* ");
		}
		printf("*\n");
	}
}
