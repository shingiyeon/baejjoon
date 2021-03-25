//# Author : nuclear852 ========================#
//# Solution : 22057339 ========================#
//# Time Stamp : 2020-08-26 22:25:31 ===========#
//# Problem Title : 최솟값과 최댓값 ===============#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

int arr[100001];
pair<int, int> p[300001];

pair<int, int> init(int index, int s, int e) {
	if(s == e) {
		return p[index] = {arr[s], arr[s]};
	}
	int mid = (s + e) / 2;
	
	pair<int, int> left = init(index * 2, s, mid);
	pair<int, int> right = init(index * 2 + 1, mid + 1, e);
	return p[index] = make_pair(min(left.first, right.first), max(left.second, right.second));
}

pair<int, int> find(int index, int s, int e, int left, int right) {
	if(left <= s && e <= right) {
		return p[index];
	}
	if(s > right || e < left) {
		return {1000000001, 0};
	}
	
	int mid = (s + e) / 2;
	pair<int, int> left_value = find(index * 2, s, mid, left, right);
	pair<int, int> right_value = find(index * 2 + 1, mid + 1, e, left, right);
	return make_pair(min(left_value.first, right_value.first), max(left_value.second, right_value.second));
}

int main() {
	scanf("%d%d",&N,&M);
	for(int i=1; i<=N; i++) scanf("%d", &arr[i]);
	init(1, 1, N);
	while(M--) {
		int a, b; scanf("%d%d", &a, &b);
		pair<int ,int> ans = find(1, 1, N, a, b);
		printf("%d %d\n", ans.first, ans.second);
	}
}