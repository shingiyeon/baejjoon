//# Author : nuclear852 ========================#
//# Solution : 24433801 ========================#
//# Time Stamp : 2020-12-17 22:22:40 ===========#
//# Problem Title : 영우는 사기꾼? ===============#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
int indeg[100001];
int build[100001];
vector< vector<int> > adj;
int main() {
    scanf("%d%d%d", &N, &M, &K);
    adj.resize(N+1);
    for(int i=1; i<=M; i++) {
        int a, b; scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        indeg[b]++;
    }
    queue<int> q;

    bool pos = true;
    for(int i=1; i<=K; i++) {
        int a, b; scanf("%d%d", &a, &b);
        if(a == 1) {
            if(indeg[b]) {
                pos = false; break;
            }
            else {
                if(!build[b]) {
                    for(auto next: adj[b]) {
                        indeg[next]--;
                    }
                }
                build[b]++;
            }
        }
        else {
            if(build[b]) {
                build[b]--;
                if(!build[b]) {
                    for(auto next: adj[b]) {
                        indeg[next]++;
                    }
                }
            }
            else {
                pos = false; break;
            }
        }
    }
    if(pos) {
        printf("King-God-Emperor");
    }
    else {
        printf("Lier!");
    }
}