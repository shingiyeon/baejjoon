#include <stdio.h>

int A[100][100];
int B[100][100];
int C[100][100];

int main(){
	int N, M; scanf("%d%d",&N,&M);
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++)
			scanf("%d",&A[i][j]);
	}
	int K, L; scanf("%d%d",&K,&L);
	for(int i=0; i<M; i++){
		for(int j=0; j<L; j++)
			scanf("%d",&B[i][j]);
	}
	
	for(int i=0; i<N; i++){
		for(int j=0; j<L; j++){
			int sum = 0;
			for(int k=0; k<M; k++){
				sum += A[i][k] * B[k][j];
			}
			C[i][j] = sum;
		}
	}
	for(int i=0; i<N; i++){
		for(int j=0; j<L; j++){
			printf("%d ", C[i][j]);
		}
		printf("\n");
	}
	
}
