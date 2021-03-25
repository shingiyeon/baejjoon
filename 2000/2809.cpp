//# Author : nuclear852 ========================#
//# Solution : 25293746 ========================#
//# Time Stamp : 2021-01-15 11:06:37 ===========#
//# Problem Title : 아스키 거리 =================#
//# Language : C++17 ===========================#

#include <iostream>
#include <string.h>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define MAX 100001
 
int N, M;
int mark[300001], chk[300001];
string str2;
char str[300002];
 
int isexist(int& exist, int ch) { //현재 문자가 존재하는지
    return (exist & (1 << (25-ch)));
}
 
int whatch(int& exist, int ch) { //ch가 몇번째에 존재하는지
    int cnt = 0;
    for (int i = 0; i < ch; ++i) {
        if (exist & (1 << (25 - i))) cnt++;
    }
    return cnt;
}
 
int nthch(int& exist, int n) {  //n번째 문자가 뭐인지
    int cnt = 0;
    for (int i = 0; i < 26; ++i) {
        if (exist & (1 << (25 - i))) {
            if (cnt == n) return i;
            cnt++;
        }
    }
    return -1;
}
 
struct Trie {
    vector<Trie*> next;
    Trie* fail;
    int output;
    int exist;
    Trie() {
        fail = nullptr;
        output = exist = 0;
    }
    ~Trie() {
        for (int i = 0; i < next.size(); ++i) {
            delete next[i];
        }
    }
 
    void insert(const char* key, int len) {
        if (*key == '\0') {
            if (output < len) {
                output = len;
            }
        }
        else {
            int cur = *key - 'a';
            int n = whatch(exist, cur);
            if (!isexist(exist, cur)) {
                exist |= (1 << (25 - cur));
                next.insert(next.begin() + n, new Trie());
            }
            next[n]->insert(key + 1, len);
        }
    }
};
 
 
int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
 
    //freopen("poplocavanje.in.3", "r", stdin);
    Trie* root = new Trie();
 
    cin >> N;
    cin >> str;
    
 
    cin >> M;
    for (int i = 0; i < M; ++i) {
        cin >> str2;
        if (str2.length() > N) continue;
        root->insert(&str2[0], str2.length());
    }
 
    queue<Trie*> q;
    root->fail = root;
    q.push(root);
    while (!q.empty()) {
        Trie* curr = q.front(); q.pop();
 
        for (int i = 0; i < curr->next.size(); ++i) {
            Trie* next = curr->next[i];
 
            if (curr == root) next->fail = root;
            else {
                int nthCh = nthch(curr->exist, i); //curr에서 i번째가 어떤 문자인지
                Trie* desc = curr->fail;
                //desc에 nthCh가 있을 때까지
                while (desc != root && !isexist(desc->exist, nthCh))
                    desc = desc->fail;
 
                //desc에 nthCh가 존재하는 경우
                //desc의 배열에 몇번째에 nthCh가 존재하는지
                if (isexist(desc->exist, nthCh))
                    desc = desc->next[whatch(desc->exist, nthCh)];
                next->fail = desc;
            }
            if (next->fail->output) {
                if (next->output < next->fail->output) {
                    next->output = next->fail->output;
                }
            }
            q.push(next);
        }
    }
 
    Trie* curr = root;
    for (int c = 0; str[c]; ++c) {
        int next = str[c] - 'a';
        while (curr != root && !isexist(curr->exist, next))
            curr = curr->fail;
        if (isexist(curr->exist, next)) curr = curr->next[whatch(curr->exist, next)];
        if (curr->output) {
            mark[c] = max(mark[c], curr->output);
        }
    }
 
    int res = 0;
    for (int i = N - 1; i >= 0; --i) {
        int check = mark[i];
        if (check == 0 && chk[i] == 0) res++;
        while (chk[i - check + 1] == 0 && i - check + 1 <= i) {
            chk[i - check + 1] = 1;
            check--;
        }
    }
 
    cout << res;
    delete root;
}