//# Author : nuclear852 ========================#
//# Solution : 22057787 ========================#
//# Time Stamp : 2020-08-26 22:36:50 ===========#
//# Problem Title : 최솟값 ====================#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

int arr[100001];
int p[300001];

int init(int index, int s, int e) {
	if(s == e) {
		return p[index] = arr[s];
	}
	int mid = (s + e) / 2;
	
	int left = init(index * 2, s, mid);
	int right = init(index * 2 + 1, mid + 1, e);
	return p[index] = min(left, right);
}

int find(int index, int s, int e, int left, int right) {
	if(left <= s && e <= right) {
		return p[index];
	}
	if(s > right || e < left) {
		return 1000000001;
	}
	
	int mid = (s + e) / 2;
	int left_value = find(index * 2, s, mid, left, right);
	int right_value = find(index * 2 + 1, mid + 1, e, left, right);
	return min(left_value, right_value);
}

int main() {
	scanf("%d%d",&N,&M);
	for(int i=1; i<=N; i++) scanf("%d", &arr[i]);
	init(1, 1, N);
	while(M--) {
		int a, b; scanf("%d%d", &a, &b);
		int ans = find(1, 1, N, a, b);
		printf("%d\n", ans);
	}
}