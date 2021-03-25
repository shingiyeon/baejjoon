//# Author : nuclear852 ========================#
//# Solution : 22238535 ========================#
//# Time Stamp : 2020-09-02 14:19:24 ===========#
//# Problem Title : 달리기 ====================#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <map>
#include <algorithm>

using namespace std;

int N;
map<int, int> m;

int arr[500001];
int tree[2000001];

int find(int index, int start, int end, int left, int right) {
	if(left <= start && end <= right) {
		return tree[index];
	}
	else if(right < start || end < left) {
		return 0;
	}
	if(start == end) return 0;
	int mid = (start + end) / 2;
	return find(index * 2, start, mid, left, right) + find(index * 2 + 1, mid+1, end, left, right);
}

void update(int index, int start, int end, int cur) {
	if(start <= cur && cur <= end) {
		tree[index] += 1;
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
	for(int i=1; i<=N; i++) {
		update(1, 1, N, arr[i]);
		printf("%d\n", find(1, 1, N, arr[i], N));
	}
	
	
}