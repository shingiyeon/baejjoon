#include <iostream>
#include <math.h>
typedef long long ll;
using namespace std;
int max(int x1, int x2, int y1, int y2)
{
	if( abs(x1-x2)> abs(y1-y2))
		return abs(x1-x2);

	else
		return abs(y1-y2);
}

struct Point {
	ll x;
	ll y;
};
int main(void){
	int T;
	cin>>T;
	for(int test=0; test<T; test++)
	{
		int n;
		cin>>n;
		Point p[n];

		int xmin=0;
		int xmax=0;
		int ymin=0;
		int ymax=0;

		for(int j=0; j<n; j++){
			cin>>p[j].x>>p[j].y;
			if( p[j].x < p[xmin].x)
				xmin=j;
			if( p[j].x > p[xmax].x)
				xmax=j;
			if( p[j].y < p[ymin].y)
				ymin=j;
			if( p[j].y > p[ymax].y)
				ymax=j;
		}

		int ans=0;

		if(n==3)
			ans=0;
		else
		{
			ans= max(xmin,xmax,ymin,ymax) / 3;
			while(1)
			{
				for(int m=0; m<ans*2; m++)
				{
					bool visited[n];
					int mostleft=0;
					int mostup=0;
					for(int i=0; i<n; i++)
						visited[i]=0;
	
					for(int j=0; j<n; j++)
					{
						if( p[j].x < p[mostleft].x)
							mostleft = j;
					}



					


				


		}


		
	}
