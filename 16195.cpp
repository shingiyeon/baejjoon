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
		long long sum = 0;
		for(int i=1; i<=m; i++){
			sum = (sum + dy[n][i])%mod;
		}
		printf("%lld\n",sum);
	}
}
