#include <iostream>
using namespace std;
int main(void){
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		bool okay = 0;
		for(int B=2; B<=64; B++)
		{
			int arr[30];
			int tmp=0;
			int K = n;
			while( K / B != 0)
			{
				arr[tmp++] = K%B;
				K = K/B;
			}
			arr[tmp] = K;
			bool tmpokay = 0;
			int j=tmp;
			for( int i=0; i<=tmp/2; i++)
			{
				if( arr[i] != arr[j])
					tmpokay = 1;
				j--;
			}

			if(tmpokay == 0)
			{
				okay = 1;
				break;
			}
		}
		cout<<okay<<endl;
	}
}


			
