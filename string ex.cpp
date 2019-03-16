#include <stdio.h>
int main(){
	const char *a = "123";
	printf("%s", a);
	a = "3";
	printf("%s", a);
}
