#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> a;
bool cmp(string a, string b){
	return a.length() == b.length() ? a.compare(b) < 0 : a.length() < b.length(); 
}
int main(){
	string temp;
	int N; scanf("%d", &N);
	for(int i=0; i<N; i++) {cin>>temp; a.push_back(temp);}
	sort(a.begin(), a.end(),cmp);
	temp = "A";
	for(int i=0; i<N; i++) {
		if(a[i].compare(temp)){
			cout<<a[i]<<endl;
			temp = a[i];
		}
	}
}
