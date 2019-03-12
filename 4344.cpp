#include <stdio.h>
int main(){
	int C; scanf("%d",&C);
	while(C--){
		int N; int arr[1000]; float avg = 0;
		int pos = 0;
		scanf("%d",&N);
		for(int i=0; i<N; i++) {
			scanf("%d",&arr[i]);
			avg += arr[i];
		}
		avg /= N;
		for(int i=0; i<N; i++)
			if(arr[i] > avg) pos++;
		printf("%.3f%%\n", (float)pos/N*100);
	}
}
