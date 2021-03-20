#include <stdio.h>
long long int dy[101][101];
long long int dy2[101][101];

void d(int a, int b){
	if(a<0 || b<0) return;
	if(a==b) {dy[a][b] = 1; return;}
	if(b==1) {dy[a][b] = a; return;}	
	dy[a][b]   = ((dy[a-1][b-1] + dy[a-1][b]) % 100000000000000000);
	dy2[a][b] = (dy[a-1][b-1] + dy[a-1][b]) / 100000000000000000 + dy2[a-1][b-1] +dy2[a-1][b];

}

int main(){
	int N, K; scanf("%d%d",&N,&K);
	for(int i=1; i<=100; i++){
		for(int j=1; j<=i; j++){
			d(i,j);
		}
	}
	if(dy2[N][K]!=0)
		printf("%lld%016lld",dy2[N][K],dy[N][K]);
	else
		printf("%lld",dy[N][K]);
}
