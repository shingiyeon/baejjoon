#include <stdio.h>
#include <utility>
#include <math.h>
#define MAX 9876543212345LL
using namespace std;
typedef long long ll;
pair<int, int> p[20];
int N;
ll tx, ty;

ll dy[1<<20];

ll min(ll x, ll y){
	return x < y? x : y;
}
ll bf(ll x, ll y, int num, int state){
	if(dy[state]!=-1) return dy[state];
	ll MIN = MAX;
	if(num == (N/2))
		return dy[state] = (tx-2*x)*(tx-2*x) + (ty-2*y)*(ty-2*y);
	
	for(int i=0; i<N; i++){
		int temp = 1<<i;
		if( (state & temp) == 0)
			MIN = min(MIN, bf(x+p[i].first, y+p[i].second, num+1, state | temp));
	}
	return dy[state] = MIN;
}

int main(){
	int T; scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		int tx = 0, ty = 0;
		for(int i=0; i<1048576; i++) dy[i] = -1;
		for(int i=0; i<N; i++) {
			scanf("%d%d",&p[i].first,&p[i].second);
			tx += (ll)p[i].first; ty += (ll)p[i].second;
		}
		ll ansll = bf(0,0,0,0);
		printf("%.6lf\n", sqrt(ansll));
	}
}
