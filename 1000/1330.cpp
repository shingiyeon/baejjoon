//# Author : nuclear852 ========================#
//# Solution : 15115769 ========================#
//# Time Stamp : 2019-09-13 23:45:29 ===========#
//# Problem Title : 두 수 비교하기 ===============#
//# Language : C++14 ===========================#

#include <stdio.h>
int main(){
	int a, b; scanf("%d%d",&a,&b);
	if(a<b) printf("<");
	if(a==b) printf("==");
	if(a>b) printf(">");
}