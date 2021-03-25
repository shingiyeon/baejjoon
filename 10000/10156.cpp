//# Author : nuclear852 ========================#
//# Solution : 12614887 ========================#
//# Time Stamp : 2019-04-06 10:59:24 ===========#
//# Problem Title : 과자 =====================#
//# Language : C++98 ===========================#

#include <stdio.h>
int main(){
	int K, N, M; scanf("%d%d%d",&K,&N,&M);
	printf("%d", K*N>=M? K*N-M : 0);
}