//# Author : nuclear852 ========================#
//# Solution : 26609793 ========================#
//# Time Stamp : 2021-02-21 23:39:16 ===========#
//# Problem Title : 트리 색칠하기 ================#
//# Language : C++17 ===========================#

#include <iostream>
#include <vector>
#define INF 999999999
using namespace std;

int dy[100001][20];
vector<int> adj[100001];

int d(int cur, int color, int parent) {
    if (dy[cur][color] != -1) return dy[cur][color];
    int c = color;
    for(auto next: adj[cur]) {
        if(next == parent) continue;
        int next_temp = INF;
        for(int next_color = 1; next_color < 20; next_color++) {
            if(next_color == color) continue;
            next_temp = min(next_temp, d(next, next_color, cur));
        }
        c += next_temp;
    } 
    return dy[cur][color] = c;
}

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    int n; cin >> n;
    for(int i=1; i<n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    int ans = INF;
    for(int i=1; i<=100000; i++) {
        for(int j=1; j<20; j++) {
            dy[i][j] = -1;
        }
    }
    for(int i=1; i<20; i++) {
        ans = min(ans, d(1, i, 0));
    }
    cout << ans;
}