#include <stdio.h>

int d[200000][26];
char s[200005];
int main(){
	scanf("%s", s);
	for(int j=0; j<26; j++){
		char tmp = j + 'a';
		d[0][j] = (s[0]==tmp);
		for(int i=1; s[i]!='\0'; i++){
			d[i][j] = d[i-1][j] + (s[i]==tmp);
		}
	}
	int q; scanf("%d",&q);
	while(q--){
		char alp; int l, r;
		getchar();
		scanf("%c",&alp); scanf("%d%d",&l,&r);
		if(l==0){
			printf("%d\n", d[r][alp-'a']);
		}
		else{
			printf("%d\n", d[r][alp-'a']-d[l-1][alp-'a']);
		}
	}
}
