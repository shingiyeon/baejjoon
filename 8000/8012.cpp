//# Author : nuclear852 ========================#
//# Solution : 26338969 ========================#
//# Time Stamp : 2021-02-13 23:16:20 ===========#
//# Problem Title : 한동이는 영업사원! =============#
//# Language : C++17 ===========================#

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class LCA {
    private:
        vector< vector<int> > adj;
        vector<int> depth;
        vector< vector<int> > tree;
        int n, p;

    public:
        LCA(int _n, int _p) {
            n = _n; p = _p;
            adj.resize(n+1);
            depth.resize(n+1);
            tree.resize(n+1, vector<int>(p+1));
            depth[0] = -1;
        }    

       void addEdge(int a, int b){
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

       void swapValue(int &a, int &b) {
           int tmp = a; a = b; b = tmp;
       }

       int getLCA(int a, int b) {
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
       
       int getDepth(int a) {
           return depth[a];
       }
};

int main() {
    cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
    int n, m, p; cin >> n;
    int cur, future;
    long long ans = 0;
    p = floor(log2(n)) + 1;
    LCA *lca = new LCA(n, p);
    for(int i=1; i<n; i++) {
        int a, b; cin >> a >> b;
        lca->addEdge(a, b);
        lca->addEdge(b, a);
    }
    lca->getTree(1, 0);
    cin >> m >> cur;
    for(int i=1; i<m; i++) {
        cin >> future;
        int lca_v = lca->getLCA(cur, future);
        ans = ans + lca->getDepth(cur) + lca->getDepth(future) - 2 * lca->getDepth(lca_v);
        cur = future;
    }
    cout << ans;
    delete lca;

}