//# Author : nuclear852 ========================#
//# Solution : 12939382 ========================#
//# Time Stamp : 2019-04-27 14:41:45 ===========#
//# Problem Title : 카드게임 ===================#
//# Language : C++98 ===========================#

#include <stdio.h>

int main(){
	int A[10], B[10];
	int a = 0, b = 0;
	for(int i=0; i<10; i++) scanf("%d", &A[i]);
	for(int i=0; i<10; i++) scanf("%d", &B[i]);
	for(int i=0; i<10; i++){
		if(A[i] >= B[i]) a++;
		if(B[i] >= A[i]) b++;
	}
	if(a==b) printf("D");
	if(a>b) printf("A");
	if(a<b) printf("B");
}