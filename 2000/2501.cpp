//# Author : nuclear852 ========================#
//# Solution : 12479381 ========================#
//# Time Stamp : 2019-03-30 19:52:59 ===========#
//# Problem Title : 약수 구하기 =================#
//# Language : C++98 ===========================#

#include <stdio.h>
int main(){
	int N, K;
	scanf("%d%d",&N,&K);
	int i;
	int idx=0;
	for(i=1; i<=N; i++){
		if(N%i==0){
			idx = idx + 1;	
		}
		if(idx == K){
			printf("%d", i);
			break;
		}
	}
	if(idx < K){
		printf("0");
	}
	
}