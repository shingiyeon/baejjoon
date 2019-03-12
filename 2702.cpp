#include <stdio.h>

int main(){
	int T; scanf("%d", &T);
	while(T--){
		int a, b; scanf("%d%d", &a,&b);
		int ta = a, tb = b;
		if(tb>ta){
			int temp = tb;
			tb = ta;
			ta = temp;
		}
		while(ta%tb){
			int mod = ta%tb;
			ta = tb;
			tb = mod;
		}
		
		printf("%d %d\n", a*b/tb, tb);
	}
}
