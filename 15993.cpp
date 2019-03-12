#include <stdio.h>
#define mod 1000000009
long long dy[100001][2];
int main(){
	dy[1][1] = 1; dy[2][1]=1; dy[2][0] = 1;
	dy[3][1] = 2; dy[3][0] =2;
	for(int i=4; i<=100000; i++){
		dy[i][0] = (dy[i-1][1] + dy[i-2][1] + dy[i-3][1])%mod;
		dy[i][1] = (dy[i-1][0] + dy[i-2][0] + dy[i-3][0])%mod;
	}
	int T; scanf("%d",&T);
	while(T--){
		int n; scanf("%d",&n);
		printf("%d %d\n",dy[n][1],dy[n][0]);
	}
}
