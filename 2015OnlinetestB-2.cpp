#include <iostream>
#include <stdio.h>
using namespace std;
int A[1001];
int S[1001];
int D[1001][1001];
int max(int a, int b)
{
	if(a>b)
		return a;
	else
		return b;
}
int dy(int s, int e)
{
	if( s> e) return 0;
	if( s== e) return A[s];
	if(D[s][e] >= 0) return D[s][e];
	D[s][e] = max( S[e] - S[s-1] - dy(s+1,e) , S[e] - S[s-1] - dy(s,e-1));
	return D[s][e];
}

in main(void)
{
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		S[0]  = 0;
		for(int i=1; i<=N; i++){
			scanf("%d",&A[i]);
				S[i] = S[i-1]+A[i];
			for(int j=i; j<=N; j++)
				D[i][j] = -1;
		}
		cout<<dy(1,N)<<endl;
	}
}
