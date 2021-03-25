//# Author : nuclear852 ========================#
//# Solution : 11381521 ========================#
//# Time Stamp : 2019-01-16 15:15:04 ===========#
//# Problem Title : 이동하기 ===================#
//# Language : C++98 ===========================#

#include <stdio.h>
int max(int a, int b){
	return a > b? a : b;	
}
int dy[1000][1000];
int main(){
	int di[3] = {-1, -1, 0};
	int dj[3] = {-1, 0, -1};
	int N, M;
	scanf("%d%d",&N,&M);
	short arr[1000][1000];
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			scanf("%d", &arr[i][j]);
		}
	}
	dy[0][0] = arr[0][0];
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			for(int k=0; k<3; k++){
				if(i+di[k] < 0 || j+dj[k]<0) continue;
				dy[i][j] = max(dy[i][j], dy[i+di[k]][j+dj[k]]+arr[i][j]);
			}
		}
	}
	printf("%d",dy[N-1][M-1]);	
}