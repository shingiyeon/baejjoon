#include <stdio.h>
int main(){
	int sum = 0;
	int arr[26];
	char str[101];
	int N; scanf("%d",&N);
	while(N--){
		bool pos = 1;
		scanf("%s", str);
		for(int i=0; i<26; i++) arr[i] = -1;
		for(int i=0; str[i] != '\0'; i++){
			if(arr[str[i]-'a']!=-1 && arr[str[i]-'a']!=i-1) pos = 0;
			arr[str[i]-'a'] = i;
		}
		sum += pos;
	}
	printf("%d",sum);
}
