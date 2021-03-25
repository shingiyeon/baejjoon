//# Author : nuclear852 ========================#
//# Solution : 15115454 ========================#
//# Time Stamp : 2019-09-13 23:18:43 ===========#
//# Problem Title : 플로이드 ===================#
//# Language : C++14 ===========================#

#include <stdio.h>
#define MAX 100000000

int n, m;
int dy[101][101];

int min(int a, int b){
	return a < b? a : b;
}

int main(){
	for(int i=1; i<=100; i++){
		for(int j=1; j<=100; j++){
			dy[i][j] = MAX;
		}
	}
	int s, e, d;
	scanf("%d%d", &n, &m);
	
	while(m--){
		scanf("%d%d%d",&s,&e,&d);
		dy[s][e] = min(dy[s][e], d);
	}
	
	for(int i=1; i<=n; i++) dy[i][i] = 0;
	
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				dy[i][j] = min(dy[i][j], dy[i][k] + dy[k][j]);
			}
		}
	}
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(dy[i][j] != MAX)
				printf("%d ", dy[i][j]);
			else
				printf("0 ");
		}
		printf("\n");
	}
	
}