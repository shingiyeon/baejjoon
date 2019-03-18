#include <stdio.h>
int main(){
	int T; scanf("%d", &T);
	while(T--){
		long long a=1, b=2, c=4, d;
		int n; scanf("%d",&n);
		if(n==1) {printf("1\n"); continue;}
		if(n==2) {printf("2\n"); continue;}
		if(n==3) {printf("4\n"); continue;}
		for(int i=4; i<=n; i++){
			d = (a+b+c) % 1000000009;
			a=b;
			b=c;
			c=d;
		}
		printf("%lld\n",d);
	}
}
