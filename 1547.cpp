#include <stdio.h>
int main(){
	int ans = 1; int T; scanf("%d",&T);
	while(T--){
		int a, b; scanf("%d%d",&a,&b);
		if(a==ans) ans = b;
		if(b==ans) ans = a;
	}
	printf("%d", ans);
}
