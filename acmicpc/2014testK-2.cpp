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
	for(int test=0; test<T; test++)
	{
		long long ans = 0;
		int n;
		cin>>n;
		inf index[n+1];

		for(int i=1; i<=n; i++)
			cin>>index[i].bus>>index[i].tra;
		long long day[n+1];
		long long train[n+1];
		day[0] = 0;
		train[0] = 0;
		
		for(int i=1; i<=n; i++)
		{
			train[i] = min( train[i-1]+6, train[i-1] + 2*index[i].tra);
			if(i>=7)
				train[i] = min(train[i] , train[i-7]+36);
			else
				train[i] = min(train[i] , 36);
			if(i>=30)
				train[i] = min(train[i] , train[i-30]+90);
			else
				train[i] = min(train[i], 90);
		
			day[i] = min( day[i-1] + 6, day[i-1] + 3 +train[i] - train[i-1]);
			day[i] = min( day[i], day[i-1] + index[i].bus + index[i].tra * 2);

			if(i>=7)
				day[i] = min(day[i], min(day[i-7] + 36 , day[i-1] + train[i] - train[i-7] + 18));
			else
				day[i] = min(day[i], 36);
			if(i>=30)
				day[i] = min( day[i], min( day[i-30] + 90, day[i-30] + train[i] - train[i-30] + 45));
			else
				day[i] = min(day[i] , 90);

			cout<<"i : "<<i<<" train : "<<train[i]<<" day : "<<day[i]<<endl;
		}

		cout<<day[n]<<endl;
	}
}
