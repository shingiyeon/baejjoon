//# Author : nuclear852 ========================#
//# Solution : 21570173 ========================#
//# Time Stamp : 2020-08-08 00:22:25 ===========#
//# Problem Title : 보석 상자 ==================#
//# Language : C++14 ===========================#

#include <stdio.h>
using namespace std;
int N, M;
int arr[300003];
int bs(int left, int right) {
	int mid = (left + right) / 2;
	if(left > right) return right+1;
	
	int c = 0;
	for(int i=0; i<M; i++) {
		c += (arr[i] -1) / mid +1 ;
	}
	if (c > N) {
		return bs(mid+1, right);
	}
	else {
		return bs(left, mid-1);
	}
}

int main() {
	scanf("%d%d",&N,&M);
	int max_val = 0;
	for(int i=0; i<M; i++) {
		scanf("%d",&arr[i]);
		if (arr[i] >= max_val) max_val = arr[i];
	}
	int ans = bs(1, max_val);
	printf("%d", ans);
}