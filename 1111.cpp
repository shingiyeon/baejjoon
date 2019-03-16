#include <stdio.h>

int main(){
	int N; scanf("%d", &N);
	int arr[50];
	for(int i=0; i < N; i++){
		scanf("%d", &arr[i]);
	}
	if(N==1) {printf("A"); return 0;}
	else if(N==2){
		if(arr[0] != arr[1]) {printf("A"); return 0;}
		else {printf("%d", arr[0]); return 0;}
	}
	if(arr[0]==arr[1]){
		int cmp = arr[0];
		for(int i=2; i<N; i++){
			if(arr[i] != cmp){
				printf("B"); return 0;
			}
		}
		printf("%d", arr[0]);
		return 0;
	}
	int a = arr[1] - arr[0];
	int b = arr[2] - arr[1];

	if( !(b%a) ){
		int xa = b/a;
		int xb = arr[1] - arr[0] * xa;
		for(int i=2; i<N; i++){
			if(arr[i-1] * xa + xb != arr[i]){
				printf("B");
				return 0;
			}
		}
		printf("%d", arr[N-1] * xa + xb);
	}
	else{
		printf("B");
	}
}
