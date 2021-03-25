//# Author : nuclear852 ========================#
//# Solution : 12473904 ========================#
//# Time Stamp : 2019-03-30 15:02:32 ===========#
//# Problem Title : 소수 구하기 =================#
//# Language : C++98 ===========================#

#include <stdio.h>

int arr[1000001];
int main(){
	int n, m; scanf("%d%d",&n,&m);
	for(int i=2; i<=1000; i++){
		if(arr[i] == 1) continue;
		for(int j=2; i*j<=1000000; j++){
			arr[i*j] = 1;
		}
	}
	arr[1] = 1;
	for(int i=n; i<=m; i++){
		if(arr[i]==0){
			printf("%d\n", i);
		}
	}
}