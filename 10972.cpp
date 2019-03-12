#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int min(int a, int b){return a<b?a:b;}
int main(){
	vector<int> v;
	int N; int arr[10000];
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d",&arr[i]);
	int pos = -1;
	for(int i=0; i<N-1; i++){
		if(arr[i]<arr[i+1])
			pos = i; 
	}
	int minv = 10001;
	for(int i=pos; i<N; i++){
		if(arr[i]>arr[pos]) minv=min(minv,arr[i]); 
	}
	if(pos==-1){
		printf("-1");
		return 0;
	}
	for(int i=0; i<N; i++){
		if(i<pos) printf("%d ", arr[i]);
		else if(i == pos) printf("%d ", minv);
		else if(i>pos && arr[i] != minv) v.push_back(arr[i]);
	}
	v.push_back(arr[pos]);
	sort(v.begin(), v.end());
	for(int i=0; i<v.size(); i++)
		printf("%d ", v[i]);
}
