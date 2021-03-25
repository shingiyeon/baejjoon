//# Author : nuclear852 ========================#
//# Solution : 11630435 ========================#
//# Time Stamp : 2019-02-02 15:37:56 ===========#
//# Problem Title : 1, 2, 3 더하기 2 ==========#
//# Language : C++98 ===========================#

#include <stdio.h>
int d[11];
void f(int n, int k){
	if(n==1) { printf("1"); return;}
	if(n==2) {
		switch(k){
			case 1:
				printf("1+1");	break;
			case 2:
				printf("2"); break;
		}
		return;
	}
	if(n==3){
		switch(k){
			case 1: printf("1+1+1"); break;
			case 2: printf("1+2"); break;
			case 3: printf("2+1"); break;
			case 4: printf("3"); break;
		}
		return;
	}
	int K = 0;
	for(int i=1; i<=3; i++){
		if(k<=K+d[n-i]){
			printf("%d+",i);
			f(n-i,k-K);
			return;
		}
		K += d[n-i];
	}
}
int main(){
	int N, K; scanf("%d%d",&N,&K);
	d[1] = 1; d[2] = 2; d[3] = 4;
	for(int i=4; i<11; i++) d[i] = d[i-1] + d[i-2] + d[i-3];
	if(K>d[N]) {printf("-1"); return 0;}
	f(N,K);
}