//# Author : nuclear852 ========================#
//# Solution : 25855243 ========================#
//# Time Stamp : 2021-01-30 23:08:23 ===========#
//# Problem Title : LCA 2 ==================#
//# Language : C++17 ===========================#

#include <iostream>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

class LCA {
    private:
        int n, p;
        vector< vector<int> > adj;
        vector<int> depth;
        vector< vector<int> > tree;
    
    public:
        LCA(int _n, int _p) {
            n = _n; p = _p;
            adj.resize(n + 1);
            depth.resize(n + 1);
            tree.resize(n + 1, vector<int>(p + 1));
            depth[0] = -1;
        }

        void addEdge(int a, int b) {
            adj[a].push_back(b);
        }

        void getTree(int here, int parent) {
            depth[here] = depth[parent] + 1;
            tree[here][0] = parent;

            for(int i=1; i<=p; i++) {
                if( (1<<i) > n) break;
                tree[here][i] = tree[tree[here][i-1]][i-1];
            }
            for(auto next: adj[here]) {
                if(next == parent) continue;
                getTree(next, here);
            }
        }

        void swap_value(int &a, int &b) {
            int tmp = a;
            a = b;
            b = tmp;
        }

        int get_lca(int a, int b) {
            if(depth[a] > depth[b]) {
                swap_value(a, b);
            }
            for(int i=p; i>=0; i--) {
                if( (1<<i) > n) continue;
                if(depth[a] <= depth[tree[b][i]]) b = tree[b][i];
            }
            int lca = a;
            if (a != b) {
                for(int i=p; i>=0; i--) {
                    if( (1<<i) > n) continue;
                    if(tree[a][i] != tree[b][i]) {
                        a = tree[a][i];
                        b = tree[b][i];
                    }
                    lca = tree[a][i];
                }
            }
            return lca;
        }
};


int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N;
    LCA *lca = new LCA(N, (int)floor(log2(N)) + 1);
    for(int i=0; i<N-1; i++) {
        int a, b; cin >> a >> b;
        lca->addEdge(a, b);
        lca->addEdge(b, a);
    }
    lca->getTree(1, 0);
    cin >> M;
    for(int i=0; i<M; i++) {
        int a, b; cin >> a >> b;
        cout << lca->get_lca(a, b) << "\n";
    }
    delete lca;
}