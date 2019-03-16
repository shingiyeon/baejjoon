//Mutation
#include <iostream>
#include <cstring>
using namespace std;
using std::string;

int main(void)
{
	int T;
	cin>>T;

	for(int test=0; test<T; test++)
	{
		int n, m;

		cin>>n>>m;

		char DNA[n];
		char Marker[m];
		char caseMarker[10000][m];
		char realcase[10000][m];
		int IntDNA[n];

		for(int i=0; i<n; i++)
		{
			cin>>DNA[i];
			if(DNA[i] == 'A')
				IntDNA[i] = 1;
			if(DNA[i] == 'G')
				IntDNA[i] = 2;
			if(DNA[i] == 'C')
				IntDNA[i] = 3;
			if(DNA[i] == 'T')
				IntDNA[i] = 4;
		}


		for(int i=0; i<m; i++)
			cin>>Marker[i];


		int tmp = 0;
		for(int i=0; i<m; i++)
		{
			for(int j=i; j<m; j++)
			{
				for(int k = 0; k<i; k++)
				{
					caseMarker[tmp][k] = Marker[k];
				}

				int temp=j;

				for(int k= i; k<=j; k++)
				{
					
					caseMarker[tmp][k] = Marker[temp];
					temp--;
				}

				for(int k= j+1; k<m; k++)
				{
					caseMarker[tmp][k] = Marker[k];
				}

				tmp++;
			}
		}

		
		for(int i=0; i<tmp; i++)
		{ 
			
			cout<<caseMarker[i];
			/*
			for(int j=0; j<m; j++)
			{
				cout<<caseMarker[i][j];
			}*/
			cout<<endl;
		}

		int temp =0;

		for(int i=0; i<tmp; i++)
		{
			bool ithas = 0;

			for(int j=0; j<i; j++)
			{
				if( strcmp(caseMarker[i], realcase[j]) == 0 )
				{
					ithas = 1;
					break;
				}
			}

			if(ithas == 0)
			{
				strcpy( realcase[temp], caseMarker[i]);
				temp++;
			}
		}

		for(int i=0; i<temp; i++)
		{
			cout<<realcase[i]<<endl;
		}




		
	}

	return 0;
}






