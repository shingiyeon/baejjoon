#include <iostream>
using namespace std;
int main(void)
{
	int T;
	cin >> T;
	for(int test = 0; test < T; test ++)
	{
		int a, b;
		cin>>a>>b;
		
		while(b%a)
		{
			int k = b/a + 1;
			a = a * k - b;
			b = b * k;
		}

		cout<<b/a<<endl;
	}
	return 0;

}
