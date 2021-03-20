#include <iostream>
using namespace std;
int main(void)
{
	int T;
	cin>>T;
	for(int test=0; test<T; test++)
	{
		int xmin, ymin, xmax, ymax;
		int x1,y1,x2,y2;
		cin>>xmin>>ymin>>xmax>>ymax>>x1>>y1>>x2>>y2;
		int ans = 0;
		if(  (x1==x2 && (x1 == xmin || x1==xmax)) || (y1==y2 && (y1==ymin || y1==ymax)))
		{
			ans = 4;
		}
		else
		{
			long double k;
			bool fin = 0;
			bool yminfin = 0;
			bool ymaxfin = 0;
			if(  (x1<=xmin && xmin<=x2) ||  (x2<=xmin && xmin<=x1)  )
			{
				if(x1<=x2)
					k = (long double)((long double)(xmin - x1)*(long double)(y2-y1)/(long double)(x2-x1))+(long double)y1;
				else
					k = (long double)((long double)(xmin - x2)*(long double)(y1-y2)/(long double)(x1-x2))+(long double)y2;
				if(k==ymin || k==ymax)
				{
					ans++;
					fin = 1;
					if( k== ymin)
						yminfin = 1;
					else
						ymaxfin = 1;
				}
				
				if( ymin<=k && k<=ymax && fin == 0)
				{	ans++; }
			}
			fin = 0;
			if( (x1<=xmax && xmax<=x2) || (x2<=xmax && xmax<=x1))
			{
				if(x1<=x2)
					k = (long double)( (long double)(xmax - x1)*(long double)(y2-y1)/(long double)(x2-x1)) +(long double)y1;
				else
					k = (long double)( (long double)(xmax - x2)*(long double)(y1-y2)/(long double)(x1-x2)) +(long double)y2;
				if(k==ymin || k==ymax)
				{
					ans++;
					fin = 1;
					if(k==ymin)
						yminfin = 1;
					else
						ymaxfin = 1;
				}
				
				if( ymin<=k && k<=ymax && fin == 0)
				{	ans++; }
			}
			if(  (y1<=ymax && ymax<=y2) || (y2<=ymax && ymax<=y1) )
			{
				if(y1<=y2)
					k = (long double)( (long double)(ymax - y1) * (long double)(x2-x1)/(long double)(y2-y1)) + (long double)x1;
				else
					k = (long double)( (long double)(ymax - y2) * (long double)(x1-x2)/(long double)(y1-y2)) + (long double)x2;
				 if( xmin<=k && k<=xmax && ymaxfin==0)
				{	ans++; }
			}
			if( (y1<=ymin && ymin<=y2) || (y2<=ymin && ymin<=y1))
			{
				if(y1<=y2)
					k = (long double)( (long double)(ymin - y1) * (long double)(x2-x1) / (long double)(y2-y1))+(long double)x1;
				else
					k = (long double)( (long double)(ymin - y2) * (long double)(x1-x2) / (long double)(y1-y2))+(long double)x2;
				if( xmin<=k && k<=xmax &&yminfin==0)
				{	ans++; }
			}

		}
		cout<<ans<<endl;
	}
	return 0;
}
