#include <stdio.h>
#include <vector>
using namespace std;
typedef long long ll;
vector<ll> v;
bool find(ll num, int idx){
	if(idx<0) return 0;
	if(v[idx] > num) return find(num, idx-1);
	if(v[idx] == num) return 1;
	return find(num-v[idx], idx-1) | find(num, idx-1);
}
int main(){
	ll N; scanf("%lld", &N);
	v.push_back(1);
	ll i = 1; int n = 2; 
	while(N/i){
		v.push_back(i);
		i = i * n++;
	}
	printf("%s", find(N,v.size()-1) ? "YES": "NO");
}
	
