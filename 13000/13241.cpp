//# Author : nuclear852 ========================#
//# Solution : 11584787 ========================#
//# Time Stamp : 2019-01-30 00:58:24 ===========#
//# Problem Title : 최소공배수 ==================#
//# Language : C++98 ===========================#

#include <stdio.h>
int main(){
	long long a, b; scanf("%lld%lld",&a,&b);
	if(b>a){long long temp = b; b = a; a = temp;}
	long long ta = a, tb = b;
	while(ta%tb){ long long temp = ta % tb; ta = tb; tb = temp;}
	printf("%lld\n",a/tb*b);
	
}