//# Author : nuclear852 ========================#
//# Solution : 11578648 ========================#
//# Time Stamp : 2019-01-29 18:22:14 ===========#
//# Problem Title : 이항 쇼다운 =================#
//# Language : C++98 ===========================#

#include <stdio.h>
typedef long long ll;
int main() {
	int N, K;
	while (1){
		scanf("%d%d",&N,&K);
		if(!N&&!K)
			return 0;
		K = (K>N-K) ? N-K: K;
		ll ans = 1;
		for(int i=1; i<=K; i++)
			ans = ans * (N-K+i) / i;

		printf("%lld\n", ans);
	}

	return 0;
}