#include <stdio.h>
int main(){
	int n; scanf("%d",&n);
	if(!n) {printf("0"); return 0;}
	if(n==1) {printf("1"); return 0;}
	long long a, b, c;
	a = 0; b = 1;
	for(int i=2; i<=n; i++){
		c = b + a;
		a = b; b = c; 
	}
	printf("%lld", c);
}
