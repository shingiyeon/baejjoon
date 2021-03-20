#include <stdio.h>
bool visited[10001];
int main(){
	for(int i=1; i<=10000; i++){
		int sum = i;
		sum += (i/10000) + (i%10000/1000) + (i%1000/100) + (i%100/10) + (i%10);
		if(sum>=1 && sum<=10000) visited[sum] = 1;
	}
	for(int i=1; i<=10000; i++)
		if (!visited[i]) printf("%d\n",i);
}
