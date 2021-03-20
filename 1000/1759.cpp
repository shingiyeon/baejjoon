#include <stdio.h>
#include <algorithm>
using namespace std;

int L, C; char arr[15];
char a[15];
char m[] ={'a', 'e', 'i', 'o', 'u'};

void backtracking(int idx, int num, int ja, int mo){
	if(num==L && ja>=2 && mo>=1){
		for(int i=0; i<L; i++) printf("%c", a[i]);
		printf("\n");
		return;
	}
	if(idx>=C) return;
	for(int i=idx+1; i<C; i++){
		a[num] = arr[i];
		bool pos = 0;
		for(int j=0; j<5; j++)	if(m[j]==arr[i] || m[j]+'A'-'a'==arr[i]) pos = 1;
		backtracking(i, num+1, ja+!pos, mo+pos);
	}
	return;
}

int main(){
	scanf("%d%d",&L,&C);
	for(int i=0; i<C; i++) scanf(" %c", &arr[i]);
	sort(arr, arr+C);
	backtracking(-1, 0, 0, 0);
}
