#include <stdio.h>
int main()
{
	int a;
	int sum = 0;
	int num = 1;
	scanf("%d", &a);
	while(num<=a){
		sum = sum + num;
		num++;
	}
	printf("%d\n", sum);
}
