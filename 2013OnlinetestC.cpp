#include <iostream>
#include <limits.h>
#include <math.h>
using namespace std;
struct point{
	long long x;
	long long y;
	double angle;
	int line;
};

void Itsline(point *a, int pt,  int n)
{
	long long v1x, v1y, v2x, v2y;

	int ptbefore;
	int ptafter;

	if(pt == 0)
		ptbefore = n-1;
	else
		ptbefore = pt-1;
	if(pt == n-1)
		ptafter = 0;
	else
		ptafter = pt+1;

	v1x = a[pt].x - a[ptbefore].x;
	v1y = a[pt].y - a[ptbefore].y;
	v2x = a[ptafter].x - a[ptbefore].x;
	v2y = a[ptafter].y - a[ptbefore].y;
	
	if(v1x * v2y - v2x * v1y == 0)
	{
		if( a[ptbefore].line != 1)
			a[ptbefore].line = -1;
		a[ptafter].line = -1;
		a[pt].line = 1;
	}

}

bool correctline(point *a, int start, int end, int n)
{
	

	int inside = end - start - 1;

	int outside = n - (inside) -2;
	long double insideangle = 0;
	long double outsideangle = 0;
	
	if(start > end)
	{
		for(int i=start+1; i<n; i++)
			insideangle = insideangle + a[i].angle;
		for(int i=0; i<end; i++)
			insideangle = insideangle + a[i].angle;
		for(int i=end+1; i<start; i++)
			outsideangle= outsideangle +a[i].angle;
	}
	
	else
	{
		for(int i=start+1; i<end; i++)
			insideangle = insideangle + a[i].angle;
		for(int i=end+1; i<n; i++)
			outsideangle = outsideangle + a[i].angle;
		for(int i=0; i<start; i++)
			outsideangle = outsideangle + a[i].angle;
	}	

	if( M_PI * (inside) - insideangle <= M_PI )
		if( M_PI * (outside) - outsideangle <= M_PI)
			return 1;
	return 0;
}

int findPivot(int line, int start, int end, point *a, int amount)
{
	int pivot = (start + end) / 2;

	if( correctline(a, line, pivot, amount) == 1)
		return pivot;
	else
	{
		if(end > start)
		{
			findPivot(line,start, pivot, a,amount);
			findPivot(line,  pivot+1, end, a, amount);
		}

		else if( start == end && end == amount-1)
			return -1;
	}
}

int findleftmost(int line, int start, int end , point *a, int amount)
{
	if(start == end)
		return start;
	int pivot = (start + end) / 2;

	if( correctline(a, line, pivot, amount) == 1)
		findleftmost( line, start, pivot, a, amount);

	else
	{
		findleftmost( line, pivot+1, end, a, amount);
	}
}

int findrightmost(int line, int start, int end, point *a, int amount)
{
	if(start > end)
		return end;
	int pivot = (start + end) / 2;

	if( correctline(a, line, pivot, amount) == 1)
		findrightmost(line, pivot+1, end, a, amount);
	else
		findrightmost(line, start, pivot-1, a, amount);
}

int main(void)
{
	int T;
	cin>>T;

	for(int test=0; test<T; test++)
	{
		int n;
		cin >> n;
		point a[n];
		int tmp=0;

		for(int i=0; i<n; i++){
			cin >> a[i].x >> a[i].y;
			a[i].line = 0;
		}
		
	
		for(int i=0; i<n; i++)
		{
			Itsline(a, i, n);
		}
		
		for(int i=0; i<n; i++)
		{
			cout<<a[i].line<<endl;
		}

		long long v1x = a[1].x - a[0].x;
		long long v2x = a[n-1].x - a[0].x;
		long long v1y = a[1].y - a[0].y;
		long long v2y = a[n-1].y - a[0].y;
		
		a[0].angle = acos(( (v1x*v2x) + (v1y*v2y)) /( sqrt ( pow(v1x,2) + pow(v1y,2) ) *  sqrt( (pow(v2x,2) + pow(v2y,2) ) )));

		v1x = a[0].x - a[n-1].x;
		v2x = a[n-2].x - a[n-1].x;
		v1y = a[0].y - a[n-1].y;
		v2y = a[n-2].y - a[n-1].y;

		a[n-1].angle = acos( ((v1x*v2x) + (v1y*v2y)) / (sqrt (pow(v1x,2) + pow(v1y,2)) * sqrt( (pow(v2x,2) + pow(v2y,2)))));

		for( int i=1; i<n-1; i++)
		{
			v1x = a[i+1].x - a[i].x;
			v2x = a[i-1].x - a[i].x;
			v1y = a[i+1].y - a[i].y;
			v2y = a[i-1].y - a[i].y;

			a[i].angle = acos( ((v1x*v2x) + (v1y*v2y)) / (sqrt (pow(v1x,2) + pow(v1y, 2)) * sqrt( (pow(v2x,2) + pow(v2y,2)))));
		}

		int ans=0;
		int beforeok = 0;
		int tmp;
		for(int i=0; i<n-1; i++)
		{

			int tmp = i+1;
			int tmpbefore;

			if(i ==0)
				tmpbefore = n-1;
			tmpbefore = i;

			if( a[tmp].line == 1 || (a[tmp].line == -1 && a[i].line == 1))
			{
				if(tmp != n-1)
					tmp++;
			}

			if( a[tmpbefore] == 1 ) 
			{
				if(tmpbefore != 0)
					tmpbefore--;
				else
					tmpbefore = n-1;
			}


			int temp=findPivot(i,tmp,n-1,a,n);

			if( temp != -1)
			{
				int leftmost = findleftmost(i, tmp,temp , a, n);
				int rightmost = findrightmost(i, temp, n-1, a, n);
				ans = rightmost - leftmost + 1 + ans;
				cout << rightmost - leftmost +1 <<endl;
			}
		}

		cout<<ans<<endl;
	}
	return 0;
}	
