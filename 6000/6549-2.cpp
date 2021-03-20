#include <stdio.h>
#include <vector>
#include <utility>
typedef long long ll;
using namespace std;

int a[100001];
int main(){
	while(true){
		int N;
		scanf("%d", &N);
		if(!N) return 0;
		for(int i=0; i<N; i++) scanf("%d", &a[i]);
		a[N] = 0;
		vector< pair<int, int> > s;
		long long ans = 0;
		for(int i=0; i<=N; i++){
			int index = i;
			while(s.size() && s.back().first>= a[i]){
				ans = ans < (ll)(i-s.back().second) * s.back().first? (ll)(i-s.back().second) * s.back().first : ans;
				index = s.back().second;
				s.pop_back();
			}
			pair<int, int> p(a[i], index);
			s.push_back(p);
		}
		printf("%lld\n", ans);
	}
}
