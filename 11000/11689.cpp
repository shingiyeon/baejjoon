//# Author : nuclear852 ========================#
//# Solution : 11691112 ========================#
//# Time Stamp : 2019-02-08 10:43:13 ===========#
//# Problem Title : GCD(n, k) = 1 ==========#
//# Language : C++98 ===========================#

#include <stdio.h>
using namespace std;

bool visited[1000001];

int main(){
	for(int i=2; i<=1000000; i++){
		if(visited[i]) continue;
		for(int j=2; i*j<=1000000; j++){
			visited[i*j] = 1;
		}
	}
	long long n; scanf("%lld", &n);
	if(n==1) {printf("1"); return 0;}
	long long num = n;
	
	for(long long i=2; i*i<=n; i++){
		if(n%i == 0){
			if(!visited[i]){
				num = num/i*(i-1);
			}
			long long b = n/i;
			if(i==b)	continue;
			bool pos = (b==1)? 0 : 1;
			for(int j=2; j<b && j<=1000000; j++){
				if(visited[j]) continue;
				if(b%j == 0) {pos = 0; break;}
			}
			if(pos) num = num/b*(b-1);
		}
	}
	printf("%lld", (num==n)? n-1: num);
}