//# Author : nuclear852 ========================#
//# Solution : 21995881 ========================#
//# Time Stamp : 2020-08-24 23:30:52 ===========#
//# Problem Title : 구간 합 구하기 ===============#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <math.h>
typedef long long ll;
using namespace std;

ll tree[3000000];
ll num[1000001];
int N, M, K;

ll init(int index, int start, int end) {
	if(start == end) {
		return tree[index] = num[start];
	}
	int mid = (start + end) / 2;
	return tree[index] = init(2 * index, start, mid) + init(2 * index + 1, mid + 1, end);
}

ll find(int index, int start, int end, int left, int right){;
	if (left <= start && end <= right) return tree[index];
	if (right < start || end < left) return 0;
	int mid = (start + end) / 2;
	return find(2 * index, start, mid, left, right) + find(2 * index + 1, mid+1, end, left, right);
}	

void update(int index, int start, int end, int t, ll diff) {
	if(start <= t && t <= end) {
		tree[index] += diff;
	}
	else {
		return;
	}
	if(start == end) return;
	int mid = (start + end) / 2;
	update(2 * index, start, mid, t, diff);
	update(2 * index + 1, mid + 1, end, t, diff);
}

int main() {
	scanf("%d%d%d", &N, &M, &K);
	for(int i=1; i<=N; i++) scanf("%lld", &num[i]);
	ll a,b,c;
	init(1, 1, N);
	for(int i=0; i<M+K; i++) {
		scanf("%lld%lld%lld", &a, &b, &c);
		if(a==1) {
			ll diff = c - num[b];
			num[b] = c;
			update(1, 1, N, (int)b, diff);
		}
		else {
			printf("%lld\n", find(1, 1, N, (int)b, (int)c));
		}
	}
}