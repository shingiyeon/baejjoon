#include <iostream>
#include <math.h>
#include <algorithm>
#include <stdio.h>
#define Swapll(a,b) {long long t; t=a; a=b; b=t;}
#define Swapld(a,b) {long double t; t=a; a=b; b=t;}
using namespace std;
typedef long double ld;
typedef long long ll;

struct point{
	ll x;
	ll y;
	ld angle;
};

ll finddistance(point a, point b)
{
	return ( pow( a.x- b.x,2) + pow( a.y-b.y,2));
}

ll ccw(point a, point b, point c)
{
	return( ((b.x - a.x)*(c.y - a.y)) - ((b.y - a.y) * (c.x - a.x)));
}

bool cmp(point a, point b)
{
	if( a.angle != b.angle)
		return a.angle < b.angle;
	else
		return (a.x < b.x);
}

int main(void)
{
	int T;
	cin >> T;
	for(int test =0; test < T; test++)
	{
		int N;
		cin >> N;
		point a[N];
		int stack[N];
		int pointer=0;

		int minyx=0;

		for(int i=0; i<N; i++){
			scanf("%lld %lld",&a[i].x,&a[i].y);
			if(a[minyx].y > a[i].y)
				minyx=i;
			else if(a[minyx].y == a[i].y && a[minyx].x > a[i].x)
				minyx=i;
		}

		for(int i=0; i<N; i++)
			a[i].angle = atan2l( a[i].y-a[minyx].y , a[i].x-a[minyx].x);

		sort(a,a+N,cmp);	

		stack[0]=0;
		stack[1]=1;
		pointer=1;

		for(int i=2; i<N; i++)
		{
			while( ccw( a[ stack[pointer-1]], a[ stack[pointer]], a[i])<=0)
			{
				if(pointer > 1)
					pointer--;
				else if( i==N )
					break;
				else
					i++;
			}
			pointer++;
			stack[pointer]=i;
		}
		
		if( ccw( a[ stack[pointer-1]], a[ stack[pointer]], a[0]) <= 0 )
		{
			pointer--;
		}
		
		int convexNum = pointer+1;

		ll answer = 0;
		int p1, p2=1;
		int tmpx, tmpy;
		tmpy=1;
		int j=1;
		for(int i=0; i<convexNum; i++)
		{
			ll tmp=0;
			j=p2;
			while(1)
			{
				if(j==i)
					break;
				if(j==convexNum)
					j=0;
				ld temp = finddistance( a[stack[i]], a[stack[j]]);
				if(temp >= tmp){
					tmp = temp;
					tmpx = i;
					tmpy = j;
					j++;
				}			
				else
					break;
			}

		
			if( answer < tmp)
			{
				answer = tmp;
				p1 = tmpx;
				p2 = tmpy;
			}
			
		}
		cout<< a[ stack[p1]].x<< " "<<a[ stack[p1]].y<<" "<<a[stack[p2]].x<<" "<<a[stack[p2]].y<<endl<<endl;
	}
	return 0;
}
