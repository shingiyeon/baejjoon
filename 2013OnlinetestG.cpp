#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;
using std::string;

int main(void)
{
	int testcase;
	cin>>testcase;

	while(testcase--)
	{
		int state[101][27];

		for(int i=0; i<101; i++)
		{
			for(int j=0; j<27; j++)
			{
				state[i][j] = -1;
			}
		}

		string p;

		cin>>p;

		vector<int> childnode[101];
		stack<int> startpoint;
		int standardpoint=0;
		int blankstate;
		int maxcurrentstate = 0;

		for(int i=0; i<p.size(); i++)
		{
			
			if( p[i] != '(' && p[i] != ')' && p[i] != '|' )
			{
				maxcurrentstate++;

				stack <int> temp;
				
				temp.push(standardpoint);

				if( p[i] == '_')
					p[i] = 26;

				while(!temp.empty())
				{
					int k = temp.top();
					temp.pop();


					if( childnode[k].empty() ) {
						state[k][ p[i]-'A' ] = maxcurrentstate;
						childnode[k].push_back(maxcurrentstate);
					}
					else{
						for(int j=0; j<childnode[k].size(); j++)
							temp.push( childnode[k].at(j));
					}
				}

				standardpoint = maxcurrentstate;

				/*
				if( p[i] != '_')
					state[ standardpoint ][ p[i]-'A'] = maxcurrentstate;
				else{
					state[ standardpoint][26] = maxcurrentstate;
					blankstate = maxcurrentstate;
					}

					childnode[standardpoint].push_back(maxcurrentstate);
					standardpoint = maxcurrentstate;
				*/
			}
			
			else if( p[i] == '(')
			{
				startpoint.push(standardpoint);
			}
	
			else if( p[i] == '|')
			{
				standardpoint = startpoint.top();
			}
	
			else if( p[i] == ')')
			{
				startpoint.pop();
			}
		}

		for(int i=0; i<101; i++)
		{
			for(int j=0; j<childnode[i].size(); j++)
			{
				cout<<i<<" "<<childnode[i].at(j)<<endl;
			}
		}
	}
	return 0;
}

			

		


