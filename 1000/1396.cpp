//# Author : nuclear852 ========================#
//# Solution : 26489454 ========================#
//# Time Stamp : 2021-02-18 09:18:44 ===========#
//# Problem Title : 크루스칼의 공 ================#
//# Language : C++17 ===========================#

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <math.h>
#define INF 1000000000
using namespace std;

tuple<int, int, int> edge[100001];

class LCA {
    private:
        vector<vector<int> > adj;
        vector<vector<int> > tree;
        vector<pair<int, int> > info;
        vector<int> depth;

        int n, p;
    public:
        LCA(int _n, int _p) {
            n = _n, p = _p;
            adj.resize(n + 1);
            tree.resize(n + 1, vector<int>(p+1));
            depth.resize(n + 1);
            depth[0] = -1;
        }

        void addEdge(int a, int b) {
            adj[a].push_back(b);
        }

        void getTree(int cur, int parent) {
            depth[cur] = depth[parent] + 1;
            tree[cur][0] = parent;
            for(int i=1; i<=p; i++) {
                tree[cur][i] = tree[tree[cur][i-1]][i-1];
            }
            for(auto next: adj[cur]) {
                if(next == parent) continue;
                getTree(next, cur);
            }
        }

        int getLca(int a, int b) {
            if(depth[a] > depth[b]) swap(a, b);
            for(int i=p; i>=0; i--) {
                if(depth[a] <= depth[tree[b][i]]) b = tree[b][i];
            }
            for(int i=p; i>=0; i--) {
                if(tree[a][i] != tree[b][i]) {
                    a = tree[a][i];
                    b = tree[b][i];
                }
            }
            if(a != b) {
                a = tree[a][0];
                b = tree[b][0];
            }
            return a;
        }
};

class UF {
    private:
        vector<int> p;
        vector<pair<int, int> > info;
        int idx;
    public:
        UF(int N, int n) {
            p.resize(N + 1);
            info.resize(N + 1);
            idx = n;
            for(int i=1; i<=N; i++) {
                p[i] = i;
                info[i].first = 1;
                info[i].second = 0;
            }
        }
        int parent(int cur) {
            if(p[cur] == cur) return p[cur];
            return p[cur] = parent(p[cur]);
        }
        int merge(int a, int b, int c) {
            idx++;
            int pA = parent(a); int pB = parent(b);
            p[pA] = idx;
            p[pB] = idx;
            info[idx].first = info[pA].first + info[pB].first;
            info[idx].second = c;
            return idx;
        }
        vector<int> root() {
            vector<int> tmp;
            for(int i=1; i<=idx; i++) {
                if(parent(i) == i) tmp.push_back(i);
            }
            return tmp;
        }
        pair<int, int> getInfo(int cur) {
            return info[cur];
        }
};

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m, q; cin >> n >> m;
    LCA *lca = new LCA(2*n, (int)floor(log2(n)) + 1);
    UF *uf = new UF(2*n, n);

    for(int i=0; i<m; i++) {
        int a, b, c; cin >> a >> b >> c;
        edge[i] = make_tuple(c, a, b);
    }

    sort(edge, edge+m);

    for(int i=0; i<m; i++) {
        int a, b, c;
        tie(c, a, b) = edge[i];

        int pA = uf->parent(a); int pB = uf->parent(b);
        if(pA == pB) {
            continue;
        }
        int p = uf->merge(a, b, c);
        lca->addEdge(pA, p); lca->addEdge(p, pA);
        lca->addEdge(pB, p); lca->addEdge(p, pB);
    }

    auto root_list = uf->root();
    for(int root: root_list) {
        lca->getTree(root, 0);
    }
    
    cin >> q;
    for(int i=1; i<=q; i++) {
        int x, y; cin >> x >> y;
        if(uf->parent(x) != uf->parent(y)) cout << "-1" << "\n";
        else {
            int lca_node = lca->getLca(x, y);
            auto info = uf->getInfo(lca_node);
            cout << info.second << " " << info.first << "\n";
        }
    }



    delete lca;
    delete uf;
}