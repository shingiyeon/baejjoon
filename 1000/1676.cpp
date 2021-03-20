#include <stdio.h>

int two[501];
int five[501];
int t,f;

int main(){
	for(int i=0; i<=500; i++){
		int num = i;
		while(!(num%5) && num>0){
			num /= 5;
			five[i]++;
		}
		while( !(num%2) && num>0){
			num /= 2;
			two[i]++;
		}
	}
	int N; scanf("%d",&N);
	for(int i=0; i<=N; i++){
		t += two[i]; f+=five[i];
	}
	printf("%d", t>f? f:t);
}
