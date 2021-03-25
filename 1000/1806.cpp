//# Author : nuclear852 ========================#
//# Solution : 15252656 ========================#
//# Time Stamp : 2019-09-21 23:28:08 ===========#
//# Problem Title : 부분합 ====================#
//# Language : C++14 ===========================#

#include <stdio.h>

using namespace std;
int arr[100000];
int N, S;
int main() {
	scanf("%d%d", &N,&S);
	for(int i=0; i<N; i++) scanf("%d", &arr[i]);
	int s = 0 , e = 0; int sum = arr[0];
	int ans = 100001;
	while(1){
		if(sum >= S)
			ans = (e-s+1 < ans) ? e-s+1 : ans;
		
		if(sum < S){
			e++;
			if(e >= N) break;
			sum += arr[e];
		}
		
		else {
			sum -= arr[s];
			s++;
			if(s > e) break;
		}
	}
	printf("%d", ans != 100001? ans : 0);
}