#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
	int N; int arr[1000]; scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d", &arr[i]);
	sort(arr, arr+N);
	printf("%d", arr[N-1]-arr[0]);
}
