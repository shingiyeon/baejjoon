//# Author : nuclear852 ========================#
//# Solution : 11599465 ========================#
//# Time Stamp : 2019-01-30 22:43:23 ===========#
//# Problem Title : K번째 수 ==================#
//# Language : C++98 ===========================#

#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[5000000];
int main(){
	int N, K; scanf("%d%d", &N,&K);
	for(int i=0; i<N; i++) scanf("%d",&arr[i]);
	sort(arr,arr+N);
	printf("%d",arr[K-1]);
}