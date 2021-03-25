//# Author : nuclear852 ========================#
//# Solution : 15115535 ========================#
//# Time Stamp : 2019-09-13 23:24:55 ===========#
//# Problem Title : 곱셈 =====================#
//# Language : C++14 ===========================#

#include <stdio.h>

int main(){
	int a, b; scanf("%d%d",&a,&b);
	int c = a * b;
	while(b){
		printf("%d\n", a * (b%10));
		b /= 10;
	}
	printf("%d", c);
}