//# Author : nuclear852 ========================#
//# Solution : 12615574 ========================#
//# Time Stamp : 2019-04-06 12:08:54 ===========#
//# Problem Title : 개미 =====================#
//# Language : C++98 ===========================#

#include <stdio.h>
int main(){
	int w, h, p, q, t; scanf("%d%d%d%d%d", &w, &h, &p, &q, &t);
	printf("%d %d\n", ((t+p)/w)%2? w-((t+p)%w):(t+p)%w , ((t+q)/h)%2? h-((t+q)%h):(t+q)%h);
}