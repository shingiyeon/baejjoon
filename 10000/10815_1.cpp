//# Author : nuclear852 ========================#
//# Solution : 21567472 ========================#
//# Time Stamp : 2020-08-07 22:23:42 ===========#
//# Problem Title : 숫자 카드 ==================#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <algorithm>
using namespace std;

int A[500005];
int main() {
	int N, M;
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d", &A[i]);
	sort(A, A+N);
	
	scanf("%d", &M);
	while(M--) {
		int tmp; scanf("%d", &tmp);
		if(binary_search(A, A+N, tmp)) {
			printf("1 ");
		}
		else{
			printf("0 ");
		}
	}
}