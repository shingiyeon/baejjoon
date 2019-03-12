#include <stdio.h>
int main(){
	int num = 1;
	long long sum = 0;
	long long S; scanf("%lld", &S);
	for(long long i=1; i<S; i++){
		sum += i;
		if(S-sum<=i) break;
		num++;
	}
	printf("%d",num);
}
