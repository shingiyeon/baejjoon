#include <iostream>
using namespace std;
int arr[500];
int DY[500][500];
int dy(int i, int j)
{
	if(j<=i){
		DY[i][j] = 0;
		return 0;
	}
	if(j-i == 1){
		DY[i][j] = arr[j]+arr[i];
		return arr[j]+arr[i];
	}

	if( DY[i][j] != -1)
		return DY[i][j];
	else
	{
		int min = 1000000000;
		int plus = 0;
		for(int s=i; s<=j; s++)
			plus = plus + arr[s];
		for(int s=i; s<j; s++)
		{
			int temp = plus+dy(i,s)+dy(s+1,j);
			if(temp < min)
				min = temp;
		}
		DY[i][j] = min;
		return DY[i][j];
	}
}
int main(void){
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		for(int i=0; i<N; i++)
			cin>>arr[i];
		for(int i=0; i<N; i++)
			for(int j=i; j<N; j++)
				DY[i][j]=-1;

		cout<<dy(0,N-1)<<endl;
	}
}

