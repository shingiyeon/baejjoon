#include <stdio.h>
#include <vector>
#include <utility>
#define MAX 1000000000LL
using namespace std;
typedef pair<long long, int> p;
typedef long long ll;

ll maxv(ll x, ll y){
	return x < y? y : x;
}

ll a[100001];
vector<p> tree(262144);

p init(int node, int start, int end){
	if (start == end) {
		p temp(a[start], start);
		return tree[node] = temp;
	}
	else{
		p L = init(node*2, start, (start+end)/2);
		p R = init(node*2+1, (start+end)/2+1, end);
		if(L.first<=R.first) return tree[node] = L;
		else return tree[node] = R;
	
	}	
}

p mintree(int node, int start, int end, int left, int right){
	if(left > end || right < start) { p temp(MAX, MAX); return temp;}
	if(left<=start && end <= right) return tree[node];
	p L = mintree(node*2, start, (start+end)/2, left, right);
	p R = mintree(node*2+1, (start+end)/2+1, end, left, right);
	if(L.first<R.first) return L;
	else return R;
}

ll search_maxarea(int start, int end, int left, int right){
	if(left > right || left < start || end < right) return 0;
	if(left == right) return a[left];
	p pivot = mintree(1, start, end, left, right);
	ll max = pivot.first * (ll)(right - left + 1);

	if (pivot.second == left) {
		ll temp = search_maxarea(start, end, left+1, right);
		max = maxv(temp, max);
	}
	else if(pivot.second == right) {
		ll temp = search_maxarea(start, end, left, right-1);
		max = maxv(temp, max);
	}
	else{
		ll temp = search_maxarea(start, end, left, pivot.second-1);
		max = maxv(temp, max);
		temp = search_maxarea(start, end, pivot.second+1, right);
		max = maxv(temp, max);
	}
	return max;
}

int main(){
	int N;
	while(1){
		scanf("%d", &N);
		if(!N) return 0;
		for(int i=1; i<=N; i++) scanf("%lld", &a[i]);
		init(1, 1, N);
		printf("%lld\n", search_maxarea(1, N, 1, N));
	}	
}
