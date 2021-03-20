#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[1000001];
bool compare(int a, int b){
	return a > b? 1 : 0;
}
int main(){
	int N; scanf("%d",&N); 
	for(int i=0; i<N; i++) scanf("%d",&arr[i]);
	sort(arr, arr+N);
	for(int i=0; i<N; i++) printf("%d\n", arr[i]);
}
