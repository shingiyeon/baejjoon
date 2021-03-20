#include <stdio.h>
int arr[26];
char a[1000001];
int main(){
	scanf("%s",a);
	for(int i=0; a[i]!='\0'; i++){
		if(a[i]-'a'>=0 && a[i]-'a'<=25) arr[a[i]-'a'] += 1;
		if(a[i]-'A'>=0 && a[i]-'A'<=25) arr[a[i]-'A'] += 1;
	}
	int max = -1; int alp = -1;
	for(int i=0; i<26; i++){
		if(arr[i]>max){
			max = arr[i];
			alp = i;
		}
		else if(arr[i]==max){
			alp = -1;
		}
	}
	printf("%c", alp!=-1? alp+'A' : '?');
}
