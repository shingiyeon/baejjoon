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
#define MOD 1000000009LL


class AhoCorasick {
    private:
        ll dp[51][64][400];
        int trie[400][26];
        int fail[400];
        int comp[400];
        int idx;
        int cIdx;
    
    public:
        AhoCorasick() {
            for(int i=0; i<=50; i++) {
                for(int j=0; j<64; j++) {
                    for(int k=0; k<400; k++) {
                        dp[i][j][k] = -1;
                    }
                }
            }

            for(int i=0; i<400; i++) {
                for(int j=0; j<26; j++) {
                    trie[i][j] = 0;
                }
                comp[i] = 0;
                fail[i] = 0;
                idx = 0;
                cIdx = 1;
            }
        }

        static int to_num(char c) {
            return c - 'a';
        }

        void insert(string str) {
            int cur = 0;
            for(int i=0; i<str.size(); i++) {
                int path = to_num(str[i]);
                if(!trie[cur][path]) trie[cur][path] = ++idx;
                cur = trie[cur][path];
            }
            comp[cur] = mergeCidx(0, cIdx++);
            return;
        }

        void make_failFunc() {
            queue<int> q; q.push(0);
            while(!q.empty()) {
                int cur = q.front(); q.pop();
                for(int path=0; path<26; path++) {
                    if(!trie[cur][path]) continue;
                    int next = trie[cur][path];
                    if(!cur) fail[next] = 0;
                    else {
                        int f = fail[cur];
                        while(f && !trie[f][path]) f = fail[f];
                        if(trie[f][path]) f = trie[f][path];
                        fail[next] = f;
                    }
                    if(comp[fail[next]]) comp[next] = comp[next] | comp[fail[next]];
                    q.push(next);
                }
            }
        }

        int getAmount(int cmp) {
            int amount = 0;
            while(cmp) {
                amount += (cmp % 2);
                cmp /= 2;
            }
            return amount;
        }

        int mergeCidx(int cmp, int compIdx) {
            int tmp = 1;
            for(int i=0; i<(compIdx - 1); i++) {
                tmp *= 2;
            }
            return cmp | tmp;
        }

        ll d(int idx, int cmp, int cur, int C, int L) {
            // cout << idx << " " << cmp << " " << cur << " " << "\n";
            if(dp[idx][cmp][cur] != -1) {
                // cout << idx << " " << cmp << " " << cur << " " << dp[idx][cmp][cur] << "\n";    
                return dp[idx][cmp][cur];
            }

            if(idx == L && getAmount(cmp) == C) return 1;
            else if(idx == L) return 0;
            if(getAmount(cmp) > C) return 0;
            ll value = 0;
            for(int path=0; path<26; path++) {
                int next = cur;
                while(next && !trie[next][path]) next = fail[next];
                if(trie[next][path]) next = trie[next][path];
                if(comp[next]) {
                    value += d(idx + 1, cmp | comp[next], next, C, L);
                } else {
                    value += d(idx + 1, cmp, next, C, L);
                }
                value = value % MOD;
            }
            dp[idx][cmp][cur] = value;
            return dp[idx][cmp][cur];
        }

};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N, C, L;
    AhoCorasick *ac = new AhoCorasick();
    cin >> N >> C >> L;
    string s;
    
    while(N--) {
        cin >> s;
        ac->insert(s);
    }
    ac->make_failFunc();
    cout << ac->d(0, 0, 0, C, L);


}