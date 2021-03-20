#include <iostream>
#include <stdlib.h>
#include <cstring>
using std::string;
using namespace std;

static int   cmpstringp(const void *p1, const void *p2)
   {
		               /* The actual arguments to this function are "pointers to
				*               pointers to char", but strcmp(3) arguments are "pointers
				*                             to char", hence the following cast plus dereference */

                 return strcmp(* (char * const *) p1, * (char * const *) p2);
}


int main(void)
{
	int T;
	cin >>T;
	for(int test=0; test<T; test++)
	{
		int n,m;
		cin>>n>>m;

		char DNA[n+1];
		char tempDNA[n+1];
		char Marker[m+1];
		char tempcaseMarker[10000][m+1];



	//	char caseMarker[10000][m+1];
	//
	//
		char** caseMarker = new char*[10000];
		for(int i=0; i<10000; i++)
		{
			caseMarker[i] = new char[m+1];
		}

//		cin>>DNA>>Marker;
		//
		//
		for(int i=0; i<n; i++)
		{
			int temp;
			temp=rand()%4;
			switch(temp){
				case 0:
					DNA[i]='A';
					break;
				case 1:
			                 DNA[i]='T';
		                            break;
				case 2:
					DNA[i]='C';
					break;
				case 3:
					DNA[i]='G';
				
				         break;
			}
		}

		DNA[n] = '\0';

		for(int i=0; i<m; i++)
    		 {
	                         int temp;
		                 temp=rand()%4;
		                  switch(temp){
		                  case 0:
		                                    Marker[i]='A';
		                                         break;
		                   case 1:
		                                   Marker[i]='T';
		                                           break;
		                    case 2:
		                                   Marker[i]='C';
		                                    break;
		                    case 3:
		                                    Marker[i]='G';
                                  break;
	}	
		}     
		Marker[m]='\0';


//		cout<<DNA<<endl;
//		cout<<Marker<<endl;

		


		int tmp = 0;

		for(int i=0; i<m; i++)
		{
			for(int j=i; j<m; j++)
			{
				for(int k = 0; k<i; k++)
				{
					tempcaseMarker[tmp][k] = Marker[k];
				}

				int temp = j;

				for(int k= i; k<=j; k++)
				{
					tempcaseMarker[tmp][k] = Marker[temp];
					temp--;
				}

				for(int k= j+1; k<m; k++)
				{
					tempcaseMarker[tmp][k] = Marker[k];
				}

				tempcaseMarker[tmp][m] = '\0';

				tmp++;
			}
		}
		
		int temp=0;

		for(int i=0; i<tmp; i++)
		{
			bool ithas = 0;
			for(int j=0; j<temp; j++)
			{
				if( strcmp( caseMarker[j], tempcaseMarker[i])==0)
				{
					ithas = 1;
					break;
				}
			}

			if(ithas == 0)
			{
				strcpy( caseMarker[temp], tempcaseMarker[i]);
				temp++;
			}
		}

	//	qsort( caseMarker, temp, sizeof(char *), cmpstringp);

	//	char** case2Marker = new char*[temp];
		
//		for(int i=0; i<temp; i++)
//		{
			/*case2Marker[i] = new char[ m/5 + 2];
			strcpy( case2Marker[i], caseMarker[i]);
			case2Marker[i][m/5 + 1] = '\0';*/
//			caseMarker[i][m/5] = '\0';
//		}
/*	
		cout<<DNA<<endl;
*/	//	cout<<temp<<endl;
/*
		for(int i = 0; i<temp; i++)
		{
			cout<<caseMarker[i]<<endl;
			cout<<case2Marker[i]<<endl;
		}
*/
//		int ans=0;
//		char *p;
//		char *r;
//		char *temp2DNA = new char[n+1];
//		char *temp3DNA = temp2DNA;
//		strcpy(temp2DNA, DNA);
//		for(int i=0; i<temp; i++)
//		{

//			p=0;
//			temp2DNA = temp3DNA;
	//		strcpy(temp2DNA, DNA);	
			//cout<<i<<" "<<tempDNA<<" "<<caseMarker[i]<<endl;

//			while( strstr( temp2DNA, caseMarker[i]) !=NULL)
//			{
//				r = strstr(temp2DNA, case2Marker[i]);
//				p = strstr(temp2DNA, caseMarker[i]);
//				if(p!=NULL)
//				{
					
			//		cout<<tempDNA-p<<endl;
//					ans++;
//					temp2DNA =  p+1;
//				}
			/*	else
				{
					temp2DNA = r+1;
				}*/
//			}
//		}

//		cout<<ans<<endl; 
	}
	return 0;
}
