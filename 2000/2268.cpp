//# Author : nuclear852 ========================#
//# Solution : 22309897 ========================#
//# Time Stamp : 2020-09-04 23:06:57 ===========#
//# Problem Title : 수들의 합 ==================#
//# Language : C++14 ===========================#

#include <stdio.h>
typedef long long ll;
using namespace std;

int N, M;

int arr[1000001];
ll tree[4000001];

void update(int index, int start, int end, int cur, int diff) {
	if(start <= cur && cur <= end) {
		tree[index] += (ll) diff;
	}
	else {
		return;
	}
	if(start == end) return;
	int mid = (start + end) / 2;
	update(index*2, start, mid, cur, diff);
	update(index*2 + 1, mid+1, end, cur, diff);
}

ll sum(int index, int start, int end, int left, int right) {
	if(left <= start && end <= right) {
		return tree[index];
	}
	else if(right < start || end < left) {
		return 0;
	}
	if(start == end) return 0;
	int mid = (start + end) / 2;
	return sum(index*2,start,mid,left,right) + sum(index*2+1,mid+1,end,left,right);
}

int main(){
	scanf("%d%d", &N, &M);
	int a, b, c;
	for(int i=1; i<=M; i++) {
		scanf("%d%d%d",&a,&b,&c);
		if(a) {
			update(1, 1, N, b, c - arr[b]);
			arr[b] = c;
		}
		else {
			if(c>b) printf("%lld\n", sum(1, 1, N, b, c));
			else printf("%lld\n", sum(1, 1, N, c, b));
		}
	}
}