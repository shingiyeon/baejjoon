//# Author : nuclear852 ========================#
//# Solution : 11527297 ========================#
//# Time Stamp : 2019-01-25 22:41:01 ===========#
//# Problem Title : 이항 계수 2 ================#
//# Language : C++98 ===========================#

#include <stdio.h>
long long dy[1001][1001];

long long d(int a, int b){
	if(a<0 || b<0) return 0;
	if(dy[a][b]!=-1) return dy[a][b];
	if(a==b) return dy[a][b] = 1;
	if(b==1) return dy[a][b] = a;
	return dy[a][b] = (d(a-1,b-1) + d(a-1,b)) % 10007;

}

int main(){
	int N, K; scanf("%d%d",&N,&K);
	for(int i=0; i<=N; i++){
		for(int j=0; j<=K; j++){
			dy[i][j] = -1;
		}
	}
	printf("%lld",d(N,K));
}