//# Author : nuclear852 ========================#
//# Solution : 12619139 ========================#
//# Time Stamp : 2019-04-06 16:16:48 ===========#
//# Problem Title : 암호 =====================#
//# Language : C++98 ===========================#

#include <stdio.h>
#define mod 1000000009ULL
typedef unsigned long long ull;
ull d[1000001];
int main(){
	int N; int K; scanf("%d%d",&N,&K);
	d[0] = 1;
	for(int i=1; i<=N; i++){
		if(i<=4) d[i] = d[i-1] * K;
		else if(i>=5 && i<7){
			d[i] = ( d[i-1] * K - 2 * d[i-5] + 2 * mod) % mod;
		}
		else{
			d[i] = ( d[i-1] * K - 2 * d[i-5] + d[i-7] + 2 * mod) % mod;
		}
	}
	printf("%u", d[N]);
}