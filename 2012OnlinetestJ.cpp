#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
struct Point{
	int x;
	int y;
};

bool cmp2(int a, int b)
{
	return a>b;
}

bool cmp( Point a, Point b)
{
	if(a.x < b.x)
		return 1;
	else if( (a.x == b.x) && (a.y < b.y) )
		return 1;
	else
		return 0;
}

using namespace std;

int main(void)
{
	int test;
	cin>>test;

	while(test--)
	{
		vector<int> xmap[20001];
		Point P[3000];
		int ans = 0;
		int N;
		cin>>N;

		for(int i=0; i<N; i++){
			scanf("%d%d",&P[i].x,&P[i].y);
			P[i].x = P[i].x+10000;
			xmap[ P[i].x ].push_back( P[i].y);
		}

		sort(P,P+N,cmp);

		for(int i=0; i<20001; i++)
			sort( xmap[i].begin(), xmap[i].end(), cmp2);
		
		for(int i=0; i<N-1; i++)
		{
			for(int j=i+1; j<N; j++)
			{
				if( P[i].y < P[j].y )
				{
					int h = P[j].y - P[i].y;
					int d = P[j].x - P[i].x;
					
					if( P[j].x+h < 20001)
					{
						if( binary_search( xmap[P[i].x+h].begin(), xmap[P[i].x+h].end(), P[i].y-d,cmp2) )
						{
							if(binary_search( xmap[P[j].x+h].begin(), xmap[P[j].x+h].end(), P[j].y-d,cmp2 ) )
							{
								if( d*d + h*h > ans)
									ans = d*d + h*h;
							}
						}
					}
				}

				else if ( P[i].y > P[j].y )
				{
					int h = P[i].y - P[j].y;
					int d = P[j].x - P[i].x;
					
					if( P[j].x+h < 20001)
					{
						if( binary_search( xmap[P[i].x+h].begin(), xmap[P[i].x+h].end(), P[i].y + d, cmp2) )
						{
							if(binary_search( xmap[P[j].x+h].begin(), xmap[P[j].x+h].end(), P[j].y+d, cmp2) )
							{
								if(d*d + h*h > ans)
									ans = d*d + h*h;
							}
						}
					}
				}

				else
				{
					int d = P[j].x - P[i].x;

					if( binary_search( xmap[P[i].x].begin(), xmap[P[i].x].end(), P[i].y - d, cmp2) )
					{
						if(binary_search( xmap[P[j].x].begin(), xmap[P[j].x].end(), P[j].y-d, cmp2) )
						{
							if( d*d > ans)
								ans = d*d;
						}
					}
				}
			}
		}

		cout << ans << endl;
	}
	return 0;
}

