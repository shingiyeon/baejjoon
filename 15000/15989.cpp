//# Author : nuclear852 ========================#
//# Solution : 11630894 ========================#
//# Time Stamp : 2019-02-02 16:14:47 ===========#
//# Problem Title : 1, 2, 3 더하기 4 ==========#
//# Language : C++98 ===========================#

#include <stdio.h>

int d[10001][4];

int main(){
	d[1][1] = 1; d[2][1] = 1; d[2][2] = 1;
	d[3][1] = 1; d[3][2] = 1; d[3][3] = 1;
	for(int i=4; i<=10000; i++){
		d[i][1] = 1;
		d[i][2] = d[i-2][2] + d[i-2][1];
		d[i][3] = d[i-3][3] + d[i-3][2] + d[i-3][1];
	}
	int T; scanf("%d",&T);
	while(T--){
		int temp; scanf("%d", &temp);
		printf("%d\n", d[temp][1]+d[temp][2]+d[temp][3]);
	}
}