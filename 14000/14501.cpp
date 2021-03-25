//# Author : nuclear852 ========================#
//# Solution : 11380798 ========================#
//# Time Stamp : 2019-01-16 14:42:25 ===========#
//# Problem Title : 퇴사 =====================#
//# Language : C++98 ===========================#

#include <stdio.h>
int max(int a, int b){
	return a >= b? a : b;
}

int main(){
	int N;
	scanf("%d", &N);
	int day[16];
	int arr[16];
	int dy[16];
	
	for(int i=1; i<=N; i++){
		scanf("%d%d",&day[i], &arr[i]);
		dy[i] = arr[i];
	}
	
	dy[0] = 0;
	day[0] = 0;
	arr[0] = 0;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=i; j++){
			if( i >= j+day[j] )
				dy[i] = max(dy[i], dy[j]+arr[i]);
		}
	}
	int ans = 0;
	for(int i=1; i<=N; i++){
		if(i + day[i] - 1 <= N)
			ans = max(ans, dy[i]);
	}
	printf("%d",ans);
}