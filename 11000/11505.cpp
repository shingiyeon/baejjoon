//# Author : nuclear852 ========================#
//# Solution : 22143971 ========================#
//# Time Stamp : 2020-08-29 22:34:52 ===========#
//# Problem Title : 구간 곱 구하기 ===============#
//# Language : C++14 ===========================#

#include <stdio.h>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int N, M, K;

ll arr[1000001];
ll tree[3000001];

ll init(int index, int start, int end) {
	if(start == end){
		return tree[index] = arr[start];
	}
	int mid = (start + end) / 2;
	return tree[index] = (init(index * 2, start, mid) * init(index*2+1, mid+1, end)) % MOD;
}

ll find(int index, int start, int end, int left, int right) {
	if(left <= start && end <= right) {
		return tree[index];
	}
	else if(left > end || right < start) {
		return 1;
	}
	int mid = (start + end) / 2;
	ll left_val = find(index * 2, start, mid, left, right);
	ll right_val = find(index * 2 + 1, mid+1, end, left, right);
	return (left_val * right_val) % MOD;
}

ll update(int index, int start, int end, int cur, ll after) {
	if(start > cur || cur > end) return tree[index];
	if(start == end && start == cur) {
		return tree[index] = after % MOD;
	}
	int mid = (start + end) / 2;
	ll left_val = update(index * 2, start, mid, cur, after);
	ll right_val = update(index * 2 + 1, mid + 1, end, cur, after);
	return tree[index] = (left_val * right_val) % MOD;
}

int main() {
	scanf("%d%d%d", &N, &M, &K);
	for(int i=1; i<=N; i++) scanf("%lld", &arr[i]);
	init(1, 1, N);
	for(int i=1; i<=M+K; i++) {
		int a, b; ll c;
		scanf("%d%d%lld",&a,&b,&c);
		if(a==1) {
			update(1, 1, N, b, c);
		}
		else {
			printf("%lld\n", find(1, 1, N, b, c));
		}
	}
}