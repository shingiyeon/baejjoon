#include <stdio.h>
int main(){
	char arr[2][4];
	int a, b;
	scanf("%s%s",arr[0],arr[1]);
	a = (arr[0][2]-'0') * 100 + (arr[0][1]-'0') * 10 + arr[0][0]-'0';
	b = (arr[1][2]-'0') * 100 + (arr[1][1]-'0') * 10 + arr[1][0]-'0';
	printf("%d", a>b? a : b);
}
