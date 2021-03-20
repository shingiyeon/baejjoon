#include <stdio.h>
int r[1500];
int c[15001];
int N, M;
int MAX = 0;
int max(int a, int b){return a>b?a:b;}
int main(){
	char t[1501];
	scanf("%d%d", &N,&M);
	for(int i=0; i<N; i++){
		int minh = 1000000000;
		int maxh = 0;
		scanf("%s", t);
		for(int j=0; j<M; j++){
			if(t[j]=='0'){
				for(int k=r[j]; k>0; k--){
					c[k] -= k;
				}
				r[j] = 0;
				continue;
			}
			r[j]++;
			c[r[j]] += r[j];
			if(minh>r[j]) minh=r[j];
			if(maxh<r[j]) maxh=r[j];	
		}
		for(int j=minh; j<=maxh; j++)
			MAX = max(MAX, c[j]);
	}
	printf("%d", MAX);
}
