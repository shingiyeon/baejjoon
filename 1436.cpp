#include <stdio.h>
bool find(int N){
	while(N){
		if(N%1000==666) return 1;
		N /= 10;
	}
	return 0;
}
int main(){
	int arr[30000];
	int idx=0;
	for(int i=1; i<=5000000; i++){
		if(find(i)){
			arr[idx++] = i;
		}
	}
	int N; scanf("%d", &N);
	printf("%d", arr[N-1]);
}
