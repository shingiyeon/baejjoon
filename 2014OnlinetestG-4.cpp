#include <iostream>
#include <cstring>
using namespace std;
using std::string;

// A = 0 T = 1 C = 2 G = 3

//char** AhoCorasickTree( char** caseMarker, int m, 

int main(void)
{
	int T;
	cin>>T;
	for(int test=0; test<T; test++)
	{
		int n, m;
		cin>>n>>m;
		
		char *DNA = new char[n+1];
		char *Marker = new char[m+1];

		cin>>DNA>>Marker;
		
		char tempcaseMarker[10000][m+1];

		char **caseMarker = new char*[10000];
		for(int i=0; i<10000; i++)
		{
			caseMarker[i] = new char[m+1];
		}

		int **Trie = new int*[m];
		for(int i=0; i<m; i++)
		{
			Trie[i] = new int[4];
		}


		int tmp = 0;
		
		for(int i=0; i<m; i++)
		{
			for(int j=i; j<m; j++)
			{
				for(int k=0; k<i; k++)
				{
					caseMarker[tmp][k] = Marker[k];
				}

				int temp = j;

				for(int k=i; k<=j; k++)
				{
					caseMarker[tmp][k] = Marker[temp];
					temp--;
				}

				for(int k= j+1; k<m; k++)
				{
					caseMarker[tmp][k] = Marker[k];
				}

				caseMarker[tmp][m] = '\0';
				tmp++;
			}
		}

		int temp = 0;
		





	}

	return 0;
}
