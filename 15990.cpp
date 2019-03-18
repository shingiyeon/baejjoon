#include <stdio.h>
#define mod 1000000009
long long d[100001][4];

int main(){
	d[1][1] = 1; d[2][2] = 1; d[3][1] = 1; d[3][2]=1; d[3][3] = 1;
	for(int i=4; i<=100000; i++){
		d[i][1] = (d[i-1][2] + d[i-1][3]) % mod;
		d[i][2] = (d[i-2][1] + d[i-2][3]) % mod;
		d[i][3] = (d[i-3][1] + d[i-3][2]) % mod;
	}
	int T; scanf("%d", &T);
	while(T--){
		int temp; scanf("%d",&temp);
		printf("%d\n",(d[temp][1]+d[temp][2]+d[temp][3])%mod);
	}
}
