#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;

	while(n--)
	{
		int M, N, x, y;
		cin>>M>>N>>x>>y;

		bool okay = 0;
		int tmp;
		for(int i=0; i<=N; i++)
		{
			tmp = x + (i*M);
			if( tmp % N == (y%N))
			{
				okay = 1;
				break;
			}
		}

		if(okay == 0)
			tmp = -1;

		cout<<tmp<<endl;
	}
}				
