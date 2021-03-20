#include <stdio.h>
int main(){
	long long a, b; scanf("%lld%lld",&a,&b);
	if(b>a){long long temp = b; b = a; a = temp;}
	long long ta = a, tb = b;
	while(ta%tb){ long long temp = ta % tb; ta = tb; tb = temp;}
	printf("%lld\n%lld\n",tb,a/tb*b);
	
}
