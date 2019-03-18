#include <iostream>
using namespace std;

struct WhoDontKnow{
	int x;
	int y;
	int no;
};

int main(){
	int T;
	cin >> T;
	for(int test=0; test<T; test++)
	{
		int n, m;
		cin>>n>>m;
		WhoDontKnow arr[m];
		for(int i=0; i<m; i++)
			cin>>arr[i].x>>arr[i].y;

		int k[n+1];
		for(int i=0; i<=n; i++)
			k[i]=0;

		for(int i=0; i<m; i++){
			k[ arr[i].x ]++;
			k[ arr[i].y ]++;
		}
		int max=0;

		for(int i=1; i<=n; i++)
			if( k[i] > k[max])
				max = i;
		int slot = k[max]+1;
	
		cout<<"slot is "<<slot<<endl;

		bool dy[n+1][slot+1];

		for(int i=0; i<=n; i++)
			for(int j=0; j<=slot; j++)
				dy[i][j]=0;
		bool check = 0;

		for(int i=0; i<m; i++)
		{
			int tmp=1;
			while(1)
			{
				if(tmp > slot){
					for(int j=0; j<m; j++)
						arr[j].no = 0;
					check = 1;
					break;
				}

				else if( dy[ arr[i].x ][tmp] ==0 && dy[ arr[i].y][tmp] == 0)
				{
					arr[i].no = tmp;
					dy[arr[i].x][tmp]=1;
					dy[arr[i].y][tmp]=1;
					cout<<arr[i].x<<" "<<arr[i].y<<" "<<arr[i].no<<endl;
					break;
				}
				else
					tmp++;
			}
			if(check == 1)
				break;
		}

		for(int i=0; i<m; i++)
			cout<< arr[i].x<<" "<<arr[i].y<<" "<<arr[i].no<<endl;
	}
}
