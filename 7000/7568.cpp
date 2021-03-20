#include <stdio.h>
#include <utility>
using namespace std;
int num[50];
int main()
{
	pair<int, int> p[50];
	int N; scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d%d",&p[i].first,&p[i].second);
	}
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(i==j) continue;
			if(p[i].first<p[j].first && p[i].second<p[j].second)
				num[i]++;
		}
	}
	for(int i=0; i<N; i++){
		printf("%d ", num[i]+1);
	}
}
