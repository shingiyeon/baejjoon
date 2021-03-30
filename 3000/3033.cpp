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
#include <unordered_set>
using namespace std;
typedef long long ll;
string str;

const int BASE = 31;
const ll MOD[2] = {100000007, 1000000009};
int ans = 0;
bool bs(int start, int end) {
	unordered_set<ll> s;
	int max_val = 0;
	int mid = (start + end) / 2;

	ll h[2], b[2];
	h[0] = h[1] = str[0];
	b[0] = b[1] = 1;
	
	for(int i=1; i<mid; i++) {
		for(int j=0; j<=1; j++) {
			h[j] = (h[j] * BASE + str[i] + MOD[j]) % MOD[j];
			b[j] = (b[j] * BASE) % MOD[j];
		}
	}
	s.insert(h[0] << 32 | h[1]);

	for(int i = mid; i < str.size(); i++) {
		for(int j=0; j<=1; j++) {
			h[j] = ( (h[j] - str[i-mid] * b[j] ) % MOD[j]  + MOD[j]) % MOD[j];
			h[j] = (h[j] * BASE + str[i]) % MOD[j];
		}
		ll tmp = h[0] << 32 | h[1];
		if(s.find(tmp) != s.end()) {
			ans = max(ans, mid);
			return true;
		}
		s.insert(tmp);
	}
	return false;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int L; cin >> L;
	cin >> str;
	int s = 1, e = L;
	while(s <= e) {
		bool flag = bs(s, e);
		if(flag) {
			s = (s + e) / 2 + 1;
		}
		else {
			e = (s + e) / 2 - 1;
		}
	}
	cout << ans;

}