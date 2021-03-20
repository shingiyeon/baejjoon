#include <stdio.h>

char a[100005];

int main(){
	scanf("%s", a);
	int ans = 0;
	int sum = 0;
	for(int i=0; a[i]!='\0'; i++){
		if(a[i] == '(') sum++;
		else{
			if(a[i-1] == '('){
				sum--;
				ans += sum;
			}
			else{
				ans += 1;
				sum--;
			}
		}
	}
	printf("%d", ans);
}
