//# Author : nuclear852 ========================#
//# Solution : 15087241 ========================#
//# Time Stamp : 2019-09-11 13:40:24 ===========#
//# Problem Title : 카드게임 ===================#
//# Language : C++98 ===========================#

#include <stdio.h>

int MAX;
int dp[2001][2001];
int A[2000], B[2000];
int N;

int max(int a, int b){
	return a > b? a : b;
}

int d(int a, int b){
	if(dp[a][b] != -1) return dp[a][b];
	if(a==N || b==N) return dp[a][b] = 0;
	
	dp[a][b] = max(dp[a][b], d(a+1, b));
	dp[a][b] = max(dp[a][b], d(a+1, b+1));
	if( A[a] > B[b])
		dp[a][b] = max(dp[a][b], d(a, b+1) + B[b]);
	return dp[a][b];
}

int main(){
	for(int i=0; i<=2000; i++){
		for(int j=0; j<=2000; j++){
			dp[i][j] = -1;
		}
	}
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d", &A[i]);
	for(int i=0; i<N; i++) scanf("%d", &B[i]);
	
	printf("%d", d(0, 0));
	
}