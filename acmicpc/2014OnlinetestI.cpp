#include <iostream>
#include <algorithm>
using namespace std;
struct Point{
	int x;
	int y;
};

int main(void)
{
	int T;
	cin >> T;
	for(int test=0; test<T; test++)
	{
		int m, n, c;
		cin>>m>>n>>c;
		Point p[c];
		bool a[m][n];
		int visited[m][n];

		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				a[i][j]=0;
				visited[i][j]=1;}
		}

		for(int i=0; i<c; i++)
		{
			cin>>p[i].x>>p[i].y;
			a[ (p[i].x -1) ][ (p[i].y -1) ] = 1;
			visited[ p[i].x-1 ][ p[i].y-1 ] = 0;
		}
		
		int dy[m][n];
		
		for(int i=0; i<m; i++)
			for(int j=0; j<n; j++)
				dy[i][j]=0;

		for(int i=0; i<m; i++)
		{
			for( int j=0; j<n; j++)
			{
					
				for(int k=i-1; k<=i+1; k++)
				{
					for(int l=j-1; l<=j+1; l++)
					{
						if(0<=k && k<m && 0<=l && l<n)
						{
							if( a[k][l] == 1)
								dy[i][j]++;
						}
					}
				}
			}
		}/*
		for(int i=0; i<m; i++)
		{
			for(int j=0; j<n; j++)
			{
				cout<<visited[i][j]<<" ";
			}
			cout<<endl;
		}

		for(int i=0; i<m; i++)
		{
			for(int j=0; j<n; j++)
			{
				cout<< dy[i][j]<<" ";
			}
			cout<<endl;
		}*/

		int tempx;
		int tempy;
		int ans=0;

		for(int i=0; i<m; i++)
		{
			for(int j=0; j<n; j++)
			{				
				if( visited[i][j] == 0 )
				{					
					int max = 0;
					for( int k=i-1; k<=i+1; k++)
					{
						for( int l=j-1; l<=j+1; l++)
						{
							if(0<=k && k<m && 0<=l && l<n)
							{
								if( dy[k][l] >= max)
								{
									max = dy[k][l];
									tempx = k;
									tempy = l;
								}
							}
						}
					}
					
					for( int k= tempx-1; k<=tempx+1; k++)
					{
						for(int l=tempy-1; l<=tempy+1; l++)
						{
							if( visited[k][l]==0)
							{
								visited[k][l]=1;
								
								for( int x1= k-1; x1<=k+1; x1++)
								{
									for( int y1= l-1; y1<=l+1; y1++)
									{
										if(0<=x1 && x1<m && 0<=y1 && y1<n)
										{
											dy[x1][y1]--;
										}
									}
								}
							}
						}
					}
					ans++;
				/*	cout<<max<<" "<<tempx<<" "<<tempy<<endl;

					for(int k=0; k<m; k++)
					{
						for(int l=0; l<n; l++)
						{
							cout<<visited[k][l]<<" ";
						}
						cout<<endl;
					}
					cout<<endl;

					for( int k=0; k<m; k++)
					{
						for(int l=0; l<n; l++)
						{
							cout<<dy[k][l]<<" ";
						}
						cout<<endl;
					}*/


				}
			}
		}
	cout<<ans<<endl;
	}
	return 0;
}

