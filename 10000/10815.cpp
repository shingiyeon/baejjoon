//# Author : nuclear852 ========================#
//# Solution : 21568030 ========================#
//# Time Stamp : 2020-08-07 22:45:38 ===========#
//# Problem Title : 숫자 카드 ==================#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <vector>
using namespace std;

int A[500005];

void merge_sort(int left, int right){
	if (left >= right) {
		return;
	}
	vector<int> v;
	int mid = (left + right) / 2; 
	
	merge_sort(left, mid);
	merge_sort(mid+1, right);
	
	int l = left;
	int r = mid+1;
	while(l<=mid && r<=right) {
		if(A[l] > A[r]) {
			v.push_back(A[r++]);
		}
		else {
			v.push_back(A[l++]);
		}
	}
	while(l<=mid) {
		v.push_back(A[l++]);
	}
	while(r<=right){
		v.push_back(A[r++]);
	}
	
	int idx = 0;
	for(int i=left; i<=right; i++) {
		A[i] = v[idx++];
	}
}

bool binary_search(int left, int right, int value) {
	if(left > right) {
		return 0;
	}
	int mid = (left + right) / 2;
	
	if (A[mid] == value) return 1;
	if (A[mid] > value) {
		return binary_search(left, mid-1, value);
	}
	else {
		return binary_search(mid+1, right, value);
	}
	
}


int main() {
	int N, M;
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d", &A[i]);
	merge_sort(0, N-1);
	scanf("%d", &M);
	while(M--) {
		int tmp; scanf("%d", &tmp);
		if(binary_search(0, N-1, tmp)) {
			printf("1 ");
		}
		else{
			printf("0 ");
		}
	}
}