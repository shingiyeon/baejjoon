#include <stdio.h>
int main(){
	int a; int N = 0; int temp;
	scanf("%d",&a);
	temp = a;
	do{
		if(a<10) a += a*10;
		else a = ((a%10)*10) + ( ((a/10)+(a%10))%10);
		N++;
	}while(a!=temp);
	printf("%d",N);
}
