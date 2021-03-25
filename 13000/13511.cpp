//# Author : nuclear852 ========================#
//# Solution : 26220759 ========================#
//# Time Stamp : 2021-02-09 22:46:46 ===========#
//# Problem Title : 트리와 쿼리 2 ===============#
//# Language : C++17 ===========================#

#include <iostream>
#include <vector>
#include <math.h>
#include <utility>
using namespace std;
typedef long long ll;

class LCA {
    private:
        int n, p;
        vector< vector< pair<int, ll> > > adj;
        vector< vector<int> > tree;
        vector< vector<ll> > cost;
        vector<int> depth;

    public:
        LCA(int _n, int _p) {
            n = _n; p = _p;
            adj.resize(n+1);
            tree.resize(n+1, vector<int>(p+1));
            cost.resize(n+1, vector<ll>(p+1));
            depth.resize(n+1);
            depth[0] = -1;
        }

        void addEdge(int a, int b, int c) {
            adj[a].push_back({b, c});
        }

        void getTree(int cur, int parent, ll dist) {
            depth[cur] = depth[parent] + 1;
            tree[cur][0] = parent;
            cost[cur][0] = dist;

            for(int i=1; i<=p; i++) {
                tree[cur][i] = tree[tree[cur][i-1]][i-1];
                cost[cur][i] = cost[cur][i-1] + cost[tree[cur][i-1]][i-1];
            }

            for(auto info: adj[cur]) {
                int next = info.first;
                ll next_dist = info.second;
                if(next == parent) continue;
                getTree(next, cur, next_dist);
            }
        }

        void swapValue(int &a, int &b) {
            int tmp = a;
            a = b;
            b = tmp;
        }

        int getLca(int a, int b) {
            if(depth[a] > depth[b]) swapValue(a, b);
            for(int i=p; i>=0; i--) {
                if(depth[a] <= depth[tree[b][i]]) {
                    b = tree[b][i];
                }

            }
            for(int i=p; i>=0; i--) {
                if(tree[a][i] != tree[b][i]) {
                    a = tree[a][i];
                    b = tree[b][i];
                }
            }
            if(a != b) {
                return tree[a][0];
            }
            return a;
        }

        ll getDist(int a, int b) {
            ll dist = 0;
            if(depth[a] > depth[b]) swapValue(a, b);
            for(int i=p; i>=0; i--) {
                if(depth[a] <= depth[tree[b][i]]) {
                    dist += cost[b][i];
                    b = tree[b][i];
                }
            }
            for(int i=p; i>=0; i--) {
                if(tree[a][i] != tree[b][i]) {
                    dist += cost[a][i];
                    dist += cost[b][i];
                    a = tree[a][i];
                    b = tree[b][i];
                }
            }
            if(a != b) {
                dist += cost[a][0];
                dist += cost[b][0];
            }
            return dist;
        }

        int getKthNode(int a, int b, int k) {
            int lcaNode = getLca(a, b);
            if (depth[a] - depth[lcaNode] < k) {
                k -= ( depth[a] - depth[lcaNode] );
                int findK = depth[b] - depth[lcaNode] + 1 - k;
                for(int i=p; i>=0; i--) {
                    int num = (1 << i);
                    if(findK >= num) {
                        findK -= num;
                        b = tree[b][i];
                    }
                }
                return b;
            }
            else {
                k -= 1;
                for(int i=p; i>=0; i--) {
                    int num = (1 << i);
                    if(k >= num) {
                        k -= num;
                        a = tree[a][i];
                    }
                }
                return a;
            }
        }
};

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M; cin >> N;
    int p = (int)floor(log2(N)) + 1;
    LCA *lca = new LCA(N, p);

    for(int i=1; i<N; i++) {
        int a, b, c; cin >> a >> b >> c;
        lca->addEdge(a, b, c);
        lca->addEdge(b, a, c);
    }
    lca->getTree(1, 0, 0);

    cin >> M;
    for(int i=1; i<=M; i++) {
        int c, u, v, w;
        cin >> c;
        if(c == 1) {
            cin >> u >> v;
            cout << lca -> getDist(u, v) << "\n";
        }
        else {
            cin >> u >> v >> w;
            cout << lca -> getKthNode(u, v, w) << "\n";
        }
    }
    delete lca;
}