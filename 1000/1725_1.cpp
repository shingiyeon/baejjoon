//# Author : nuclear852 ========================#
//# Solution : 23897035 ========================#
//# Time Stamp : 2020-11-17 10:22:34 ===========#
//# Problem Title : 히스토그램 ==================#
//# Language : C++17 ===========================#

#define MAX_NUM 1000000001
#define MAX_NODE 303030

#include <stdio.h>

struct NODE {
	long long h;
	int i;
} arr[MAX_NODE];

int arr_idx;

NODE* myalloc() {
	return &arr[arr_idx++];
}

NODE* Tree[MAX_NODE];
NODE* NU;

int N;

void init(int N) {
	for (int n = 1; n <= 303030; ++n) {
		Tree[n] = myalloc();
		Tree[n]->h = MAX_NUM;
		Tree[n]->i = n;
	}
	NU = myalloc();
	NU->h = -1;
}

void insert(int node, int s, int e, int t, int d) {
	if (s == e) {
		if (s == t) {
			Tree[node]->h = d;
			Tree[node]->i = t;
		}
		return;
	}

	int mid = (s + e) / 2;

	if (t <= mid) insert(node * 2, s, mid, t, d);
	else insert(node * 2 + 1, mid + 1, e, t, d);

	int l = node * 2;
	int r = node * 2 + 1;

	if (Tree[l]->h <= Tree[r]->h) Tree[node] = Tree[l];
	else Tree[node] = Tree[r];
}

long long result;

NODE* get_h(int node, int s, int e, int qs, int qe) {
	if (qe < s || e < qs) return NU;
	if (qs <= s && e <= qe) {
		return Tree[node];
	}

	int mid = (s + e) / 2;

	NODE* l; NODE* r;

	l = get_h(node * 2, s, mid, qs, qe);
	r = get_h(node * 2 + 1, mid + 1, e, qs, qe);

	if (l->h == -1) return r;
	if (r->h == -1) return l;

	if (l->h <= r->h) return l;
	else return r;
}

void get_result(int s, int e) {
	if (s > e) return;
	NODE* pop;
	pop = get_h(1, 1, N, s, e);
	if (result < pop->h * (e - s + 1)) result = pop->h * (e - s + 1);

	get_result(s, pop->i - 1);
	get_result(pop->i + 1, e);
}

int main(void) {
	// freopen("input.txt", "r", stdin);
	scanf("%d", &N);

	init(N);

	for (int n = 1; n <= N; ++n) {
		int num;
		scanf("%d", &num);
		insert(1, 1, N, n, num);
	}

	get_result(1, N);

	printf("%lld", result);
	return 0;
}