#include <stdio.h>
int main(){
	int arr[26];
	for(int i=0;i<30;i++) arr[i] = -1;
	char str[101]; scanf("%s", str);
	for(int i=0;str[i]!='\0';i++) if(arr[str[i]-'a'] == -1) arr[str[i]-'a'] = i;
	for(int i=0;i<26;i++) printf("%d ",arr[i]);
}
