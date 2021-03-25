//# Author : nuclear852 ========================#
//# Solution : 11631063 ========================#
//# Time Stamp : 2019-02-02 16:28:17 ===========#
//# Problem Title : 1, 2, 3 더하기 6 ==========#
//# Language : C++98 ===========================#

#include <stdio.h>
#define mod 1000000009
long long d[100001];

int main(){
	d[0] = 1; d[1] = 1; d[2] = 2; d[3] = 2;
	d[4] = 3; d[5] = 3; d[6] = 5;
	for(int i=4; i<=100000; i++){
		d[i] = (d[i-2] + d[i-4] + d[i-6])%mod;
	}
	int T; scanf("%d", &T);
	while(T--){
		int t; scanf("%d",&t);
		printf("%d\n", d[t]);
	}
}