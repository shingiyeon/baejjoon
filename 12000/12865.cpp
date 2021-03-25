//# Author : nuclear852 ========================#
//# Solution : 15189978 ========================#
//# Time Stamp : 2019-09-18 20:31:40 ===========#
//# Problem Title : 평범한 배낭 =================#
//# Language : C++14 ===========================#

#include <iostream>
#include <stdio.h>
using namespace std;
int N, K;
int W[101], V[101];
int dp[101][100001];
int max(int a, int b){
	return a > b? a : b;
}
int main() {
	// your code goes here
	scanf("%d%d",&N,&K);
	for(int i=1; i<=N; i++) scanf("%d%d", &W[i], &V[i]);
	
	for(int i=1; i<=N; i++) {
		for(int j=0; j<=K; j++){
			dp[i][j] = dp[i-1][j];
			if(j - W[i] >= 0 ) {
				dp[i][j] = max(dp[i][j], dp[i-1][j-W[i]] + V[i]);
			}
		}
	}
	
	printf("%d", dp[N][K]);
	
	return 0;
}