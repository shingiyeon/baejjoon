//# Author : nuclear852 ========================#
//# Solution : 15115829 ========================#
//# Time Stamp : 2019-09-13 23:50:35 ===========#
//# Problem Title : 최소, 최대 =================#
//# Language : C++14 ===========================#

#include <stdio.h>
int min = 1000000;
int max = -1000000;

int main(){
	int N; scanf("%d", &N);
	while(N--){
		int temp; scanf("%d" , &temp);
		min = (min > temp ? temp : min);
		max = (max < temp ? temp : max);
	}
	printf("%d %d",min, max);
}