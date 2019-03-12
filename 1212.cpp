#include <stdio.h>
int main(){
	int a; scanf("%1d",&a);
	if(a==0) {printf("0"); return 0;}
	int k = 4;
	bool pos = 0;
	while(k>0){
		if(a>=k) {a-=k; printf("1"); pos=1;}
		else if(a<k && pos==1) {printf("0");}
		k /= 2;
	}
	
	while(scanf("%1d", &a) != EOF){
		k = 4;
		while(k>0){
			if(a>=k) { a-=k; printf("1");	}
			else printf("0");
			k/=2;
		}
	}
	return 0;
}
