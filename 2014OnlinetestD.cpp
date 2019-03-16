#include <iostream>
using namespace std;
int main(void)
{
	int T;
	cin >> T;

	for(int test = 0; test<T; test++)
	{
		long long a;
		long long b;
		long long ab;
		cin>>a>>b;
		ab = (long long)b/a;
		while(a!=1)
		{

			if( a*ab - b >= 0)
			{
				long long tmp = b;
				b= b*ab;
				a= a*ab - tmp;
				
				ab++;

				long long temp = 2;
				
				while(1)
				{
					if( a%temp == 0 && b%temp == 0)
					{
						a = a/temp;
						b = b/temp;
					}

					else
					{
						temp++;
						if(temp > a)
							break;
					}
				}
				if(a==0)
					break;
				ab = b/a;
			}
			else
				ab++;
		}
		cout<<b<<endl;
	}
	return 0;
}
