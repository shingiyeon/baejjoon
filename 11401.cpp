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
