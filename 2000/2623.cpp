//# Author : nuclear852 ========================#
//# Solution : 24121060 ========================#
//# Time Stamp : 2020-11-29 22:32:33 ===========#
//# Problem Title : 음악프로그램 =================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[1001];
vector<int> answer;
int indeg[1001];
queue<int> q;
int N, M;
int main() {
    scanf("%d%d", &N, &M);
    for(int i=1; i<=M; i++) {
        int len; scanf("%d", &len);
        int a, b;
        scanf("%d", &a);
        for(int j=2; j<=len; j++) {
            scanf("%d", &b);
            adj[a].push_back(b);
            indeg[b]++;
            a = b;
        }
    }
    for(int i=1; i<=N; i++) {
        if(indeg[i]==0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        answer.push_back(cur);
        for(auto next: adj[cur]) {
            indeg[next]--;
            if(indeg[next] == 0) {
                q.push(next);
            }
        }
    }
    if(answer.size() != N) {
        printf("0");
    }
    else {
        for(auto val: answer) {
            printf("%d\n", val);
        }
    }
}