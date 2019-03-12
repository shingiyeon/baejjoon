#include <stdio.h>
#include <stack>
#include <vector>
using namespace std;
int arr[100001];
bool a[200001];
stack<int> s;
vector<int> v;
int main(){
	int n; scanf("%d",&n);
	for(int i=0; i<n; i++) { scanf("%d",&arr[i]); v.push_back(i+1);}
	int idx = 0; int aidx = 0; int vidx = 0;
	while(idx<n){
		if(s.empty()){
			s.push(v[vidx++]); a[aidx++] = 1;   
		}
		else if(s.top()<v[vidx]){
			s.push(v[vidx++]); a[aidx++] = 1;
		}
		else if(s.top()>v[vidx]){
			break;
		}
		while(s.top()==arr[idx]){
			s.pop(); a[aidx++] = 0; idx++;
			if(s.empty()) break;
		}
	}
	if(idx!=n) printf("NO");
	else{
		for(int i=0; i<2*n; i++)
			printf("%s\n", a[i] ? "+" : "-");
	}
}
