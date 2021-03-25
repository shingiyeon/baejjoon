//# Author : nuclear852 ========================#
//# Solution : 15017914 ========================#
//# Time Stamp : 2019-09-07 09:53:00 ===========#
//# Problem Title : 행렬 곱셈 순서 ===============#
//# Language : C++98 ===========================#

#include <stdio.h>

using namespace std;

int dy[500][500];
int arr[500][2];

int min(int a, int b){
	return a < b? a : b;
}

int main(){
	int N; scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d%d", &arr[i][0], &arr[i][1]);
	
	for(int i=0; i<500; i++){
		for(int j=0; j<500; j++){
			dy[i][j] = 0x7fffffff;
		}
		dy[i][i] = 0;
	}
	
	for(int i=0; i<N; i++){
		for(int j=0; j+i<N; j++){
			for(int k=j; k<j+i; k++){
				dy[j][j+i] = min(dy[j][j+i], dy[j][k] + dy[k+1][j+i] + arr[j][0] * arr[k][1] * arr[j+i][1]);
			}
		}
	}
	printf("%d", dy[0][N-1]);
	
}