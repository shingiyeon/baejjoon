#include <stdio.h>
int num;
int main(){
	int N; scanf("%d", &N);
	int a=1;
	for(;N>a;a==1?a+=5:a+=6){
		N-=a; num++;
	}
	printf("%d", num+1);
}
