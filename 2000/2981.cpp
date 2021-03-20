#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int arr[100];
int minus[100];
vector<int> v;
int main(){
	int N; scanf("%d",&N);
	int max = 0;
	for(int i=0; i<N; i++) scanf("%d",&arr[i]);
	for(int i=0; i<N-1; i++) minus[i] = arr[i] < arr[i+1]? arr[i+1]-arr[i] : arr[i]-arr[i+1];
	int a = minus[1], b = minus[0];
	int idx = 1;
	while(idx<N-1){
		if(b>a){int temp = b; b = a; a = temp;}
		while(a%b){int temp = a%b; a=b; b=temp;}
		a = b; idx++;
		if(idx==N-1)
			break;
		b = minus[idx];
	}
	
	for(int i=1; i*i<=b; i++){
		if(!(b%i)){
			if(i==1 || i*i==b) v.push_back(b/i);
			else {v.push_back(i); v.push_back(b/i);}
		}
	}
	sort(v.begin(), v.end());
	for(int i=0; i<v.size(); i++)
		printf("%d ", v[i]);
}
