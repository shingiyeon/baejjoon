#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
	int sum = 0;
	int arr[9]; for(int i=0; i<9; i++) {scanf("%d", &arr[i]); sum+=arr[i];}
	int i, j; sort(arr, arr+9);
	bool pos = 0;
	for(i=0; i<9; i++){
		for(j=i+1; j<9; j++){
			if( (sum-arr[i]-arr[j])==100) { pos = 1; break;}
		}
		if(pos) break;
	}
	for(int k=0; k<9; k++){
		if(k==i||k==j) continue;
		printf("%d\n", arr[k]);
	}
}
