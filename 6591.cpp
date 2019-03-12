#include <stdio.h>
typedef long long ll;
int main() {
	int N, K;
	do{
		scanf("%d%d",&N,&K);
		if(K>N-K) K = N-K;
		ll ans = (ll)1;
		for(int i=1; i<=K; i++)
		{	ans *= N-i+1; ans /= i;}
		if(!(N==0&&K==0))
			printf("%lld\n", ans);
	}while(!(N==0&&K==0));
}
