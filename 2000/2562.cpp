//# Author : nuclear852 ========================#
//# Solution : 15115851 ========================#
//# Time Stamp : 2019-09-13 23:52:27 ===========#
//# Problem Title : 최댓값 ====================#
//# Language : C++14 ===========================#

#include <stdio.h>
int max = 0;
int num = 0;
int main(){
	for(int i=1; i<=9; i++){
		int temp; scanf("%d", &temp);
		if(temp > max){
			max = temp;
			num = i;
		}
	}
	printf("%d\n%d",max,num);
}