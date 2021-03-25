//# Author : nuclear852 ========================#
//# Solution : 21967558 ========================#
//# Time Stamp : 2020-08-23 23:20:51 ===========#
//# Problem Title : 완전 이진 트리 ===============#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;
vector<int> v[11];
int arr[2048];
int K;

void dq(int start, int end, int lv) {
	if(start > end) return;
	
	int mid = (start + end) / 2;
	v[lv].push_back(arr[mid]);
	dq(start, mid-1, lv+1);
	dq(mid+1, end, lv+1);
}

int main() {
	scanf("%d", &K);
	for(int i=0; i<pow(2, K)-1; i++) scanf("%d", &arr[i]);
	dq(0, pow(2, K)-2, 1);
	for(int i=1; i<=K; i++) {
		for(auto adj: v[i]) {
			printf("%d ", adj);
		}
		printf("\n");
	}
}