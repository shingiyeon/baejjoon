//# Author : nuclear852 ========================#
//# Solution : 11870337 ========================#
//# Time Stamp : 2019-02-21 01:27:16 ===========#
//# Problem Title : !밀비 급일 =================#
//# Language : C++98 ===========================#

#include <stdio.h>

bool strcmp(char a[]){
	char b[4] = "END";
	for(int i=0; i<4; i++){
		if(a[i] != b[i]) return 1;
	}
	return 0;
}

int main(){
	char str[501];
	gets(str);
	while(strcmp(str)){
		int strlen;
		for(strlen=0; str[strlen]!='\0'; strlen++);
		for(int i=strlen-1; i>=0; i--) printf("%c", str[i]);
		printf("\n");
		gets(str);
	}
}