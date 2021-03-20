#include <vector>
#include <stdio.h>
using namespace std;

char command[100005];
short arr[100005];

int main(){
	int T; scanf("%d",&T);
	while(T--){
		bool pos = 1;
		vector<int> v;
		scanf("%s", command);
		int N; scanf("%d",&N); int temp;
		getchar(); getchar();
		for(int i=0; i<N-1; i++){
			scanf("%d",&arr[i]); getchar(); 
		}
		if(N-1>=0)
			scanf("%d",&arr[N-1]);
		getchar();
		
		int start = 0; int end = N-1;
		
		int dir = 1;
		for(int i=0; command[i]!='\0'; i++){
			if(command[i]=='R') dir *= -1;
			else{
				if(start > end) { pos = 0; break;}
				else if(dir == 1) start+=1;
				else end-=1;
			}
		}
		if(!pos) printf("error\n");
		else{
			printf("[");
			if(dir==1&&start<=end){
				for(int i=start; i<=end-1; i++)
					printf("%d,",arr[i]);
				printf("%d", arr[end]);
			}
			else if(dir==-1&&start<=end){
				for(int i=end; i>start; i--)
					printf("%d,", arr[i]);
				printf("%d", arr[start]);
			}
			printf("]\n");
		}
	}
}
