//# Author : nuclear852 ========================#
//# Solution : 26198296 ========================#
//# Time Stamp : 2021-02-09 13:34:35 ===========#
//# Problem Title : 도로 네트워크 ================#
//# Language : C++17 ===========================#

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <utility>
using namespace std;

class LCA {
    private:
        vector< vector<pair<int, int> > > adj;
        vector< vector<int> > tree;
        vector< vector<int> > min_cost;
        vector< vector<int> > max_cost;
        vector<int> depth;
        int n, p;
        const int INF = 999999999;
    public:
        LCA(int _n, int _p) {
            n = _n;
            p = _p;
            adj.resize(n+1);
            tree.resize(n+1, vector<int>(p+1));
            min_cost.resize(n+1, vector<int>(p+1));
            max_cost.resize(n+1, vector<int>(p+1));
            depth.resize(n+1);
            depth[0] = -1;

            for(int i=0; i<=n; i++) {
                for(int j=0; j<=p; j++) {
                    min_cost[i][j] = INF;
                }
            }
        }

        void addEdge(int a, int b, int c) {
            adj[a].push_back({b,c});
        }

        void getTree(int cur, int parent, int dist) {
            depth[cur] = depth[parent] + 1;
            tree[cur][0] = parent;
            min_cost[cur][0] = dist;
            max_cost[cur][0] = dist;

            for(int i=1; i<=p; i++) {
                tree[cur][i] = tree[tree[cur][i-1]][i-1];
                max_cost[cur][i] = max(max_cost[cur][i-1], max_cost[tree[cur][i-1]][i-1]);
                min_cost[cur][i] = min(min_cost[cur][i-1], min_cost[tree[cur][i-1]][i-1]);
            }

            for(auto info: adj[cur]) {
                int next = info.first;
                int next_dist = info.second;
                if(next == parent) continue;
                getTree(next, cur, next_dist);
            }
        }

        void swapValue(int &a, int &b) {
            int tmp = a;
            a = b;
            b = tmp;
        }

        pair<int, int> getAns(int a, int b) {
            int min_ans = INF;
            int max_ans = 0;
            if(depth[a] > depth[b]) swapValue(a, b);
            for(int i=p; i>=0; i--) {
                if(depth[a] <= depth[tree[b][i]]) {
                    min_ans = min(min_ans, min_cost[b][i]);
                    max_ans = max(max_ans, max_cost[b][i]);
                    b = tree[b][i];
                }
            }

            for(int i=p; i>=0; i--) {
                if(tree[a][i] != tree[b][i]) {
                    min_ans = min(min_ans, min(min_cost[a][i], min_cost[b][i]));
                    max_ans = max(max_ans, max(max_cost[a][i], max_cost[b][i]));
                    a = tree[a][i];
                    b = tree[b][i];
                }
            }
            if(a != b) {
                min_ans = min(min_ans, min(min_cost[a][0], min_cost[b][0]));
                max_ans = max(max_ans, max(max_cost[a][0], max_cost[b][0]));
            }
            return {min_ans, max_ans};
        }
};

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    LCA* lca = new LCA(N, (int)floor(log2(N)) + 1);
    for(int i=1; i<N; i++) {
        int a, b, c; cin >> a >> b >> c;
        lca->addEdge(a, b, c);
        lca->addEdge(b, a, c);
    }
    lca->getTree(1, 0, 0);
    int M; cin >> M;
    for(int i=1; i<=M; i++) {
        int a, b; cin >> a >> b;
        auto ans = lca->getAns(a, b);
        cout << ans.first << " " << ans.second << "\n";
    }
}