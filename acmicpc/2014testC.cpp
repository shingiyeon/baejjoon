#include <iostream>
using namespace std;
int main(){
	int T;
	cin >> T;
	int a[51];
	bool possible = 0;
	for(int i=0; i<51; i++)
		a[i]=i*(i+1)/2;

	for(int test=0; test<T; test++)
	{
		int n;
		cin>>n;
		
		for(int i=50; i>=1; i--)
			if( n - a[i] >= 0)
				for(int j=i; j>=1; j--)
					if( n - a[i] - a[j] >= 0)
						for(int k=j; k>=1; k--)
							if( n- a[i] - a[j] - a[k] == 0)
							{
								possible=1;
								//cout<<" "<<a[i]<<" "<<a[j]<<" "<<a[k]<<endl;
							}
		cout<<possible<<endl;
	}
	return 0;
}
