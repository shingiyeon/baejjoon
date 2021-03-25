//# Author : nuclear852 ========================#
//# Solution : 11741413 ========================#
//# Time Stamp : 2019-02-12 01:27:02 ===========#
//# Problem Title : 별 찍기 - 23 ==============#
//# Language : C++98 ===========================#

#include <stdio.h>
int main(){
	int N; scanf("%d", &N);
	for(int i=1; i<=N; i++) printf("*");
	for(int i=1; i<=(N-1)*2-1; i++) printf(" ");
	for(int i=1; i<=N; i++) printf("*");
	printf("\n");
	
	for(int i=2; i<N; i++){
		for(int j=1; j<i; j++) printf(" ");
		printf("*");
		for(int j=1; j<=N-2; j++) printf(" ");
		printf("*");
		for(int j=1; j<=(N-i)*2-1; j++) printf(" ");
		printf("*");
		for(int j=1; j<=N-2; j++) printf(" ");
		printf("*\n");
	}
	
	for(int i=1; i<N; i++) printf(" ");
	printf("*");
	for(int j=1; j<=N-2; j++) printf(" ");
	printf("*");
	for(int i=1; i<=N-2; i++) printf(" ");
	printf("*\n");
	
	for(int i=2; i<N; i++){ 
		for(int j=1; j<=(N-i); j++) printf(" ");
		printf("*");
		for(int j=1; j<=N-2; j++) printf(" ");
		printf("*");
		for(int j=1; j<=2*(i-1)-1; j++) printf(" ");
		printf("*");
		for(int j=1; j<=N-2; j++) printf(" ");
		printf("*\n");
	}
	for(int i=1; i<=N; i++) printf("*");
	for(int i=1; i<=(N-1)*2-1; i++) printf(" ");
	for(int i=1; i<=N; i++) printf("*");
	printf("\n");	
	
}