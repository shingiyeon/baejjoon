#include <iostream>
#include <math.h>
using namespace std;
int max(int x, int y)
{
	if( x < y)
		return y;
	else
		return x;
}
int main(void)
{
	int M, N;
	cin>>M;
	N = 0;
	int dy[20][25000];
	while(1)
	{
		cin>>dy[0][N++];
		if(dy[0][N-1]==-1)
			break;
	}
	N--;
	int row = log2(N);
	for(int j=1; j<=row; j++)
	{
		for(int i =0; i < N- (pow(2,j)-1); i++)
		{
			int temp = pow(2, j-1);
			int temp1 = dy[j-1][i];
			int temp2 = dy[j-1][i+temp];
			dy[j][i] = max(temp1, temp2);
		}
	}
	int l = log2(M);
	for(int i = 0; i<=N-M; i++)
	{
		int temp = pow(2,l);
		cout<< max(dy[l][i], dy[l][i+M-temp])<<endl;
	}
	return 0;
}
