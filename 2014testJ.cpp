#include <iostream>
using namespace std;
int main(void)
{
	int T;
	cin>>T;
	for(int test=0; test<T;test++)
	{
		int m, n, p;
		cin>>m>>n>>p;
		if(p==3)
		{
			for(int i=0; i<n; i++)
			{
				for(int j=0; j<m; j++)
				{
					cout<<"("<<j<<","<<i<<")"<<"\n";
				}
			}
		}

		else
		{
			for(int i=0; i<m; i++)
				cout<<"("<<i<<",0)"<<"\n";

			for(int i=n-1; i>=1; i--)
			{
				if(i%2)
				{
					for(int j=m-1; j>=0; j--)
						cout<<"("<<j<<","<<i<<")"<<"\n";
				}
				else
				{
					for(int j=0; j<m; j++)
						cout<<"("<<j<<","<<i<<")"<<"\n";
				}
			}
		}
	}
}
