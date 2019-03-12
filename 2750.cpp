#include <stdio.h>
#include <algorithm>
using namespace std;
bool compare(int a, int b){
	return a > b? 1 : 0;
}
int main(){
	int N; scanf("%d",&N); int arr[1001];
	for(int i=0; i<N; i++) scanf("%d",&arr[i]);
	sort(arr, arr+N);
	for(int i=0; i<N; i++) printf("%d\n", arr[i]);
}
