#include <stdio.h>
int main(){
	char str[16]; scanf("%s", str);
	int sum = 0;
	for(int i=0; str[i]!='\0'; i++){
		sum += 2;
		switch(str[i]){
			case 'W': case 'Y': case 'X': case 'Z':
				sum += 1;
			case 'T':case 'U':case 'V':
				sum += 1;
			case 'P':case 'Q':case 'R':case 'S':
				sum += 1;
			case 'M':case 'N':case 'O':
				sum += 1;
			case 'J':case 'K':case 'L':
				sum += 1;
			case 'G':case 'H':case 'I':
				sum += 1;
			case 'D':case 'E':case 'F':
				sum += 1;
			case 'A':case 'B':case 'C':
				sum += 1;
		}
	}
	printf("%d",sum);
}
