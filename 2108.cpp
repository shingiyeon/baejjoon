#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[500000];
int a[8001];
int main(){
	int N; scanf("%d",&N);
	for(int i=0; i<N; i++) {scanf("%d", &arr[i]); a[arr[i]+4000]++;}
	sort(arr, arr+N);
	int sum = 0;
	for(int i=0; i<N; i++) sum += arr[i];
	int max=0; int maxvalue=0; bool pos = 0;
	for(int i=0; i<=8000; i++){
		if (a[i]!=0 && a[i]>max) {max= a[i]; maxvalue=i-4000;pos=1;}
		else if (a[i]!=0 && a[i]==max && pos) {maxvalue=i-4000;pos=0;} 
	}
	printf("%.f\n%d\n%d\n%ld",(float)sum/N,arr[N/2],maxvalue,(long)arr[N-1]-(long)arr[0]);
}
