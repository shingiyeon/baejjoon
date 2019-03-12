#include <stdio.h>
long long sum[1000001];
long long count[1000];
int main(){
	long long cnt = 0;
	int N, M; scanf("%d%d",&N,&M);
	for(int i=1; i<=N; i++){
		int temp; scanf("%d", &temp);
		sum[i] = (sum[i-1] + temp)%M;
		if(!sum[i]) cnt++;
		count[sum[i]]++;
	}
	for(int i=0; i<M; i++)
		cnt += count[i] * (count[i] - 1) /2;
	printf("%lld", cnt);
}
