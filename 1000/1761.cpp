//# Author : nuclear852 ========================#
//# Solution : 26194242 ========================#
//# Time Stamp : 2021-02-09 11:14:26 ===========#
//# Problem Title : 정점들의 거리 ================#
//# Language : C++17 ===========================#

#include <iostream>
#include <vector>
#include <math.h>
#include <utility>
using namespace std;

class LCA{
    private:
        int n, p;
        vector< vector< pair<int, int> > > adj;
        vector< vector<int> > tree;
        vector< vector<long long> > dist;
        vector<int> depth;

    public:
        LCA(int _n, int _p) {
            n = _n; p = _p;
            adj.resize(n + 1);
            tree.resize(n + 1, vector<int> (p+1));
            dist.resize(n + 1, vector<long long> (p+1));
            depth.resize(n + 1);
            depth[0] = -1;
        }

        vector< pair<int, int> > getAdj(int idx){
            return adj[idx];
        }

        void addEdge(int a, int b, int c) {
            adj[a].push_back({b, c});
        }

        void getTree(int cur, int parent, long long d) {
            depth[cur] = depth[parent] + 1;
            tree[cur][0] = parent;
            dist[cur][0] = (long long)d;
            for(int i=1; i<=p; i++) {
                if( (1<<i) > n) break;
                tree[cur][i] = tree[tree[cur][i-1]][i-1];
                dist[cur][i] = dist[cur][i-1] + dist[tree[cur][i-1]][i-1];
            }
            for(auto info: adj[cur]) {
                int next = info.first;
                int next_d= info.second;
                if(next == parent) continue;
                getTree(next, cur, next_d);
            }
        }

        void swap_value(int &a, int &b) {
            int tmp = a;
            a = b;
            b = tmp;
        }

        long long get_lca(int a, int b) {
            long long ans = 0;
            if(depth[a] > depth[b]) swap_value(a,b);
            for(int i=p; i>=0; i--) {
                if( (1<<i) > n) continue;
                if(depth[a] <= depth[tree[b][i]]) {
                    ans += dist[b][i];
                    b = tree[b][i];
                }
            }
            if(a != b) {
                for(int i=p; i>=0; i--) {
                    if( (1<<i) > n) continue;
                    if(tree[a][i] != 0 && tree[a][i] != tree[b][i]) {
                        ans += dist[a][i];
                        ans += dist[b][i];
                        a = tree[a][i];
                        b = tree[b][i];
                    }
                }
                if(a != b) {
                    ans += dist[a][0];
                    ans += dist[b][0];
                }
            }
            
            return ans;
        }
};

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    int N, M; cin >> N;
    LCA *lca = new LCA(N, (int)floor(log2(N)) + 1);
    for(int i=1; i<N; i++) {
        int a, b, c; cin >> a >> b >> c;
        lca->addEdge(a, b, c);
        lca->addEdge(b, a, c);
    }
    lca->getTree(1, 0, 0);
    cin >> M;
    for(int i=0; i<M; i++) {
        int a, b; cin>>a>>b;
        cout << lca->get_lca(a,b) << endl;
    }
    delete lca;
}