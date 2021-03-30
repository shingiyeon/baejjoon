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
using namespace std;

vector< pair<int, char> > adj[505050];
string str;
vector<int> f(505050, 0);
int ans = 0;
void make_fail() {
	int j = 0;
	for(int i=1; i<str.size(); i++) {
		while(j > 0 && str[i] != str[j]) j = f[j];
		if(str[i] == str[j]) {
			f[i] = ++j; 
		}
	}
}

void dfs(int cur, int state) {
	for(auto next: adj[cur]) {
		auto idx = next.first;
		auto ch = next.second;
		int nxt_state = state;
		while(nxt_state > 0 && ch != str[nxt_state]) nxt_state = f[nxt_state - 1];
		if(ch == str[nxt_state]) {
			nxt_state++;
			if(nxt_state == str.size()) {
				ans++; nxt_state = f[nxt_state - 1];
			}
		}
		dfs(idx, nxt_state);
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
	cin >> str;
	make_fail();
	dfs(1, 0);
	cout << ans;



	

}