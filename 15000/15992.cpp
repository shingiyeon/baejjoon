//# Author : nuclear852 ========================#
//# Solution : 11637533 ========================#
//# Time Stamp : 2019-02-03 02:57:28 ===========#
//# Problem Title : 1, 2, 3 더하기 7 ==========#
//# Language : C++98 ===========================#

#include <stdio.h>
#define mod 1000000009
long long dy[1001][1001];

int main(){
	dy[1][1] = 1; dy[2][2] = 1; dy[2][1] = 1;
	dy[3][1] = 1; dy[3][2] = 2; dy[3][3] = 1;
	for(int i=4; i<=1000; i++){
		for(int j=1; j<=1000; j++){
			dy[i][j] = (dy[i-1][j-1] + dy[i-2][j-1] + dy[i-3][j-1])%mod;
		}
	}
	int T; scanf("%d" ,&T);
	while(T--){
		int n, m; scanf("%d%d",&n,&m);
		printf("%lld\n",dy[n][m]);
	}
}