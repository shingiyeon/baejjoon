#include <iostream>
using namespace std;
long long min(long long a, long long b)
{
	if(a>b)
		return b;
	else
		return a;
}
struct inf{
	long long bus;
	long long tra;
};
int main(void){
	int T;
	cin>>T;
	for(int test=0; test<T;test++)
	{
		long long ans=0;
		int n;
		cin>>n;
		inf index[n+1];
		
		for(int i=1; i<=n; i++)
			cin>>index[i].bus>>index[i].tra;

		long long day[n+1];
		long long train[n+1][4];
		day[0]=0;
		train[0][0]=0;
		train[0][1]=0;
		train[0][2]=0;
		train[0][3]=0;
		long long temp;
		
		for(int i=1; i<=n; i++)
		{
			train[i][0] = min( train[i-1][0], min( train[i-1][1], min( train[i-1][2], train[i-1][3]))) + index[i].tra*2;
			train[i][1] = min( train[i-1][0], min( train[i-1][1], min( train[i-1][2], train[i-1][3]))) + 6;
			if(i<=6)
				train[i][2] = 36;
			else
				train[i][2] = min( train[i-7][0], min( train[i-7][1], min( train[i-7][2], train[i-7][3]))) + 36;
			if(i<=29)
				train[i][3] = 90;
			else
				train[i][3] = min( train[i-30][0] , min( train[i-30][1], min( train[i-30][2], train[i-30][3]))) + 90;
			
			temp = min( train[i][0], min( train[i][1], min(train[i][2], train[i][3])));
			long long tmp1 = min ( train[i-7][0], min( train[i-7][1], min( train[i-7][2], train[i-7][3])));
			long long tmp2 = min ( train[i-30][0], min ( train[i-30][1], min ( train[i-30][2], train[i-30][3])));

			day[i] = min( day[i-1]+6 , day[i-1]+ index[i].bus + index[i].tra*2);// 2*(train[i]-train[i-1]

		//	cout<<"check day[i]: "<<day[i]<<endl;
			day[i] = min( day[i], day[i-1] + 3 + index[i].tra * 2);
		//	cout<<"check day[i]: "<<day[i]<<endl;
			if(i>=7)
				day[i]= min( day[i], min(day[i-7]+36, day[i-7]+temp-tmp1+18));
			else
				day[i] = min(day[i], 36);
		//	cout<<"Check day[i]: "<<day[i]<<endl; 
			if(i>=30)
				day[i]=min(day[i], min(day[i-30]+90, day[i-30]+temp-tmp2+45) );
			else
				day[i] = min(day[i], 90);
		//	cout<<"check day[i]: "<<day[i]<<endl;

		//	cout<<i<<" train"<<temp<<" day"<<day[i]<<endl;
		}
		cout<<day[n]<<endl;
	}
}

