//# Author : nuclear852 ========================#
//# Solution : 22226209 ========================#
//# Time Stamp : 2020-09-01 22:48:49 ===========#
//# Problem Title : 버블 소트 ==================#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <algorithm>
#include <map>
typedef long long ll;
using namespace std;

int arr[500001];
int tree[2500001];
int N;

map<int ,int> m;

ll find(int index, int start, int end, int left, int right) {
	if(left <= start && end <= right) {
		return (ll)tree[index];
	}
	if(left > end || right < start){
		return 0;
	}
	int mid = (start + end) / 2;
	return find(index * 2, start, mid, left, right) + find(index * 2 + 1, mid+1, end, left, right);
}

void update(int index, int start, int end, int cur) {
	if(start <= cur && cur <= end) {
		tree[index] += (ll)1;
	}
	else {
		return;
	}
	if(start == end) return;
	int mid = (start + end) / 2;
	update(index * 2, start, mid, cur);
	update(index * 2 + 1, mid+1, end, cur);
}


int main() {
	scanf("%d", &N);
	for(int i=1; i<=N; i++) {
		scanf("%d", &arr[i]);
		tree[i] = arr[i];
	}
	sort(tree+1, tree+N+1);
	for(int i=1; i<=N; i++) {
		m[tree[i]] = i;
	}
	for(int i=1; i<=N; i++) {
		arr[i] = m[arr[i]];
		tree[i] = 0;
	}
	ll ans = 0;
	for(int i=1; i<=N; i++) {
		ans += find(1, 1, N, arr[i]+1, N);
		update(1, 1, N, arr[i]);
	}
	printf("%lld", ans);
}