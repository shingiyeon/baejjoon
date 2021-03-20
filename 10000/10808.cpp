#include <stdio.h>
int arr[26];
int main(){
	char str[101]; scanf("%s", str);
	for(int i=0; str[i]!='\0'; i++)
		arr[str[i]-'a']++;
	for(int i=0; i<26; i++)
		printf("%d ", arr[i]);
}
