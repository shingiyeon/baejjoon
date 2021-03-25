//# Author : nuclear852 ========================#
//# Solution : 14967641 ========================#
//# Time Stamp : 2019-09-04 20:41:25 ===========#
//# Problem Title : 전깃줄 ====================#
//# Language : C++98 ===========================#

#include <stdio.h>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> p;

vector<p> v;

int dy[100];
int MAX = 1;
int main() {
	int N;
	p temp;
	scanf("%d" , &N);
	for(int i=0; i<N; i++) {
		scanf("%d %d", &temp.first, &temp.second);
		v.push_back(temp);
		dy[i] = 1;
	}
	sort(v.begin(), v.end());
	
	for(int i=0; i<N; i++){
		for(int j=0; j<i; j++){
			if(v[i].second > v[j].second){
				dy[i] = max(dy[i], dy[j]+1);
				MAX = max(MAX, dy[i]);
			}
		}
	}
	printf("%d", N-MAX);
}