#include <stdio.h>
int main(){
	int T; scanf("%d",&T);
	while(T--){
		long long a, b; scanf("%lld%lld",&a,&b);
		if(b>a){long long temp = b; b = a; a = temp;}
		long long ta = a, tb = b;
		while(ta%tb){ long long temp = ta % tb; ta = tb; tb = temp;}
		printf("%lld\n",a/tb*b);
	}
}
