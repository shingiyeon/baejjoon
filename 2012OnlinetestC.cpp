#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

struct Point{
	int x;
	int y;
};

bool cmp(Point a, Point b)
{
	if( a.x < b.x )
		return 1;
	else if( (a.x == b.x) && (a.y<b.y) )
		return 1;
	else
		return 0;
}

bool cmp2(Point a, Point b)
{
	if( a.y < b.y )
		return 1;
	else if( (a.y == b.y) && (a.x<b.x) )
		return 1;
	else
		return 0;
}

int main(void)
{
	int test;
	cin >> test;

	while(test--)
	{
		int n;
		cin>>n;
		Point p[10000];
		
		for(int i=0; i<n; i++)
			scanf("%d%d",&p[i].x,&p[i].y);


		int serox[10000];
		int seroy[10000];
		int garox[10000];
		int garoy[10000];

		sort(p,p+n,cmp);

		for(int i=0; i<n; i++)
		{
			serox[i]=p[i].x;
			seroy[i]=p[i].y;
		}

		sort(p,p+n,cmp2);

		for(int i=0; i<n; i++)
		{
			garox[i]=p[i].x;
			garoy[i]=p[i].y;
		}

		bool pos = 1;
		int gae = 0;

		for(int i=0; i<n; i=i+2)
		{
			for(int j=0; j<n; j=j+2)
			{
				if( garoy[i] != garoy[i+1] || serox[j] != serox[j+1])
				{
					pos=0;
					break;
				}

				if( (garox[j] < serox[i]) && (garox[j+1] > serox[i]) && (seroy[i] < garoy[j]) && (garoy[j] < seroy[i+1]))
				{
					pos = 0;
					break;
				}
			}
		}

		if(pos)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}


