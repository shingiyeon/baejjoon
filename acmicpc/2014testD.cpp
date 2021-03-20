#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int main(void){
	int T;
	cin>> T;
	for(int test=0; test<T;test++)
	{
		int n, k, f;
		cin>>n>>k>>f;
		bool friendship[n+1][n+1];
		int num[n+1];

		memset(friendship, 0 , sizeof(friendship));
		memset(num,0,sizeof(num));

		for(int i=0; i<f; i++)
		{
			int tmp1, tmp2;
			cin>>tmp1>>tmp2;
			friendship[tmp1][tmp2] = 1;
			friendship[tmp2][tmp1] = 1;
			num[tmp1]++;
			num[tmp2]++;
		}

		while(1)
		{
			int i=1;
			for(;i<=n;i++)
			{
				if( num[i] < k)
					break;
			}

			if( i > n)
				break;
			else
			{
				for(int j=1; j<=n; j++)
				{


	
