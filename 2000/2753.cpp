//# Author : nuclear852 ========================#
//# Solution : 15115793 ========================#
//# Time Stamp : 2019-09-13 23:47:21 ===========#
//# Problem Title : 윤년 =====================#
//# Language : C++14 ===========================#

#include <stdio.h>
int main(){
	int a;
	scanf("%d", &a);
	if(!(a%400)) printf("1");
	else if(!(a%100)) printf("0");
	else if(!(a%4)) printf("1");
	else printf("0");
}