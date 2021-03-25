//# Author : nuclear852 ========================#
//# Solution : 25788218 ========================#
//# Time Stamp : 2021-01-28 23:09:30 ===========#
//# Problem Title : LCA ====================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

int N, M;
vector<int> adj[50050];
bool visited[50050];
int depth[50050];
int tree[50050][30];

void getTree(int here, int parent) {
    depth[here] = depth[parent] + 1;
    tree[here][0] = parent;
    
    for(int i=1; i<=30; i++) {
        if( (1 << i) > N ) break;
        tree[here][i] = tree[tree[here][i-1]][i-1];
    }

    for(auto next: adj[here]) {
        if(next == parent) continue;
        getTree(next, here);
    }
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i=1; i<=N-1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    depth[0] = -1;
    getTree(1, 0);
    cin >> M;
    for(int i=1; i<=M; i++) {
        int a, b; cin >> a >> b;
        if(depth[a] != depth[b]) {
            if(depth[a] > depth[b]) {
                int tmp = b;
                b = a;
                a = tmp;
            }
        }

        for(int i=29; i>=0; i--) {
            if( (1<<i) > N) continue;
            if(depth[a] <= depth[tree[b][i]]) {
                b = tree[b][i];
            }
        }

        int lca = a;
        if(a != b) {
            for(int i=29; i>=0; i--) {
                if( (1<<i) > N) continue;
                if(tree[a][i] != tree[b][i]) {
                    a = tree[a][i];
                    b = tree[b][i];
                }
                lca = tree[a][i];
            }
        }
        cout << lca << "\n";
    }
    
 

}