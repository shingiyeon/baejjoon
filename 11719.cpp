#include <stdio.h>
int main(){
	char a[101];
	while(fgets(a, 101, stdin) != NULL){
		printf("%s",a);
	}
}
