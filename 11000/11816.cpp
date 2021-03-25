//# Author : nuclear852 ========================#
//# Solution : 11785606 ========================#
//# Time Stamp : 2019-02-14 21:01:20 ===========#
//# Problem Title : 8진수, 10진수, 16진수 ========#
//# Language : C++98 ===========================#

#include <stdio.h>
int main(){
	char s[10]; scanf("%s", s); int sum = 0; int strlen = 0;
	for(;s[strlen]!='\0';strlen++);
	if(s[0] == '0' && s[1] != 'x'){
		int digit = 1;
		for(int i=strlen-1; i>0; i--){
			sum += digit * (s[i]-'0');
			digit *= 8;
		}
		printf("%d", sum);
		return 0;
	}
	if(s[1] == 'x'){
		int digit = 1;
		for(int i=strlen-1; i>1; i--){
			if(s[i]>='a'&&s[i]<='f')
				sum += digit * (s[i]-'a'+10);
			else
				sum += digit * (s[i]-'0');
			digit *= 16;
		}
		printf("%d", sum);
		return 0;
	}
	printf("%s", s);
}