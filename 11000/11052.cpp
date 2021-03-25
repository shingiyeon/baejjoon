//# Author : nuclear852 ========================#
//# Solution : 11368588 ========================#
//# Time Stamp : 2019-01-15 18:03:56 ===========#
//# Problem Title : 카드 구매하기 ================#
//# Language : C++98 ===========================#

#include <stdio.h>
int max(int a, int b){
	return a >= b? a : b;
}
int main(){
	int N;
	scanf("%d",&N);
	
	int arr[1001];
	int dy[1001];
	for(int i=1; i<=N; i++){
		scanf("%d",&arr[i]);
		dy[i] = 0;
	}
	dy[0] = 0;
	
	for(int i=1; i<=N; i++){
		for(int j=1; j<=i; j++){
			dy[i] = max(dy[i], dy[i-j] + arr[j]); 
		}
	}
	printf("%d", dy[N]);
}