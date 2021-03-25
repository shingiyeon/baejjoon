//# Author : nuclear852 ========================#
//# Solution : 14990458 ========================#
//# Time Stamp : 2019-09-05 20:32:14 ===========#
//# Problem Title : 가장 긴 감소하는 부분 수열 ========#
//# Language : C++98 ===========================#

#include <stdio.h>
 
int arr[1000];
int dy[1000];
int MAX = 0;
int max(int a, int b){
	return a > b? a:b;
}
 
int main(){
	int N; scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d", &arr[i]);
 
	for(int i=0; i<N; i++){
		for(int j=0; j<i; j++){
			if(arr[i] < arr[j]){
				dy[i] = max(dy[i], dy[j]+1);
				MAX = max(MAX, dy[i]);
			}
		}
	}
	printf("%d", MAX+1);
}