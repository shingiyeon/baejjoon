//# Author : nuclear852 ========================#
//# Solution : 26231312 ========================#
//# Time Stamp : 2021-02-10 10:04:09 ===========#
//# Problem Title : LCA와 쿼리 ================#
//# Language : C++17 ===========================#

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class LCA {
    private:
        int n, p;
        vector<vector<int> > adj;
        vector<int> depth;
        vector<vector<int> > tree;
    
    public:
        LCA(int _n, int _p) {
            n = _n; p = _p;
            adj.resize(n + 1);
            depth.resize(n + 1);
            tree.resize(n+1, vector<int>(p+1));
            depth[0] = -1;
        }

        void addEdge(int a, int b) {
            adj[a].push_back(b);
        }

        void getTree(int cur, int parent) {
            depth[cur] = depth[parent] + 1;
            tree[cur][0] = parent;
            for(int i=1; i<=p; i++) tree[cur][i] = tree[tree[cur][i-1]][i-1];
            for(auto next: adj[cur]) {
                if(next == parent) continue;
                getTree(next, cur);
            }
        }

        void swapValue(int &a, int &b) {
            int tmp = a; a = b; b = tmp;
        }

        int getLca(int a, int b) {
            if(depth[a] > depth[b]) swapValue(a, b);
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

        int getAns(int r, int u, int v) {
            int ru = getLca(r, u);
            int rv = getLca(r, v);
            int uv = getLca(u, v);

            if(ru == rv && rv == uv) {
                return ru;
            }
            else if(ru == rv) return uv;
            else if(ru == uv) return rv;
            else if(rv == uv) return ru;
        }
};

int main() {
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    int N, p, M;
    cin >> N;
    p = (int)floor(log2(N)) + 1;
    LCA *lca = new LCA(N, p);
    for(int i=1; i<N; i++) {
        int a, b; cin >> a >> b;
        lca->addEdge(a, b);
        lca->addEdge(b, a);
    }
    lca->getTree(1, 0);
    cin >> M;
    for(int i=1; i<=M; i++) {
        int a, b, c; cin >> a >> b >> c;
        cout << lca->getAns(a, b, c) << "\n";
    }
    delete lca;
}