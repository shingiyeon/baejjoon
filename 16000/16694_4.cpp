//# Author : nuclear852 ========================#
//# Solution : 25218039 ========================#
//# Time Stamp : 2021-01-13 08:54:16 ===========#
//# Problem Title : The ABCD Murderer ======#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <string>
#include <queue>
#define INF 999999999
using namespace std;

char tmp[3030005];
// int tree[1200120];
// int lazy[1200120];

// void init(int index, int start, int end) {
//     if(start == end) {
//         tree[index] = lazy[index] = INF;
//         return;
//     }
//     int mid = (start + end) / 2;
//     init(index * 2, start, mid);
//     init(index * 2 + 1, mid+1, end);
// }

// int find(int index, int start, int end, int cur) {
//     if(lazy[index] != INF) {
//         tree[index] = min(tree[index], lazy[index]);
//         if(start != end) {
//             lazy[index*2] = min(lazy[index*2], lazy[index]);
//             lazy[index*2+1] = min(lazy[index*2], lazy[index]);
//         }
//         lazy[index] = INF;
//     }

//     if(cur < start || cur > end) return INF;
//     if(start == end) return tree[index];
//     int mid = (start + end) / 2;
//     return min(find(index * 2, start, mid, cur), find(index*2+1, mid+1, end, cur));
// }

// void update(int index, int start, int end, int left, int right, int c) {
//     if(lazy[index] != INF) {
//         tree[index] = min(tree[index], lazy[index]);
//         if(start != end) {
//             lazy[index*2] = min(lazy[index*2], lazy[index]);
//             lazy[index*2+1] = min(lazy[index*2], lazy[index]);
//         }
//         lazy[index] = INF;
//     }
//     if(right < start || left > end) return;
//     if(left <= start && end <= right) {
//         tree[index] = min(tree[index], c);
//         if(start != end) {
//             lazy[index*2] = min(lazy[index*2], lazy[index]);
//             lazy[index*2+1] = min(lazy[index*2], lazy[index]);
//         }
//         return;
//     }
//     int mid = (start + end) / 2;
//     update(index, start, mid, left, right, c);
//     update(index * 2, mid + 1, end, left, right, c);
//     tree[index] = min(tree[index * 2], tree[index * 2 + 1]);
//     return;
// }

int to_num(char c) {
    return c - 'a';
}
int d[300005];
class AhoCorasick {
    public:
        int trie[300005][26];
        int fail[300005];
        int lv[300005];
        int piv;

        AhoCorasick() {
            for(int i=0; i<300005; i++) {
                for(int j=0; j<26; j++) {
                    trie[i][j] = 0;
                }
                fail[i] = lv[i] = 0;
            }
            piv = 0;
        }
        ~AhoCorasick() {
        }

        void insertWord(string w) {
            int cur = 0;
            for(int i=0; i<w.size(); i++) {
                int next = to_num(w[i]);
                if(!trie[cur][next]) trie[cur][next] = ++piv;
                cur = trie[cur][next];
            }
            lv[cur] = w.size();
        }

        void make_failFunc() {
            queue<int> q;
            q.push(0);
            while(!q.empty()) {
                int cur = q.front(); q.pop();
                for(int i=0; i<26; i++) {
                    if(!trie[cur][i]) continue;
                    int next = trie[cur][i];
                    if(cur == 0) fail[next] = 0;
                    else {
                        int f = fail[cur];
                        while(f && !trie[f][i]) {
                            f = fail[f];
                        }
                        if(trie[f][i]) f = trie[f][i];
                        fail[next] = f;
                    }
                    if(lv[fail[next]]) lv[next] = max(lv[next], lv[fail[next]]);
                    q.push(next);
                }
            }
        }
        int solve(string s) {
            int cur = 0;
            for(int i=0; i<s.size(); i++) {
                int next = to_num(s[i]);
                while(cur && !trie[cur][next]) {
                    cur = fail[cur];
                }
                if(trie[cur][next]) cur = trie[cur][next];
                if(lv[cur]) {
                    int len = lv[cur];
                    // int tmp = find(1, 0, s.size(), i+1-len) + 1;
                    // update(1, 0, s.size(), i+1, i+1, tmp);
                    // update(1, 0, s.size(), )


                    d[i + 1] = min(d[i+1], d[i+1 - len] + 1);
                    for(int j=i; j>=i+1-len; j--) {
                        if(d[j+1] < d[j]) d[j] = d[j+1];
                        else break;
                    }
                }
            }
            return d[s.size()];
        }
};

AhoCorasick* ac = new AhoCorasick();

int main() {
    for(int i=1; i<300005; i++) d[i] = 999999999;
    string A, B;
    int N; scanf("%d", &N);
    
    scanf("%s", tmp); A = tmp;
    while(N--) {
        scanf("%s", tmp); B = tmp;
        ac->insertWord(B);
    }
    ac->make_failFunc();
    int ans = ac->solve(A);
    printf("%d", ans != 999999999 ? ans : -1);
    delete ac;
}