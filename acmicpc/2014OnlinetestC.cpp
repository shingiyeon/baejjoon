#include <iostream>
using namespace std;
int main(void)
{
	int T;
	cin>> T;
	for(int test=0; test<T; test++)
	{
		int m, n;
		cin>>m>>n;
		
		
		int right = 1;
		int x=0, y=0;
		cout<<"1"<<endl;
		for(x = 0; x<m; x++)
		{
			cout<<"("<<x<<",0)"<<endl;
		}

		x=m-1;
		
		while(1)
		{
			if(right == 1 && y<n)
				y++;
			if(right == 0 && y>0)
				y--;
			cout<<"("<<x<<","<<y<<")"<<endl;
			if( (right == 1&& y==n-1) || (right==0 && y==1) )
			{
				x--;
				if(x==-1)
					break;
				cout<<"("<<x<<","<<y<<")"<<endl;
				right = (right+1)%2;
			}
		
		}
	
	}
return 0;
}
