//# Author : nuclear852 ========================#
//# Solution : 26579399 ========================#
//# Time Stamp : 2021-02-20 23:27:32 ===========#
//# Problem Title : 트리의 색깔과 쿼리 =============#
//# Language : C++17 ===========================#

#include <bits/stdc++.h>
 
using namespace std;
typedef tuple<int, int, int> tp;
typedef pair<int, int> pii;
 
int n,q;
int par[100005], ptr[100005];
vector<pii> query;
vector<int> ans;
 
set<int> S[100005];
 
int fi(int x) {
    if (x == ptr[x]) return x;
    else return ptr[x] = fi(ptr[x]);
}
 
int main() {
    scanf("%d %d", &n, &q);
    for (int i = 2; i <= n; i++)
        scanf("%d", &par[i]);
    for (int i = 1; i <= n; i++) {
        int cl;
        scanf("%d", &cl);
        S[i].insert(cl);
        ptr[i] = i;
    }
    int l = 0, sz=0;
    for (int i = 0; i < n + q - 1; i++) {
        int t1, t2;
        scanf("%d %d", &t1, &t2);
        query.emplace_back(t1, t2);
    }
    reverse(query.begin(), query.end());
    for (pii x : query) {
        int tp = x.first, k = x.second;
        if (tp == 1) {
            int p = par[k];
            p = fi(p), k = fi(k);
            if (S[k].size() >= S[p].size()) swap(p, k);
            ptr[k] = p;
            for (auto it = S[k].begin(); it != S[k].end(); it++)
                S[p].insert(*it);
            S[k].clear();
        }
        else
            ans.push_back(S[fi(k)].size());
    }
    reverse(ans.begin(), ans.end());
    for (int x : ans) printf("%d\n", x);
    return 0;
}