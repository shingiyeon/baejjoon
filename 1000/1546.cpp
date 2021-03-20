#include <stdio.h>
int max(int a, int b){
	return a > b? a : b;
}
int main(){
	int N; int sum = 0; scanf("%d",&N); int val = 0;
	for(int i=0; i<N; i++){
		int temp;
		scanf("%d", &temp);
		val = max(val, temp);
		sum += temp;
	}
	printf("%lf", (double)sum/val*100/N);
}
