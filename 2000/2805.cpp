#include <stdio.h>
typedef long long ll;
ll MIN = 1000000000000000;
ll pivot;
ll min(ll a, ll b){return a<b?a:b;}
ll N, M;
int t[1000000];
void search(ll s, ll e){
	ll sum = 0;
	if(s>e) return;
	ll mid = (s+e)/2;
	for(int i=0; i<N; i++){
		if(t[i]<mid) continue;
		sum += (t[i]-mid);
	}
	if(sum<M){
		MIN = min(MIN, sum);
		search(s, mid-1);
		return;
	}
	else if(sum == M){
		pivot = mid;
		return;
	}
	pivot = mid;
	search(mid+1, e);
	return;
}

int main(){
	scanf("%lld%lld",&N,&M);
	for(ll i=0; i<N; i++) scanf("%d",&t[i]);
	search(0, 1000000000);
	printf("%lld", pivot);
}
