#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

int main(void)
{
	int test;
	cin>>test;
	while(test--)
	{
		int k, n;
		cin>>k>>n;
		int cla[4][1000];
		vector<int> a;
		vector<int> b;
		for(int i=0; i<4; i++)
		{
			for(int j=0; j<n; j++)
			{
				cin>>cla[i][j];
			}
		}
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				a.push_back( cla[0][i]+cla[1][j] );
				b.push_back( cla[2][i]+cla[3][j] );
			}
		}
		sort( a.begin(), a.end() );
		sort( b.begin(), b.end() );
		int ans = 0;
		int tempval;
		int low;
		int high;
		int mid;
		for(int i=0; i<a.size(); i++)
		{
			low = 0;
			high = b.size()-1;

			while(low <= high)
			{
				mid = (low+high)/2;
				tempval = a[i] + b[mid];
				if(tempval == k){
					ans = tempval;
					break;
				}
				if( tempval > k)
					high = mid-1;
				else
					low = mid+1;
				
				if( abs(tempval - k) < abs(ans - k) )
					ans = tempval;
				else if( ans == 0)
					ans = tempval;
				else if( (abs(tempval-k)== abs(ans-k)) && (tempval <ans))
					ans = tempval;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
