#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <functional>
#include <queue>
#include <stack>
#include <string>
using namespace std;
typedef long long ll;
#define MOD 1000000009

ll dp[101][101][26];
int L;
string S;

class KMP {
    public:

    static vector<int> makeFailFunc(string s) {
        vector<int> f(s.length(), 0);
        int j = 0;
        for(int i = 1; i < s.length(); i++) {
            while(j > 0 && s[i] != s[j]) j = f[j-1];
            if(s[i] == s[j]) f[i] = ++j;
        }
        return f;
    }
};

ll d(int i, int j, int k, vector<int> f) {
    if(dp[i][j][k] != -1) return dp[i][j][k];
    if(i == L) {
        if(j == S.length()) return dp[i][j][k] = 1;
        else return dp[i][j][k] = 0;
    }
    ll cur_val = 0;
    for(int c='a'; c<='z'; c++) {
        int nxt = j;
        if(nxt == S.length()) {
            cur_val = (cur_val + d(i+1,j,c-'a',f)) % MOD;
            continue;
        }

        while(nxt > 0 && S[nxt] != c) {
            nxt = f[nxt - 1];
        } 

        if(S[nxt] == c) {
            cur_val = cur_val + d(i+1, nxt+1, c-'a', f);
        } else {
            cur_val = cur_val + d(i+1, 0, c-'a', f);
        }
        cur_val %= MOD;
    }
    return dp[i][j][k] = cur_val;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    for(int i=0; i<=100; i++) {
        for(int j=0; j<=100; j++) {
            for(int k=0; k<=25; k++) {
                dp[i][j][k] = -1;
            }
        }
    }

    cin >> L >> S;
    vector<int> f = KMP::makeFailFunc(S);
    // for(auto val: f) {
    //     cout << val << " ";
    // }
    // cout << "\n";
    cout << d(0, 0, 0, f);
}