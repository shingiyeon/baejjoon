//# Author : nuclear852 ========================#
//# Solution : 24070783 ========================#
//# Time Stamp : 2020-11-26 23:00:56 ===========#
//# Problem Title : 부등호 ====================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

priority_queue<int, vector<int>, less<int>> q;
priority_queue<int, vector<int>, less<int>> q2;

vector<int> adj[10];
vector<int> adj2[10];

int indeg[10];
int indeg2[10];

bool visited[10];
bool visited2[10];

int ans[10];
int ans2[10];

int main() {
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        char tmp;
        scanf(" %c", &tmp);
        if(tmp == '<') {
            adj[i+1].push_back(i);
            indeg[i]++;
            adj2[i].push_back(i+1);
            indeg2[i+1]++;
        }
        else { // >
            adj[i].push_back(i+1);
            indeg[i+1]++;
            adj2[i+1].push_back(i);
            indeg2[i]++;
        }
    }

    for(int i=0; i<=N; i++) {
        if(indeg[i] == 0) {
            q.push(-i);
        }
        if(indeg2[i] == 0) {
            q2.push(-i);
        }
    }

    while(!q.empty()) {
        int cur = -q.top(); q.pop();
        for(int i=9; i>=0; i--) {
            if(visited[i] == 0) {
                ans[cur] = i;
                visited[i] = 1;
                break;
            }
        }

        for(auto next: adj[cur]) {
            indeg[next]--;
            if(indeg[next]==0) q.push(-next);
        }
    }

    while(!q2.empty()) {
        int cur = -q2.top(); q2.pop();

        for(int i=0; i<=9; i++) {
            if(visited2[i] == 0) {
                ans2[cur] = i;
                visited2[i] = 1;
                break;
            }
        }

        for(auto next: adj2[cur]) {
            indeg2[next]--;
            if(indeg2[next]==0) q2.push(-next);
        }
    }


    for(int i=0; i<=N; i++) {
        printf("%d", ans[i]);
    }
    printf("\n");
    for(int i=0; i<=N; i++) {
        printf("%d", ans2[i]);
    }

}