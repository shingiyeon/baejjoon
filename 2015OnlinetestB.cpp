#include <iostream>
using namespace std;
int dy[1001];
int max(int a, int b)
{
	if(a>b)
		return a;
	else
		return b;
}
int min(int a, int b)
{
	if(a<b)
		return a;
	else
		return b;
}

int findValue(int s, int e, int T)
{ 
	if( s>e) return 0;
	if( s==e)
		return dy[s];
	
	return 


int main(void){
	int T;
	cin>>T;
	while(T--){
		int N;
		cin>>N;
		for(int i=0; i<N; i++)
			cin>>dy[i];
		int start = 0;
		int end = N-1;
		int turn = 0;
		int ans1 = 0;
		int ans2 = 0;

		while(start <= end)
		{
			if(turn == 0)
			{
				if( max( dy[start+1], dy[end]) > max( dy[start], dy[end-1]))
				{
					ans1 = ans1 + dy[end];
					end--;
				}
				else
				{
					ans1 = ans1 + dy[start];
					start++;
				}
			}
			else
			{
				if( max( dy[start+1], dy[end]) > max(dy[start], dy[end-1]) )
				{
					ans2 = ans2 + dy[end];
					end--;
				}
				else
				{
					ans2 = ans2 + dy[start];
					start++;
				}
			}
			turn = (turn+1)%2;
		}
		cout<<ans1<<endl;
	}
}

