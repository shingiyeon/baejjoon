#include <iostream>
using namespace std;
int dy[100][100];
int min(int a, int b)
{
	if(a<b)
		return a;
	else
		return b;
}
int main{
	int T;
	cin>>T;
	while(T--)
	{
		bool visited[100];
		int arr[100];
		int N,K;
		cin>>N>>K;
		for(int i=0; i<N-1; i++)
			cin>>arr[i];
		for(int i=0; i<N; i++)
			
