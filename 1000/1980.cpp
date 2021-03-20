#include <stdio.h>

int main(){
	int n,m,t,T,tn,tm,temp,c; scanf("%d%d%d",&n,&m,&t);T=t;
	if(n<m){temp=m;m=n;n=temp;}
	tn=n;tm=m;
	while(tn%tm){
		temp = tn%tm;
		tn=tm; tm=temp;
	}
	c = n*m/tm;
	while(T){
		for(int i=0; n*i<c && n*i<=T; i++){
			if( ((T-(n*i))%m) ==0  ){
				printf("%d %d",i+(T-n*i)/m,t-T);
				return 0;
			} 
		}
		T--;
	}
	printf("0 %d", t);
}
