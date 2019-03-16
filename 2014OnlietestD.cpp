#include <iostream>

using namespace std;

int main()
{
	int a;
	int b;
	double ab;

	int c;

	int T;
	cin>>T;

	for(int i; i<T; i++)
	{
		cin>>a;
		cin>>b;
		int k=1;
		while(a!=0)
		{
			double k1 = (double)1/k;
			//cout <<k << endl;
			//cout << k1<<" "<< ab<< endl;
			cin>>c;
			ab = (double)a/b;
			if( k1 < ab)
			{
				a= (a*k - b);
				b= b*k;
			}
			else
			{
				k++;
			}
		}

		cout<<k<<endl;
	}

	return 0;
}

			
