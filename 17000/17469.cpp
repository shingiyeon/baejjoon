//# Author : nuclear852 ========================#
//# Solution : 26579718 ========================#
//# Time Stamp : 2021-02-20 23:35:45 ===========#
//# Problem Title : 트리의 색깔과 쿼리 =============#
//# Language : C++17 ===========================#

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int N, Q;
struct Query { 
    int r, cur;
}query[1100001];
vector<int> ans;
int tmp[100001];
int p[100001];
int sz[100001];

set<int> S[100001];
int parent(int cur) {
    if(p[cur] == cur) return cur;
    return p[cur] = parent(p[cur]);
}
void merge(int a, int b) {
    int pA = parent(a); int pB = parent(b);
    if(sz[pA] >= sz[pB]) swap(pA, pB);
    p[pA] = pB; sz[pB] += sz[pA];
    for(const int &color : S[pA]) {
        S[pB].insert(color);
    }
    S[pA].clear();
    return;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> Q;
    for(int i=2; i<=N; i++) cin >> tmp[i];
    for(int i=1; i<=N; i++) {
        int c; cin >> c;
        S[i].insert(c);
         p[i] = i;  sz[i] = 1;
    }
    for(int i=1; i<=N+Q-1; i++) {
        cin >> query[i].r >> query[i].cur;
    }
    int idx = 1;
    for(int i=N+Q-1; i>=1; i--) {
        if(query[i].r == 2) {
            ans.push_back((int)S[parent(query[i].cur)].size());
        }
        else {
            merge(tmp[query[i].cur], query[i].cur);
        }
    }
    for(auto it = ans.rbegin(); it != ans.rend(); it++) {
        cout << *it << "\n";
    }

}