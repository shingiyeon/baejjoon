#include <stdio.h>
int n;
int main(){
	char str[101]; scanf("%s", str);
	for(int i=0; str[i]!='\0'; i++){
		n++;
		if(!i) continue;
		else{
			if(str[i] == '='){
				if(str[i-2] == 'd' && str[i-1] == 'z'){
					n-=2; continue;
				}
				if(str[i-1] == 'z' || str[i-1] == 'c' || str[i-1] == 's')
				{	n--;continue; }
			}
			else if(str[i] == '-'){
				if(str[i-1] =='c' || str[i-1] == 'd')
				{ n--; continue;}
			}
			else if(str[i] == 'j'){
				if(str[i-1] == 'l' || str[i-1] == 'n')
				{n--;continue;	}
			}
		}
	}
	printf("%d",n);
}
