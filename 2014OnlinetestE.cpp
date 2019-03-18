#include <iostream>
#include <math.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

struct point{
	int x;
	int y;
};

int main()
{
	int n;
	int T;
	
	double ans;
	double max;
	int maxp1;
	int maxp2;


	
	cin>>T;
	for(int i=0; i<T; i++)
	{
		cin>>n;
		point a[n];

		for(int j=0; j<n; j++)
		{
			cin>>a[j].x>>a[j].y;
		}
			
		int sumx=0;
		int sumy=0;
		int avgx;
		int avgy;
/*
		for(int i=0; i<n; i++)
		{
			a[i].x= rand()%20000001-10000000;
			a[i].y= rand()%20000001-10000000;
		}
*/
		for(int i=0; i<n; i++)
		{
			sumx=sumx+a[i].x;
			sumy=sumy+a[i].y;
		}

		avgx=sumx/n;
		avgy=sumy/n;

		max = sqrt( pow((a[0].x - avgx), 2) + pow( (a[0].y - avgy), 2)); 
		
		for(int i=1; i<n; i++)
		{
			if( sqrt( pow((a[i].x - avgx), 2) + pow( (a[i].y - avgy), 2)) > max)
			{
				max = sqrt ( pow((a[i].x - avgx), 2) + pow( (a[i].y - avgy), 2));
			}
		}

		ans = max;

		for(int j=0; j<n; j++)
		{
			double r;

			r= sqrt( pow((a[j].x - avgx), 2) + pow( (a[j].y - avgy), 2));
			
			if( r >= max *0.9)
			{
				for(int k=j; k<n; k++)
				{
					double temp = sqrt ( pow((a[j].x - a[k].x),2)+ pow( (a[j].y - a[k].y),2));
					

					if( temp > max)
					{
						max = temp;
						maxp1 = j;
						maxp2 = k;
					}
				}
			}
		}

		cout<< a[maxp1].x <<" " << a[maxp1].y<<" " <<a[maxp2].x<<" "<<a[maxp2].y<<endl;
	}

	return 0;
}
