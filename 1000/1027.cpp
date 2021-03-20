#include <stdio.h>
int main(){
	int arr[50];
	int N; scanf("%d",&N);
	int ans = 0;
	for(int i=0; i<N; i++) scanf("%d",&arr[i]);
	for(int i=0; i<N; i++){
		int sum = 0;
		for(int j=0; j<i; j++){
			bool pos = 1;
			for(int k=j+1; k<i; k++){
				double a = (double)(arr[j]-arr[i]) * (i-k) / (i-j) + arr[i];
				if (a<=arr[k]) pos = 0;
			}
			sum+=pos;
		}
		
		for(int j=i+1; j<N; j++){
			bool pos = 1;
			for(int k=i+1; k<j; k++){
				double a = (double)(arr[j]-arr[i]) * (k-i) / (j-i) + arr[i];
				if (a<=arr[k]) pos = 0;
			}
			sum+=pos;
		}
		ans = sum > ans? sum : ans;
	}
	printf("%d",ans);
}
