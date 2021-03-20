#include <iostream>
#include <math.h>
#include <stdlib.h>
#define PI 3.14159265359
#define Swaplong(a,b) {long long t; t = a; a = b; b = t;}
#define Swapdouble(a,b) {double t; t = a; a= b; b = t;}
using namespace std;


class Stack{
	private:
		int *data;
		int cap;
	
	public:
		Stack(int capacity = 1000) { data = new int[capacity]; cap = -1;}
		int pop() { if(cap>=0) {return data[cap--];}}
		void push(int x) {
			cap++;
			data[cap] = x;
		}
		bool isEmpty() {
			return (cap == -1);
		}
		
		int getNum() { return (cap+1);}
		int getheadvalue() { return data[cap];}
		int getheadprevalue() {return data[(cap-1)];}
};


struct point{
	long long x;
	long long y;
	double angle;
};

long long ccw(point a, point b, point c)
{
	return (b.x - a.x)*(c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

void QuickSort(point *a, int n)
{
	int pivot = 0;
	int left=0; 
	int right=0;
	if(n<=1)
		return; 
	left = 0;
	right = n;
	while(1)
	{       
		for(left++; (left<n)&& ( (a[0].angle>a[left].angle) || ( (a[0].angle==a[left].angle && a[0].x>a[left].x))); left++);
		for(right--; (right>0)&&( (a[0].angle<a[right].angle) || ( (a[0].angle==a[right].angle && a[0].x<a[right].x)) ); right--);
		if( left< right)
		{       
			Swaplong( a[left].x , a[right].x);
			Swaplong( a[left].y , a[right].y);
			Swapdouble( a[left].angle, a[right].angle);
		}       
		else    
			break;  
	}       
	Swaplong( a[0].x , a[right].x);
	Swaplong( a[0].y , a[right].y);
	Swapdouble( a[0].angle, a[right].angle);
	QuickSort(a,right);
	QuickSort(a+left, n-left);
}



long long max(long long a, long long b)
{
	if(a>=b)
		return a;
	else
		return b;
}

long long min(long long a, long long b)
{
	if(a<=b)
		return a;
	else
		return b;
}


int main()
{
	int T;
	cin >> T;

	for(int test=0; test<T; test++)
	{
		int n;	cin>>n;
		point a[n];
		bool pruning[n];

		long long A=0;// maximize x-y
		long long B=0;// maximize x+y
		long long C=0;// minimize x-y
		long long D=0;// minimize x+y
		int prunNum=0;
		int convexNum=0;
		int mostdown=0;
		


		//Finding most down position point
		for(int i=0; i<n; i++){
		 	//cin>>a[i].x>>a[i].y;
			a[i].x = rand()%2000000001-1000000000;
			a[i].y = rand()%2000000001-1000000000; 
			pruning[i]=0;
			if( a[mostdown].y > a[i].y)
					mostdown=i;
			else if(a[mostdown].y == a[i].y && a[i].x < a[mostdown].x)
				mostdown =i;

		}
	
		

		//Finding all angle of all points
		for(int i=0; i<n; i++)
		{
			a[i].angle = atan2 ( a[i].y - a[mostdown].y , a[i].x - a[mostdown].x);
		}

	
		//Sort by the angle
		QuickSort( a,n);


		//pruning
		//
		//inition condition
		for(int i=1; i<4; i++)
		{
			if(a[i].x-a[i].y > a[A].x-a[A].y)
				A=i;
			if(a[i].x+a[i].y > a[B].x+a[B].y)
				B=i;
			if(a[i].x-a[i].y < a[C].x-a[C].y)
				C=i;
			if(a[i].x+a[i].y < a[D].x+a[D].y)
				D=i;

		}
		long long x1= max( a[C].x, a[D].x);
		long long x2= min( a[A].x , a[B].x);

		long long y1= max( a[A].y, a[D].y);
		long long y2= min( a[B].y, a[C].y);

		for(int i=4; i<n; i++)
		{
			if( (x2-x1)*(a[i].y - y1) > 0){			
			if( (y2-y1) * (a[i].x - x2)< 0){
			if( (x1-x2) * (a[i].y -y2) > 0){
			if( (y1-y2) * (a[i].x -x1) < 0){
				pruning[i] =1;
				prunNum++;
			}}}}
			
			if(pruning[i] == 0){

				if( a[i].x - a[i].y > a[A].x - a[A].y)
					A=i;			
				if( a[i].x + a[i].y > a[B].x + a[B].y)
					B=i;
				if( a[i].x - a[i].y < a[C].x - a[C].y)
					C=i;
				if( a[i].x + a[i].y < a[D].x + a[D].y)
					D=i;

				x1 = max( a[C].x, a[D].x);
				x2 = min( a[A].x, a[B].x);
	
				y1 = max( a[A].y, a[D].y);
		 		y2 = min( a[B].y, a[C].y);
			}
		}
	
//		cout<<A<<B<<C<<D<<endl;

		for(int i =0; i<n; i++)
		{
		   if( (x2-x1)*(a[i].y - y1) > 0){
                   if( (y2-y1) * (a[i].x - x2) < 0){
                   if( (x1-x2) * (a[i].y -y2) > 0){
                   if( (y1-y2) * (a[i].x -x1) < 0){
                                 pruning[i] = 1;
				 prunNum++;
		}}}}
		}

		prunNum= n-prunNum;
		
		int prun[prunNum];
		int temp=0;
		for(int i=0; i<n; i++)
		{
			if(pruning[i]==0)
			{
				prun[temp] = i;
				temp++;
			}
				
		}	
		
		for(int i=0; i<prunNum; i++)
		{
			cout<<"prun"<< a[prun[i]].x <<" "<<a[prun[i]].y<<endl;
		}



		cout<<"prunNum"<<prunNum<<endl;


		// convex hull "Graham Scan" algorithm
		//
		//

		int convex[prunNum];
		convexNum=2;

		convex[0]=0;
		convex[1]=1;
		while( convex[convexNum-1] != 0)
		{
			double smallestangle = 2*PI;
			int tmpnum;
			for(int j=0; j<prunNum; j++)
			{
				if( convex[convexNum-1] != prun[j] && convex[convexNum-2] != prun[j])
				{
					double tempangle;

					long long v1x =a[convex[convexNum-1]].x- a[convex[convexNum-2]].x;
					long long v1y =a[convex[convexNum-1]].y- a[convex[convexNum-2]].y;
					long long v2x =a[prun[j]].x-a[convex[convexNum-1]].x;
					long long v2y =a[prun[j]].y-a[convex[convexNum-1]].y;

					tempangle = acos( ((v1x*v2x)+(v1y*v2y)) / (sqrt( pow(v1x,2)+pow(v1y,2)) * sqrt(pow(v2x,2)+pow(v2y,2))));
					if(tempangle<smallestangle){
						smallestangle = tempangle;
						tmpnum=prun[j];
					}
				}
			}

			convex[convexNum] = tmpnum;
			convexNum++;
		}


		cout<<convexNum<<endl;




		/*Stack S;

		S.push(0);
		S.push(1);

		for(int i=2; i<prunNum; i++)
		{
			int preval = S.getheadprevalue();
			int val = S.getheadvalue();
			if( ccw (a[preval], a[val], a[ prun[i]]) >= 0)
				S.push( prun[i] );
			else
			{
				cout<<S.pop()<<endl;;
				S.push( prun[i]);
			}
		}
		
		convexNum = S.getNum();

		cout<<"convexNum"<<convexNum<<endl;
		int convex[convexNum];
		int tmp=convexNum-1;

		while( S.getNum() != 0)
		{
			convex[tmp] = S.pop();
			tmp--;
		}
*/
		for(int i=0; i<convexNum; i++)
		{
			cout<<a[convex[i]].x<<" "<<a[convex[i]].y<<endl;
		}


		long double area = 0;
		
		if(convexNum == 3)
		{	
			long long v1x = a[ convex[1]].x - a[ convex[0]].x;
			long long v1y = a[ convex[1]].y - a[ convex[0]].y;
			long long v2x = a[ convex[2]].x - a[ convex[0]].x;
			long long v2y = a[ convex[2]].y - a[ convex[0]].y;

			area = 0.5* fabs(v1x * v2y - v1y*v2x);
		}

		else
		{ 
		//	long long longdistance = 0;
	//		long long tempdistance;
			int longa;
			int longb;
/*
			for(int i=0; i<convexNum-1; i++)
			{
				for(int j=i+1; j<convexNum; j++)
				{
					tempdistance = sqrt( pow( a[ convex[j] ].x - a[ convex[i]].x, 2) + pow( a[convex[j]].y - a[convex[i]].y, 2));

					if(tempdistance > longdistance)
					{
						longdistance=tempdistance;
						longa = i;
						longb = j;
					}
				}
			}
			
*/			area = 0;
			long double area1 = 0;
			long double area2 = 0;

			long double temparea;
			
			// n^3 processing
			for(longa = 0; longa < convexNum-2; longa++){
				for(longb = longa+2; longb < convexNum; longb++){
						temparea=0;
						area1=0;
						area2=0;
						for(int i=0; i<convexNum; i++)
						{
							long long v1x = a[ convex[longb] ].x - a[ convex[longa] ].x;
							long long v1y = a[ convex[longb] ].y - a[ convex[longa] ].y;
							long long v2x = a[ convex[i]].x - a[ convex[longa]].x;
							long long v2y = a[ convex[i]].y - a[convex[longa]].y;
				
							temparea = 0.5 * fabs( v1x*v2y - v1y*v2x);
							

							if(i>longa && i<longb)
							{
								if(temparea > area1)
									area1 = temparea;
							}
				
							else if (i!= longa && i!=longb)
							{
								if(temparea > area2)
									area2 = temparea;
							}
						}	
						
						

						if( area1 + area2 > area)
							area= area1 + area2;
												
				}
			}

					
			
			// n^4 processing		
			/*
			
			long long v1x;
			long long v1y;
			long long v2x;
			long long v2y;
			long long v3x;
			long long v3y;

			for(int i=0; i<convexNum-3; i++)
			{
				for(int j=i+1; j<convexNum-2; j++)
				{	
					for( int k=j+1; k<convexNum-1; k++)
					{
						for( int l=k+1; l<convexNum; l++)
						{
							v1x = a[convex[j]].x-a[convex[i]].x;
							v1y = a[convex[j]].y-a[convex[i]].y;
							v2x = a[convex[k]].x-a[convex[i]].x;
							v2y = a[convex[k]].y-a[convex[i]].y;
							v3x = a[convex[l]].x-a[convex[i]].x;
							v3y = a[convex[l]].y-a[convex[i]].y;
							
							long double area1= 0.5* fabs( v1x*v2y - v1y*v2x);
							long double area2= 0.5* fabs( v1x*v3y - v1y*v3x);


			//long double area1 = 0.5* fabs( (a[convex[j]].x-a[convex[i]].x)*(a[convex[k]].y - a[convex[i]].y) - (a[convex[j]].y-a[convex[i]].y)*(a[convex[k]].x-a[convex[i]].x));
			//long double area2 = 0.5* fabs( (a[convex[k]].x-a[convex[i]].x)*(a[convex[l]].y-a[convex[i]].y) - (a[convex[k]].y-a[convex[i]].y)*(a[convex[l]].x-a[convex[i]].x));
								
								if(area1 + area2 > area)
										area = area1 + area2;
								
						}
							
					}
				}
			}
			*/
		}
		cout<<area<<endl;
	}
}


