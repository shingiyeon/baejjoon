#include <iostream>
#include <stdio.h>
using namespace std;
int main(void)
{
	int T;
	cin>>T;
	while(T--)
	{
		int n, k, t, m;
		cin>>n>>k>>t>>m;
		int dy[n+1][k+1];
		int score[n+1];
		int submit[n+1];
		int last[n+1];
		for(int i=0; i<=n; i++)
		{
			score[i]=0;
			submit[i]=0;
			for(int j=0; j<=k; j++)
				dy[i][j] = 0;
		}

		for(int i=0; i<m; i++)
		{
			int tmpx, tmpy, tmpscore;
			scanf("%d%d%d",&tmpx,&tmpy,&tmpscore);
			submit[tmpx]++;
			last[tmpx]=i;
			if( dy[tmpx][tmpy] <= tmpscore)
				dy[tmpx][tmpy] = tmpscore;
		}

		for(int i=0; i<=n; i++)
		{
			for(int j=0; j<=k; j++)
				score[i] = dy[i][j] + score[i];
		}
		int ans = 1;
		for(int i=1; i<=n; i++)
		{
			if( score[i] > score[t] )
				ans++;
			else if( score[i] == score[t])
			{
				if( submit[i] < submit[t])
					ans++;
				else if( submit[i] == submit[t] )
				{
					if( last[i] < last[t] )
						ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
}
