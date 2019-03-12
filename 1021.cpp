#include <stdio.h>
#include <vector>

using namespace std;

vector<int> v;

void left(){
	int a = v[v.size()-1];
	v.pop_back();
	v.insert(v.begin(), a);
}

void right(){
	int a = v[0];
	v.erase(v.begin());
	v.push_back(a);
}

int pop(){
	int a = v[0];
	v.erase(v.begin());
	return a;
}

int main(){
	int N, K;
	int arr[50];
	int ans = 0;
	scanf("%d%d",&N,&K);
	for(int i=1; i<=N; i++) v.push_back(i);
	for(int i=0; i<K; i++) scanf("%d",&arr[i]);
	for(int i=0; i<K; i++){
		int idx;
		for(int j=0; j<v.size(); j++){
			if(v[j] == arr[i]){
				idx = j;
			}
		}
		if(idx <= v.size()/2){
			for(int j=0; j<idx; j++){
				right(); ans++;
			}
			pop();
		}
		else{
			int size = v.size();
			for(int j=idx+1; j<=size; j++){
				left(); ans++;
			}
			pop();
		}
	}
	printf("%d",ans);
}
