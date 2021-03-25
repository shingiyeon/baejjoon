#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
#include <math.h>
using namespace std;
#define INF 9876543210LL
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > pipii;

class MST {
    private:
        priority_queue<pipii, vector<pipii>, greater<pipii> > q;
        int V;
        vector<pipii> edges;
        vector<int> p;
        vector<int> sz;
    
    public:
        MST(int _V) {
            V = _V;
            p.resize(V+1);
            sz.resize(V+1);
            for(int i=1; i<=V; i++) {
                p[i] = i;
                sz[i] = 1;
            }
        }

        void addEdges(pipii edge) {
            edges.push_back(edge);
        }

        int parent(int cur) {
            if(p[cur] == cur) return cur;
            return p[cur] = parent(p[cur]);
        }

        void merge(int a, int b) {
            int pA = parent(a); int pB = parent(b);
            if(pA == pB) return;
            if(sz[pA] > sz[pB]) {
                swap(pA, pB);
            }
            p[pA] = pB;
            sz[pB] += sz[pA];
            return;
        }

        pair< vector<pipii>, vector<pipii> > mst_list() {
            vector<pipii> v;
            vector<pipii> none;
            for(auto edge: edges) {
                q.push(edge);
            }
            while(!q.empty()) {
                auto info = q.top(); q.pop();
                int val = info.first; auto [x, y] = info.second;
                if(parent(x) == parent(y)) {
                    none.push_back(info);
                    continue;
                }
                v.push_back(info);
                merge(x, y);
            }
            return {v, none};
        }
};

class LCA {
    private:
        int N, p;
        vector< vector<int> > tree;
        vector< vector<pii> > info;
        vector< vector<pii> > adj;
        vector<int> depth;

    public:
        LCA(int _N, int _p) {
            N = _N; p = _p;
            depth.resize(N+1);
            tree.resize(N+1, vector<int>(p+1));
            info.resize(N+1, vector<pii>(p+1, {-1, -1}));
            adj.resize(N+1);
            depth[0] = -1;
        }

        void addEdge(int a, int b, int c) {
            adj[a].push_back({b, c});
        }

        void getTree(int cur, int parent, int dist) {
            depth[cur] = depth[parent] + 1;
            tree[cur][0] = parent;
            if(dist > info[cur][0].first) {
                info[cur][0].second = info[cur][0].first;
                info[cur][0].first = dist;
            }
            else if(info[cur][0].first > dist && dist > info[cur][0].second) {
                info[cur][0].second = dist;
            }

            for(int i=1; i<=p; i++) {
                tree[cur][i] = tree[tree[cur][i-1]][i-1];
                auto [a, b] = info[cur][i-1];
                auto [c, d] = info[tree[cur][i-1]][i-1];
                info[cur][i].first = max(a, c);
                info[cur][i].second = -1;
                if(info[cur][i].first > a && a > info[cur][i].second) info[cur][i].second = a;
                if(info[cur][i].first > b && b > info[cur][i].second) info[cur][i].second = b;
                if(info[cur][i].first > c && c > info[cur][i].second) info[cur][i].second = c;
                if(info[cur][i].first > d && d > info[cur][i].second) info[cur][i].second = d;
            }

            for(auto [next, d]: adj[cur]) {
                if(next == parent) continue;
                getTree(next, cur, d);
            }
        }

        void getFandS(int &first, int &second, int cur, int parent) {
            if( info[cur][parent].first > first) {
                second = first;
                first = info[cur][parent].first;
            }
            else if(first > info[cur][parent].first && info[cur][parent].first > second) {
                second = info[cur][parent].first;
            }
            if(first > info[cur][parent].second && info[cur][parent].second > second) {
                second = info[cur][parent].second;
            }
        }

        pii getLca(int a, int b) {
            int first = -1, second = -1;
            if(depth[a] > depth[b]) {
                swap(a, b);
            }

            for(int i=p; i>=0; i--) {
                if(depth[a] <= depth[tree[b][i]]) {
                    getFandS(first, second, b, i);
                    b = tree[b][i];
                }
            }

            for(int i=p; i>=0; i--) {
                if(tree[a][i] != tree[b][i]) {
                    getFandS(first, second, a, i);
                    getFandS(first, second, b, i);
                    a = tree[a][i];
                    b = tree[b][i];
                }
            }
            if(a != b) {
                getFandS(first, second, a, 0);
                getFandS(first, second, b, 0);
                a = tree[a][0];
                b = tree[b][0];
            }
            return {first, second};
        }      
};

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    int V, E;
    cin >> V >> E;
    vector<pipii> e;
    for(int i=0; i<E; i++) {
        int a, b, c; cin >> a >> b >> c;
        e.push_back({c, {a,b}});
    }
    MST *mst = new MST(V);
    for(auto val: e) {
        mst->addEdges(val);
    }
    auto [mst_edges, none_edges] = mst->mst_list();
    if(mst_edges.size() != V-1) {
        cout << "-1";
        return 0;
    }
    ll MST_ = 0;
    ll ans = INF;
    for(auto edge: mst_edges) {
        MST_ += (ll)edge.first;
    }
    delete mst;

    LCA *lca = new LCA(V, (int)floor(log2(V))+1);
    for(auto edge: mst_edges) {
        lca->addEdge(edge.second.first, edge.second.second, edge.first);
        lca->addEdge(edge.second.second, edge.second.first, edge.first);
    }

    lca->getTree(1, 0, -1);
    for(auto val: none_edges) {
        int d = val.first;
        int x = val.second.first; int y = val.second.second;
        auto [first, second] = lca->getLca(x, y);
        if(d - (ll)first > 0) {
            ans = min(ans, MST_ + (ll)d - (ll)first);
        }
        if(second == -1) continue;
        if(d - (ll)second > 0) {
            ans = min(ans, MST_ + (ll)d - (ll)second);
        }
    }

    if(ans == INF) {
        cout << "-1";
        return 0;
    }
    cout << ans;
    delete lca;

}