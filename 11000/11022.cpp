//# Author : nuclear852 ========================#
//# Solution : 15115808 ========================#
//# Time Stamp : 2019-09-13 23:48:46 ===========#
//# Problem Title : A+B - 8 ================#
//# Language : C++14 ===========================#

#include <stdio.h>
int main(){
	int T; scanf("%d", &T);
	for(int i=1; i<=T; i++){
		int a, b; scanf("%d%d",&a,&b);
		printf("Case #%d: %d + %d = %d\n",i, a, b, a+b);
	}
}