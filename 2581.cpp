#include <stdio.h>
bool notsosu[10001];
int main(){
	notsosu[1] = 1;
	for(int i=2; i<=100; i++){
		for(int j=2; i*j<=10000; j++)
			notsosu[i*j] = 1;
	}
	int M, N; scanf("%d%d",&M,&N);
	int sum = 0; int min = 0;
	for(int i=M; i<=N; i++){
		if(!min&&!notsosu[i])min=i;
		if(!notsosu[i]) sum+=i;
	}
	if(!min) printf("-1");
	else printf("%d\n%d",sum,min);
}
