#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
struct ant{
	        int ID;
		        int pos;
};
struct data{
	        int direction;
		        int distance;
};
bool cmp(ant a, ant b)
{
		return a.pos< b.pos;
}
bool cmp2(data a, data b)
{
		return a.distance!=b.distance? a.distance<b.distance:a.direction<b.direction;
}
int main(void){
	int T;
	cin>>T;
	while(T--)
	{
		int r = 0;
		int l = 0;
		int N, L, K;
		cin>>N>>L>>K;
		ant arr[N];
		data Z[N];
		for(int i=0; i<N; i++)
		{
			scanf("%d %d",&arr[i].pos,&arr[i].ID);
			if(arr[i].ID >= 0){
				Z[i].distance = L-arr[i].pos+1;
				Z[i].direction = arr[i].ID;
				r++;
			}     
			else{
				Z[i].distance = arr[i].pos+1;
				Z[i].direction = arr[i].ID;
				l++;
			}
		}

		sort(arr,arr+N,cmp);
		sort(Z,Z+N,cmp2);

		int s = 0;
		int e = N-1;
		int t;
		for(int i=0; i<K; i++){
				if(Z[i].direction > 0)
				{
					r--;
					if( l>0){
						t=arr[e].ID;
						e--;
					}
					else{
						t=arr[s].ID;
						s++;
					}
				}
				else
				{
					l--;
					if( r>0){
						t=arr[s].ID;
						s++;
					}
					else{
						t=arr[e].ID;
						e--;
					}	   
				}
				cout<<t<<endl;
		}
		cout<<t<<endl;
	}
}

