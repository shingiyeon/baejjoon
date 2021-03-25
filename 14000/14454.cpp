//# Author : nuclear852 ========================#
//# Solution : 11769554 ========================#
//# Time Stamp : 2019-02-13 20:09:29 ===========#
//# Problem Title : Secret Cow Code ========#
//# Language : C++98 ===========================#

#include <stdio.h>
typedef long long ll;
int main(){
	char s[31]; int strlen; ll N;
	scanf("%s", s); scanf("%lld", &N);
	for(strlen=0; s[strlen]!='\0'; strlen++);
	ll range = (ll)strlen;
	while(range<N)range*=2;
	while(N>(ll)strlen){
		N = (N==range/2+1)? N-1 : (N>range/2)? N-range/2-1 : N;
		range /= 2;
	}
	printf("%c", s[N-1]);
}