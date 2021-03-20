#include <stdio.h>
#include <stack>
using namespace std;
stack<int> st;
int arr[10000];

void search(int s, int e){
	if(s>e) return;
	st.push(arr[s]);
	int pivot;
	for(pivot=s+1; pivot<=e; pivot++){
		if(arr[s]<arr[pivot]) break;
	}
	search(pivot, e);
	search(s+1, pivot-1);
	return;
}

int main(){
	int i = 0;
	while(scanf("%d", &arr[i])!=EOF){i++;if(i==9)break;}
	search(0,i-1);
	while(!st.empty()){
		printf("%d\n", st.top());
		st.pop();
	}
	
}


