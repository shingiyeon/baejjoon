#include <stdio.h>
#include <utility>
#include <algorithm>
using namespace std;
pair<int, int> p[5000];
int min(int a, int b){return a<b? a:b;}
int main(){
	int sum = 0;
	int N; scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d%d",&p[i].first,&p[i].second);
	sort(p, p+N);
	for(int i=0; i<N; i++){
		int MIN = 100001;
		for(int j=i-1; j>=0; j--)
			if(p[i].second == p[j].second) MIN = min(MIN, p[i].first - p[j].first);
		for(int j=i+1; j<N; j++)
			if(p[i].second == p[j].second) MIN = min(MIN, p[j].first - p[i].first);
		if(MIN==100001) continue;
		sum += MIN;
	}
	printf("%d", sum);
}
