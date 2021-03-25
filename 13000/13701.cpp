//# Author : nuclear852 ========================#
//# Solution : 11628472 ========================#
//# Time Stamp : 2019-02-02 10:30:10 ===========#
//# Problem Title : 중복 제거 ==================#
//# Language : C++98 ===========================#

#include <stdio.h>
int a[1048576];
int main(){
	int temp;
	while(scanf("%d", &temp) != EOF){
		int x = temp/32;
		int y = 1 << (temp%32);
		if( (a[x] & y) == 0)
			printf("%d ", temp);
		a[x] = a[x] | y;
	}
}