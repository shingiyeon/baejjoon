#include <stdio.h>
int main(){
	int T; scanf("%d",&T);
	int arr[15][15];
	for(int i=0; i<15; i++) arr[0][i] = i;
	for(int i=1; i<15; i++){
		for(int j=1; j<15; j++){
			int sum = 0;
			for(int k=1; k<=j; k++)
				sum += arr[i-1][k];
			arr[i][j] = sum;
		}
	}
	while(T--){
		int n, k; scanf("%d%d",&n,&k);
		printf("%d\n",arr[n][k]);
	}
}
