#include <stdio.h>
#include <queue>
using namespace std;
queue<int> q;

int main(){
	int N; scanf("%d",&N);
	while(N--){
		char command[10]; scanf("%s",command);
		switch(command[1]){
			case 'u':
				int n; scanf("%d", &n);
				q.push(n);
				break;
			case 'r':
				printf("%d\n", !q.size()? -1: q.front());
				break;
			case 'a':
				printf("%d\n", !q.size()? -1: q.back());
				break;
			case 'o':
				printf("%d\n", !q.size()? -1: q.front());
				if(q.size()) q.pop();
				break;
			case 'm':
				printf("%d\n", q.empty());
				break;
			case 'i':
				printf("%d\n", q.size());
				break;
		}
		
	}
}
