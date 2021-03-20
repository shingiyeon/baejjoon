#include <iostream>
#include <map>
#include <stdio.h>
using namespace std;

int main(void)
{
	int n;
	cin>>n;

	while(n--)
	{
		int K;
		scanf("%d\n",&K);
		char c;
		
		map<long long, int> queue;

		for(int i=0; i<K; i++)
		{
			int temp;
			scanf("%c ", &c);
			scanf("%d\n", &temp);

			if( c == 'I'){
				if( queue.find(temp) == queue.end() )
					queue[temp] = 0;
				queue[temp]++;
			}

			else{
			
				if(queue.size() != 0)
				{
					if(temp == 1)
					{
						int max = (queue.end()-1)->first;
						if( queue[ max ] >= 2 )
							queue[max]--;
						else
							queue.erase(--queue.end());
					}

					else
					{
						int min = queue.start()->first;
						if( queue[ min ] >= 2 )
							queue[ min ]--;
						else
							queue.erase(queue.begin());
					}
				}
			}
		}

		if(queue.size() == 0)
			cout<<"EMPTY"<<endl;
		else
			cout<< (queue.end()-1)->first <<" "<<queue.begin()->first<<endl;
	}
	return 0;
}

