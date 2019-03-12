#include <stdio.h>
#include <algorithm>
using namespace std;
bool cmp(int a, int b){
	return a > b;
}
int max1(int a){
	return a > 0? a : 0;
}
int main(){
	int n, m; scanf("%d%d",&n,&m);
	int arr[101];
	for(int i=0; i<n; i++) scanf("%d", &arr[i]);
	sort(arr, arr+n, cmp);
	
	for(int i=1; i<=n; i++){
		int sum = 0;
		for(int j=0; j<n; j++){
			sum +=  max1(arr[j]-(j/i));
		}
		if(sum>=m){
			printf("%d", i);
			return 0;
		}
	}
	printf("-1");
}
