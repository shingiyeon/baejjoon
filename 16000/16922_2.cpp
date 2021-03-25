//# Author : nuclear852 ========================#
//# Solution : 11736986 ========================#
//# Time Stamp : 2019-02-11 20:02:13 ===========#
//# Problem Title : 로마 숫자 만들기 ==============#
//# Language : C++98 ===========================#

#include <stdio.h>

int R[4] = {1, 5, 10, 50};
int d[21][1001][4];

int main(){
	int N; scanf("%d", &N);
	int num = 0;
	d[1][1][0] = 1; d[1][5][1] = 1; d[1][10][2] = 1; d[1][50][3] = 1;
	for(int i=2; i<=20; i++){
		for(int j=1; j<=1000; j++){
			for(int k=0; k<=4; k++){
				if(j>=R[k]){
					int sum = 0;
					for(int l=0; l<=k; l++)
						sum |= d[i-1][j-R[k]][l];
					d[i][j][k] = sum;
				}	
			}
		}
	}

	
	int sum = 0;
	
	for(int i=1; i<=1000; i++){
		int num = 0;
		for(int k=0; k<4; k++){
			num |= d[N][i][k];
		}
		sum += num;
	}
	printf("%d", sum);	
}