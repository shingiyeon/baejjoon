//# Author : nuclear852 ========================#
//# Solution : 11408594 ========================#
//# Time Stamp : 2019-01-18 00:06:31 ===========#
//# Problem Title : 그대로 출력하기 2 =============#
//# Language : C++98 ===========================#

#include <stdio.h>
int main(){
	char a[101];
	while(fgets(a, 101, stdin) != NULL){
		printf("%s",a);
	}
}