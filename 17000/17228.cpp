#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <functional>
#include <math.h>
#include <utility>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
using namespace std;
typedef long long ll;
const int BASE = 31;
const int MOD[2] = {100000007, 1000000009};
vector<pair<int, char> > adj[505050];
string s;

ll h[2], b[2];
vector<ll> tmp_hash;
vector<char> stk;
ll ha;
ll ans;

void make_hash() {	
	h[0] = h[1] = s[0];
	b[0] = b[1] = 1;

	for(int i=1; i<s.size(); i++) {
		for(int j=0; j<2; j++) {
			h[j] = (h[j] * BASE + s[i]) % MOD[j];
			b[j] = (b[j] * BASE) % MOD[j];
		}
	}
	ha = (h[0] << 32 | h[1]);
}

void dfs(int idx, char cur) {
	if(stk.size() > s.size()) {
		for(int j=0; j<2; j++) {
			tmp_hash[j] = ( (tmp_hash[j] - stk[stk.size() - s.size() - 1] * b[j] ) % MOD[j] + MOD[j] ) % MOD[j];
			tmp_hash[j] = ( (tmp_hash[j] * BASE + cur) % MOD[j]);
		}
		ll tmp_ha = (tmp_hash[0] << 32 | tmp_hash[1]);
		//cout << tmp_ha << " " << ha << "\n";
		if(ha == tmp_ha) ans++;
	}
	else {
		if(cur != 0) {
			for(int j=0; j<2; j++) {
				tmp_hash[j] = (tmp_hash[j] * BASE + cur) % MOD[j];
			}
		}
	}

	for(auto next: adj[idx]) {
		ll th0 = tmp_hash[0]; ll th1 = tmp_hash[1];
		stk.push_back(next.second);
		dfs(next.first, next.second);
		stk.pop_back();
		tmp_hash[0] = th0; tmp_hash[1] = th1;
	}
}



int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int N; cin >> N;
	for(int i=1; i<=N-1; i++) {
		int a, b; char c;
		cin >> a >> b >> c;
		adj[a].push_back({b, c});
	}
	cin >> s;
	make_hash();
	tmp_hash.resize(2, 0);
	stk.push_back(0);
	dfs(1, 0);
	cout << ans;
}