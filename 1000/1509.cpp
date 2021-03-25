//# Author : nuclear852 ========================#
//# Solution : 15039727 ========================#
//# Time Stamp : 2019-09-08 20:16:18 ===========#
//# Problem Title : 팰린드롬 분할 ================#
//# Language : C++98 ===========================#

#include <stdio.h>
using namespace std;

char str[2505];
int dp[2505];

int min(int a, int b){
	return a < b? a : b;
}

int main(){
	int i;
	dp[0] = 1;
	for(i=1; i<2505; i++) dp[i] = 99999999;
	scanf("%s", str);
	for(i=0; str[i]!='\0'; i++){
		for(int j=0; j<i; j++){
			bool pos = 1;
			for(int k=j,l=i; k<=l;){
				if(str[k]!=str[l]){
					pos = 0;
					break;
				}
				k++; l--;
			}
			if(pos){
				if(dp[i]==-1) {
					if(!j) dp[i] = 1;
					else dp[i] = 1 + dp[j-1];
				}
				else{
					if(!j) dp[i] = 1;
					else dp[i] = min(dp[i], 1 + dp[j-1]);
				}
			}
			else{
				dp[i] = min(dp[i], dp[i-1] + 1);
			}
		}
	}
	printf("%d", dp[i-1]);
}