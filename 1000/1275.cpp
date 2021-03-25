//# Author : nuclear852 ========================#
//# Solution : 22144780 ========================#
//# Time Stamp : 2020-08-29 23:04:26 ===========#
//# Problem Title : 커피숍2 ===================#
//# Language : C++14 ===========================#

#include <stdio.h>
typedef long long ll;
using namespace std;

int N, Q;

ll arr[100001];
ll tree[300001];

ll init(int index, int start, int end) {
	if(start == end){
		return tree[index] = arr[start];
	}
	int mid = (start + end) / 2;
	return tree[index] = init(index * 2, start, mid) + init(index*2+1, mid+1, end);
}

ll find(int index, int start, int end, int left, int right) {
	if(left <= start && end <= right) {
		return tree[index];
	}
	else if(left > end || right < start) {
		return 0;
	}
	int mid = (start + end) / 2;
	return find(index * 2, start, mid, left, right) + find(index * 2 + 1, mid+1, end, left, right);
}

void update(int index, int start, int end, int cur, ll diff) {
	if(start <= cur && cur <= end) {
		tree[index] += diff;
	}
	else{
		return;
	}
    if(start == end) return;
	int mid = (start + end) / 2;
	update(index * 2, start, mid, cur, diff);
    update(index * 2 + 1, mid + 1, end, cur, diff);
}

int main() {
	scanf("%d%d", &N, &Q);
	for(int i=1; i<=N; i++) scanf("%lld", &arr[i]);
	init(1, 1, N);
	for(int i=1; i<=Q; i++) {
		int a, b, c; ll d;
		scanf("%d%d%d%lld",&a,&b,&c,&d);
        if (a > b) {
            int tmp;
            tmp = b;
            b = a;
            a = tmp;
        }
		printf("%lld\n", find(1, 1, N, a, b));
		update(1, 1, N, c, d - arr[c]);
		arr[c] = d;
	}
}