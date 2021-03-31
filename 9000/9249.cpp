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
#include <unordered_map>
#include <unordered_set>
using namespace std;
typedef long long ll;


string s, p;
const int BASE = 31;
const int MOD[2] = {100000007, 1000000009};

unordered_set<ll> find_hash(int start, int end, string str) {
	int mid = (start + end) / 2;
	ll h[2], b[2];
	h[0] = h[1] = str[0]; b[0] = b[1] = 1;
	unordered_set<ll> us;
	for(int i=1; i<mid; i++) {
		for(int j=0; j<=1; j++) {
			h[j] = (h[j] * BASE + str[i]) % MOD[j];
			b[j] = (b[j] * BASE) % MOD[j];
		}
	}
	us.insert(h[0] << 32 | h[1]);
	for(int i=mid; i<str.size(); i++) {
		for(int j=0; j<=1; j++) {
			h[j] = ((h[j] - str[i-mid] * b[j]) % MOD[j] + MOD[j]) % MOD[j];
			h[j] = (h[j] * BASE + str[i]) % MOD[j];
		}
		ll tmp = (h[0] << 32 | h[1]);
		us.insert(tmp);
	}
	return us;
}

int bs(int start, int end, string str, unordered_set<ll> us) {
	int mid = (start + end) / 2;
	ll h[2], b[2];
	h[0] = h[1] = str[0]; b[0] = b[1] = 1;
	for(int i=1; i<mid; i++) {
		for(int j=0; j<=1; j++) {
			h[j] = (h[j] * BASE + str[i]) % MOD[j];
			b[j] = (b[j] * BASE) % MOD[j];
		}
	}
	ll tmp = (h[0] << 32 | h[1]);
	if(us.find(tmp) != us.end()) return mid;
	for(int i=mid; i<str.size(); i++) {
		for(int j=0; j<=1; j++) {
			h[j] = ((h[j] - str[i-mid] * b[j]) % MOD[j] + MOD[j]) % MOD[j];
			h[j] = (h[j] * BASE + str[i]) % MOD[j];
		}
		ll tmp = (h[0] << 32 | h[1]);
		if(us.find(tmp) != us.end()) return i+1;
	}
	return -1;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string s, p; cin >> s >> p;
	int ans = 0;
	int start = 1, end = min(s.size(), p.size());
	string str;
	if(s.size() > p.size()) swap(s,p);
	while(start <= end) {
		auto us = find_hash(start, end, s);
		
		int mid = (start + end) / 2;
		int idx = bs(start, end, p, us);
		if(idx != -1) {
			start = mid + 1;
			str = p.substr(idx-mid, mid);
		}
		else {
			end = mid - 1;
		}
	}

	cout << str.size() << "\n";
	cout << str;
}
