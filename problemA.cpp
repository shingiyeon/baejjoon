#include <stdio.h>
int main(){
	int q; scanf("%d", &q);
	while(q--){
		long long a, b, c;
		scanf("%lld%lld%lld", &a, &b, &c);
		if(2*b>=c){
			printf("%lld\n", (a/2)*c + (a%2) * b);
		}
		else{
			printf("%lld\n", a * b);
		}
	}
}
