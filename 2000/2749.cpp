#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
typedef vector< vector<long long> > matrix;
long long mod = 1000000;
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
	long long n; scanf("%lld",&n);
	if(n <= 1){
		printf("%lld", n);
	}
	else{
		matrix b, a;
		vector<long long> temp;
		temp.push_back(1);temp.push_back(0); b.push_back(temp); temp.clear();
		temp.push_back(0);temp.push_back(1); b.push_back(temp); temp.clear();
		temp.push_back(1);temp.push_back(1); a.push_back(temp); temp.clear();
		temp.push_back(1);temp.push_back(0); a.push_back(temp); temp.clear();
		
		while(n>0){
			if(n%2) b = b * a;
			a = a*a;
			n /= 2;
		}
		printf("%lld",b[0][1]);
	}
}
