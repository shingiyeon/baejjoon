#include <iostream>
using namespace std;
// 0 is right 1 is down
int main(void)
{
	int T;
	cin>>T;
	for(int test=0; test<T; test++)
	{
		int M, N, L, G;
		cin>>M>>N>>L>>G;
		int gas[M][N][2];
		int turn[M][N][2];
		memset(dy,-1,sizeof(dy));
		memset(turn,-1,sizeof(turn));
		
		int garo[M][N-1];
		int sero[M-1][N];

		for(int i=0; i<M; i++)
			for(int j=0; j<N-1; j++)
				cin>>garo[i][j];
		for(int i=0; i<M-1; i++)
			for(int j=0; j<N; j++)
				cin>>sero[i][j];
		
		dy[0][0][0][0] = 0;
		dy[0][0][0][1] = 0;
		for( i=1; i<N; i++)
		{
			dy[0][i][0][0] = dy[0][i-1][0][0] + garo[0][i-1];
		}
		for( i=1; i<M; i++)
		{
			dy[i][0][0][1] = dy[i-1][0][0][1] + sero[i-1][0];
		}

		for( i=0; i<M; i++)
		{
			for(j=0; j<N; j++)
			{
				dy[i+1][j]




		

	}

	return 0;
}

