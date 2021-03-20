#include <time.h>
#include <stdio.h>
int main(){
	time_t t = time(0);
	char* dt = ctime(&t);
	printf("%s", dt);
	
	
}
