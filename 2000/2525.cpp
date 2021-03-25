//# Author : nuclear852 ========================#
//# Solution : 12479226 ========================#
//# Time Stamp : 2019-03-30 19:44:09 ===========#
//# Problem Title : 오븐 시계 ==================#
//# Language : C++98 ===========================#

#include <stdio.h>
int main(){
	int h, m;
	scanf("%d%d",&h,&m);
	int addm; scanf("%d",&addm);
	printf("%d %d", 
(h + (m + addm)/60) % 24, (m + addm) % 60);
	
}