//# Author : nuclear852 ========================#
//# Solution : 15023412 ========================#
//# Time Stamp : 2019-09-07 17:08:46 ===========#
//# Problem Title : 자두나무 ===================#
//# Language : C++98 ===========================#

#include <stdio.h>
using namespace std;

int arr[1000];
int dy[1000][31];
int MAX;
int max(int a, int b){
	return a > b? a : b;
}

int main(){
	int T, W;
	scanf("%d%d",&T, &W);
	for(int i=0; i<T; i++) scanf("%d", &arr[i]);
	
	for(int i=0; i<=W; i++){
		dy[0][i] = (arr[0] == (i%2)+1);
	}
	
	for(int i=1; i<T; i++){
		for(int j=0; j<=W; j++){
			if(j==0) dy[i][j] = dy[i-1][j] + (arr[i]==(j%2)+1);
			else{
				dy[i][j] = max(dy[i-1][j], dy[i-1][j-1]) + (arr[i]==(j%2)+1);
			}
		}
	}
	for(int j=0; j<=W; j++)
		MAX = max(MAX, dy[T-1][j]);
	printf("%d", MAX);
}