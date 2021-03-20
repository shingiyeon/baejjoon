#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

int main(void)
{
	int T;
	cin>>T;

	while(T--)
	{
		int n,m;
		cin>>n>>m;

		long long a = 0;
		long long b = 0;

		int arra[1000000];
		int arrb[1000000];

		for(int i =0; i<n; i++){
			scanf("%d",&arra[i]);
			a=a+arra[i];
		}
		for(int i =0; i<m; i++){
			scanf("%d",&arrb[i]);
			b=b+arrb[i];
		}

		long long min = 
		
