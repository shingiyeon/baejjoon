//# Author : nuclear852 ========================#
//# Solution : 15190130 ========================#
//# Time Stamp : 2019-09-18 20:36:25 ===========#
//# Problem Title : 손익분기점 ==================#
//# Language : C++14 ===========================#

#include <stdio.h>
using namespace std;
int main(){
	int A, B, C;
	scanf("%d%d%d",&A,&B,&C);
	if(C-B>0)
		printf("%d",A/(C-B)+1);
	else
		printf("-1");
	
}