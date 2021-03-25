//# Author : nuclear852 ========================#
//# Solution : 11142797 ========================#
//# Time Stamp : 2018-12-29 16:12:42 ===========#
//# Problem Title : 스택 =====================#
//# Language : C++98 ===========================#

#include <stdio.h>
#include <stack>

using namespace std;

int main(){
	stack<int> s;
	char cmd[10];
	int N;
	scanf("%d", &N);
	
	while(N--){
		scanf("%s", cmd);
		switch(cmd[0]){
			case 'p':
				if(cmd[1] == 'u'){
					int n;
					scanf("%d", &n);
					s.push(n);
				}
				else
					if(s.empty()==0){
						printf("%d\n", s.top());
						s.pop();
					}
					else
						printf("-1\n");
				break;
			case 't':
				if(s.empty() == 0)
					printf("%d\n", s.top());
				else
					printf("-1\n");
				break;
			case 's':
				printf("%d\n", s.size());
				break;
			case 'e':
				printf("%d\n", s.empty());
				break;
		}
	}
}