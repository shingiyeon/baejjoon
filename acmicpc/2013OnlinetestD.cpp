#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
	int T;
	cin>>T;
	int arr[1000000];
	while(T--){
		int K;
		scanf("%d\n",&K);
		int s, e;
		s=0; e=-1;
		char c;
		for(int i=0; i<K; i++)
		{
			int temp;
			scanf("%c ", &c);
			scanf("%d\n",&temp);
			if(c=='I'){
				e++;
				arr[e]=temp;
				sort(arr+s,arr+e+1);
			}
			else{
				if( e >= s)
				{
					if(temp == -1)
						s++;
					else
						e--;
				}
			}
		}
		if( e>=s)
			cout<<arr[e]<<" "<<arr[s]<<endl;
		else
			cout<<"EMPTY"<<endl;
	}
}
