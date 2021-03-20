#include <iostream>
#include <stdio.h>
typedef long double ld;
using namespace std;
int main(void){
	int test;
	cin>>test;
	while(test--)
	{
		ld m,n,ans;
		cin>>m>>n;
		ans = (n/2) + (m/3) -(1/ (ld)(3*m));
		printf("%0.1llf\n",ans);
	}
}
