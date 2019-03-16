#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
	int arr[10]; int i=0;
	

	
	while(scanf("%1d", &arr[i])!=EOF){i++;}
	sort(arr, arr+i);
	for(int j=i-1; j>=0; j--) printf("%d", arr[j]);
}
