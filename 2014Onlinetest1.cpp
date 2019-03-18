#include <iostream>

using namespace std;

int main()
{
	int T;

	cin>>T;

	int M;
	int N;
	int H;

	for(int i=0; i<T; i++)
	{

		cin>>M>>N>>H;
		
		
		int ans= ((((H-1)%M)+1)*100)+(((H-1)/M)+1);
		cout<<ans<<endl;
	}

	return 0;
}


