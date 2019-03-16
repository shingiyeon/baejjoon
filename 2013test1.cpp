#include <iostream>

using namespace std;

int main()
{
	int A[100][100];
	int m, n;
	int T;
	
	

	cin>>T;

	int *answer = new int[T];

	
	for(int z=0; z<T; z++)
	{
	
		cin>>m>>n;
		int ans = 0;	
	
		for(int i=0; i<m; i++)
		{
			for(int j=0; j<n; j++)
			{
				cin>> A[i][j];
			}
		}

		for(int i=0; i<m; i++)
		{
			for(int j=0; j<n; j++)
			{
				if( A[i][j]==1 )
				{
					int max = i;

					for(int k=m-1; k>i; k--)
					{
						if( A[k][j]== 0)
						{
							max=k;
						}
					}

					ans = ans + (max-i) ;
					A[i][j]=0;
					A[max][j]=1;
				}
			}
		}

		answer[z]=ans;
	}

	for(int i=0; i<T; i++)
	{
		cout<<answer[i]<<endl;
	}

	

	return 0;
}
					
		 

	
