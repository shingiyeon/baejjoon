//# Author : nuclear852 ========================#
//# Solution : 22093354 ========================#
//# Time Stamp : 2020-08-27 23:36:27 ===========#
//# Problem Title : 구간 합 구하기 2 =============#
//# Language : C++14 ===========================#

#include <stdio.h>
typedef long long ll;

using namespace std;

int N, M, K;
ll arr[3000001];
ll tree[3000001];
ll lazy[3000001];

ll init(int index, int s, int e) {
	if(s == e) {
		return tree[index] = arr[s];
	}
	int mid = (s+e) / 2;
	return tree[index] = init(index*2, s, mid) + init(index*2+1, mid+1, e);
}

ll find(int index, int s, int e, int left, int right) {
	if (lazy[index] != 0) {
		tree[index] += (e - s + 1) * lazy[index];
		if (s != e) {
			lazy[index * 2] += lazy[index];
			lazy[index * 2 + 1] += lazy[index];
		}
		lazy[index] = 0;
	}
	if (s > right || e < left) return 0;
	if (left <= s && e <= right) {
		return tree[index];
	}
	int mid = (s+e) / 2;
	return find(index*2, s, mid, left, right) + find(index*2+1, mid+1, e, left, right);
}

void update(int index, int s, int e, int left, int right, ll diff) {
	if (lazy[index] != 0) {
		tree[index] += (e - s + 1) * lazy[index];
		if (s != e) {
			lazy[index * 2] += lazy[index];
			lazy[index * 2 + 1] += lazy[index];
		}
		lazy[index] = 0;
	}
	
	if(right < s || left > e) return;
	
	if(left <= s && e <= right) {
		tree[index] += (e-s+1) * diff;
		if(s != e) {
			lazy[index*2] += diff;
			lazy[index*2 + 1] += diff;
		}
		return;
	}
	
	int mid = (s+e) / 2;
	update(index*2, s, mid, left, right, diff);
	update(index*2+1, mid+1, e, left, right, diff);
	
	tree[index] = tree[index*2] + tree[index*2+1];
}

int main() {
	scanf("%d%d%d", &N, &M, &K);
	for(int i=1; i<=N; i++) scanf("%lld", &arr[i]);
	init(1, 1, N);
	for(int j=1; j<=M+K; j++) {
		int tmp;
		ll a, b, c;
		scanf("%d", &tmp);
		if(tmp == 1) {
			scanf("%lld%lld%lld",&a,&b,&c);
			update(1, 1, N, a, b, c);
		}
		else {
			scanf("%lld%lld",&a,&b);
			printf("%lld\n", find(1, 1, N, a, b));
		}
	}
}