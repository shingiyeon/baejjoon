#include <iostream>
#include <queue>
using namespace std;
int main(void)
{
	int T;
	cin>>T;
	for(int test=0; test<T; test++)
	{
		int M,N,L,G;
		cin>>M>>N>>L>>G;
		int garo[M][N-1];
		int sero[M-1][N];

		queue<int> x;
		queue<int> y;
		queue<int> gas;
		queue<int> length;
		queue<bool> direction;


		for(int i=0; i<M;i++)
		{
			for(int j=0; j<N-1; j++)
			{
				cin>>garo[i][j];
			}
		}

		for(int i=0; i<M-1;  i++)
		{
			for(int j=0; j<N; j++)
			{
				cin>>sero[i][j];
			}
		}

		x.push(0);
		y.push(1);
		gas.push( garo[0][0]);
		length.push( L);
		direction.push(1);

		x.push(1);
		y.push(0);
		gas.push( sero[0][0]);
		length.push(L);
		direction.push(0);

		int ans = -1;

		while( !x.empty())
		{
			int tempx = x.front();
			int tempy = y.front();
			int tempG = gas.front();
			int templength = length.front();
			int tempdirection = direction.front();

			x.pop();
			y.pop();
			gas.pop();
			length.pop();
			direction.pop();


			if( tempx == M-1 && tempy == N-1)
			{
				if(tempG <= G)
				{
					if( templength < ans || ans == -1) 
						ans = templength;
				}
			}

			else{
				if(tempx < M-1)	
				{
					x.push(tempx+1);
					y.push(tempy);
					gas.push( tempG + sero[tempx][tempy]);
					direction.push(0);
					if( tempdirection == 1)
						length.push( templength+L+1);
					else
						length.push( templength+L);
				}

				if(tempy< N-1)
				{
					x.push(tempx);
					y.push(tempy+1);
					gas.push( tempG + garo[tempx][tempy]);
					direction.push(1);
					if( tempdirection == 0)
						length.push( templength+L+1);
					else
						length.push( templength+L);
				}
			}
		}

		cout<<ans<<endl;
	}

	return 0;
}
