//# Author : nuclear852 ========================#
//# Solution : 15251846 ========================#
//# Time Stamp : 2019-09-21 22:51:05 ===========#
//# Problem Title : 수들의 합 2 ================#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[10000];
int main(){
	
	int N, M; scanf("%d%d", &N, &M);
	for(int i=0; i<N; i++) scanf("%d", &arr[i]);
	
	int s = 0, e = 0;
	int sum = arr[s];
	int ans = 0;
	while(1){
		if(sum == M) {
			ans++;
		}
		
		if(sum > M) {
			sum -= arr[s];
			s++;
		}
		else {
			e++;
			if( e >= N) break;
			sum += arr[e];
		}
	}
	printf("%d", ans);
	
}