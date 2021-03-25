//# Author : nuclear852 ========================#
//# Solution : 15252370 ========================#
//# Time Stamp : 2019-09-21 23:15:36 ===========#
//# Problem Title : 소수의 연속합 ================#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <vector>
using namespace std;
vector<int> prime;
bool arr[4000001];
int N;
int main(){
	scanf("%d", &N);
	for(int i=2; i<=2000; i++){
		if(arr[i]) continue;
		for(int j=2; i*j<=4000000; j++) arr[i*j] = 1;
	}
	arr[1] = 1;
	
	for(int i=1; i<=4000000; i++) if(!arr[i]) prime.push_back(i);
	
	int s = 0, e = 0;
	int ans = 0;
	int sum = prime[s];
	while(1){
		if(sum == N) ans++;
		if( sum > N) {
			sum -= prime[s];
			s++;
		}
		else {
			e++;
			if(e >= prime.size()) break;
			sum += prime[e];
		}
	}
	printf("%d", ans);
	
}