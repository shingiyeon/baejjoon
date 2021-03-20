#include <stdio.h>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;
ll a[1001];
ll b[1001];
vector<ll> va;
vector<ll> vb;
ll sum;
int n, m;
int main(){
	ll T; scanf("%lld", &T);
	ll temp;
	scanf("%d", &n); sum = 0;
	for(int i=1; i<=n; i++){
		scanf("%lld", &temp);
		sum += temp;
		a[i] = sum;
	}
	scanf("%d", &m); sum = 0;
	for(int i=1; i<=m; i++){
		scanf("%lld", &temp);
		sum += temp;
		b[i] = sum;
	}
	for(int i=0; i<n; i++){
		for(int j=i+1; j<=n; j++){
			va.push_back(a[j]-a[i]);
		}
	}
	for(int i=0; i<m; i++){
		for(int j=i+1; j<=m; j++){
			vb.push_back(b[j]-b[i]);
		}
	}
	sort(va.begin(), va.end());
	sort(vb.begin(), vb.end());
	ll ans = 0;
	for(int i=0; i<va.size(); i++){
		if(binary_search(vb.begin(), vb.end(), T-va[i]))
			ans += upper_bound(vb.begin(), vb.end(), T-va[i]) - lower_bound(vb.begin(), vb.end(), T-va[i]);
	}
	printf("%lld", ans);
	
}
