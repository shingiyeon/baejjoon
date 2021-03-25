//# Author : nuclear852 ========================#
//# Solution : 11688830 ========================#
//# Time Stamp : 2019-02-08 00:15:00 ===========#
//# Problem Title : 피보나치 수와 최대공약수 ==========#
//# Language : C++98 ===========================#

#include <stdio.h>
#include <vector>
#include <iostream>
#define mod 1000000007LL

using namespace std;

typedef vector< vector<long long> > matrix;

matrix operator * (const matrix &a, const matrix &b){
	matrix c;
	vector<long long> temp;
	temp.push_back( (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % mod );
	temp.push_back( (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % mod );
	c.push_back(temp);
	temp.clear();
	temp.push_back(  (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % mod);
	temp.push_back(  (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % mod);
	c.push_back(temp);
	temp.clear();
	return c;
} 

int main(){
	long long N, M; scanf("%lld%lld",&N,&M);
	if(M>N){
		long long temp = N;
		N = M;
		M = temp;
	}
	while(N%M){
		long long temp = N%M;
		N = M;
		M = temp;
	}
	if(M <= 1){
		printf("%lld", M);
	}
	else{
		matrix b, a;
		vector<long long> temp;
		temp.push_back(1);temp.push_back(0); b.push_back(temp); temp.clear();
		temp.push_back(0);temp.push_back(1); b.push_back(temp); temp.clear();
		temp.push_back(1);temp.push_back(1); a.push_back(temp); temp.clear();
		temp.push_back(1);temp.push_back(0); a.push_back(temp); temp.clear();
		
		while(M>0){
			if(M%2) b = b * a;
			a = a*a;
			M /= 2;
		}
		printf("%lld",b[0][1]);
	}
}