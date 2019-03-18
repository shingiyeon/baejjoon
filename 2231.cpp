#include <stdio.h>
#define MAX 10000001
int arr[1000001];

int main(){
	int N; scanf("%d", &N);
	for(int i=1000000; i>=1; i--){
		int sum = i;
		int temp = i;
		while(temp){
			sum += temp%10;
			temp /= 10;
		}
		if(sum<=1000000&&sum>=0){
			arr[sum] = i;
		}
	}
	printf("%d", arr[N]);
}

