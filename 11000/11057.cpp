//# Author : nuclear852 ========================#
//# Solution : 11368703 ========================#
//# Time Stamp : 2019-01-15 18:12:17 ===========#
//# Problem Title : 오르막 수 ==================#
//# Language : C++98 ===========================#

#include <stdio.h>
int main(){
	int N;
	scanf("%d", &N);
	int dy[1001][10];
	for(int i=1; i<1001; i++){
		for(int j=0; j<10; j++){
			dy[i][j] = 0;
		}
	}
	for(int i=0;i<10;i++)
		dy[1][i] = 1;
	for(int i=2; i<=1000;i++){
		for(int j=0; j<10; j++){
			for(int k=0; k<=j; k++){
				dy[i][j] += dy[i-1][k] % 10007;
			}
		}
	}
	int sum = 0;
	for(int i=0; i<10; i++)
		sum += dy[N][i] % 10007;
	printf("%d", sum % 10007);
}