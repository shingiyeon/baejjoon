#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
int main(void){
	int test;
	cin>>test;
	while(test--)
	{
		double n, m;
		double ans = 0.0;
		double temp;
		cin>>n>>m;
		for(int i=0; i<n; i++)
		{
			scanf("%lf",&temp);
			printf("%lf\n",temp);
			ans = ans +  (temp / n);
		}
		for(int j=0; j<m; j++)
		{
			scanf("%lf",&temp);
			printf("%lf\n",temp);
			ans = ans + ( temp / m);
		}
		printf("%lf\n",ans);
		printf("%0.1lf\n",ans);
	}
}

