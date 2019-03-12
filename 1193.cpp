#include <stdio.h>
int main(){
	int N;scanf("%d",&N);int a=1;int num=2;int dir=1;
	for(;N>a;a++){N-=a;num+=1;dir*=-1;}
	printf("%d/%d", dir==-1? N:num-N, dir==-1? num-N: N);
}
