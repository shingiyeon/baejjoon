#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
struct ant{
	int ID;
	int pos;
	int direction;
	int distance;
};
bool cmp(ant a, ant b)
{
	if( a.distance != b.distance)
		return a.distance < b.distance;
	else
		return a.ID < b.ID;
}
int main(void){
	int T;
	cin>>T;
	while(T--)
	{
		int ll = 0;
		int lr = 0;
		int rl = 0;
		int rr = 0;

		int N, L, K;
		cin>>N>>L>>K;
		ant arr[N];
		for(int i=0; i<N; i++)
		{
			scanf("%d %d",&arr[i].pos,&arr[i].ID);
			if(arr[i].ID >= 0)
				rr++;
			else
				arl++
		}

		for(int i=0; i<N; i++)
		{
			if(arr[i].ID >= 0)
			{
				rr--;
				if( rl > lr)
					arr[i].direction = -1;
				else
					arr[i].direction = 1;
				lr++;
			}
			else
			{
				rl--;
				if( lr > rl)
					arr[i].direction = 1;
				else
					arr[i].direction = -1;
				ll++;
			}
		}

		for(int i=0; i<N; i++)
		{
			if( arr[i].direction == 1)
				arr[i].distance = L-arr[i].pos+1;
			else
				arr[i].distance = arr[i].pos+1;
		}

		sort(arr,arr+N,cmp);

		for(int i=0; i<N; i++)
			cout<<arr[K-1].ID<<endl;
	}
}


