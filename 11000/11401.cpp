//# Author : nuclear852 ========================#
//# Solution : 11529848 ========================#
//# Time Stamp : 2019-01-26 08:28:18 ===========#
//# Problem Title : 이항 계수 3 ================#
//# Language : C++98 ===========================#

#include <stdio.h>
#define mod 1000000007LL
typedef long long ll;

ll fac[4000001], inv[4000001];

ll power(ll x, int p){
	ll temp = 1;
	while(p>0){
		if(p%2)	temp = (temp * x) % mod;
		x = (x * x) % mod;
		p/=2;
	}
	return temp;
}

int main() {
	int N, K; scanf("%d%d",&N,&K);
	fac[0] = 1;
	for(int i=1; i<=N; i++)
		fac[i] = (fac[i-1] * i) % mod;
	printf("%lld", (power((fac[K]*fac[N-K])%mod,mod-2)*fac[N])%mod);
}