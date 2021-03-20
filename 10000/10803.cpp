#include <stdio.h>

int d[10001][101];

int min(int a, int b){
	return a < b? a : b;
}

int dy(int n, int m){
	if(m>n){
		int temp = n;
		n = m;
		m = temp;
	}
	if(d[n][m]!=-1) return d[n][m];
	if(n<=0 || m<=0) return 0;
	if(n%m==0) return d[n][m] = n/m;
	int MIN = 999999999;
	for(int i=1; i<=m; i++){
		MIN = min(dy(n-i,m)+dy(i,m), MIN);
	}
	for(int i=1; i<=min(m/2,n); i++){
		MIN = min(dy(n,m-i)+dy(n,i), MIN);
	}
	return d[n][m] = MIN;
}

int main(){
	int n, m;
	for(int i=0; i<=10000; i++){
		for(int j=0; j<=100; j++){
			d[i][j] = -1;
		}
	}
	scanf("%d%d", &n,&m);
	
	printf("%d", dy(n,m));
}
