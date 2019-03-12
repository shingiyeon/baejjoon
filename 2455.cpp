#include <stdio.h>
int arr[4][2];
int main(){
	for(int i=0; i<4; i++)
		for(int j=0; j<2; j++)
			scanf("%d", &arr[i][j]);
	int sum = 0;
	int max = 0;
	for(int i=0; i<4; i++){
		sum += arr[i][1] - arr[i][0];
		if(sum > max) max = sum;
	}
	printf("%d", max);
}
