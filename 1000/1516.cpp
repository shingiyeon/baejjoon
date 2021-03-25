//# Author : nuclear852 ========================#
//# Solution : 24120799 ========================#
//# Time Stamp : 2020-11-29 22:19:35 ===========#
//# Problem Title : 게임 개발 ==================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <queue>
#include <utility>
#include <vector>
#include <functional>

using namespace std;
int N;

int arr[501];
int indeg[501];
int answer[501];
vector<int> adj[501];
priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > q;

int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        scanf("%d", &arr[i]);
        int tmp;
        scanf("%d", &tmp);
        while(tmp != -1) {
            adj[tmp].push_back(i);
            indeg[i]++;
            scanf("%d", &tmp);
        }
    }
    for(int i=1; i<=N; i++) {
        if(indeg[i] == 0) {
            q.push({arr[i], i});
        }
    }

    while(!q.empty()) {
        int cur = q.top().second;
        int time = q.top().first;
        q.pop();
        answer[cur] = time;
        for(auto next: adj[cur]) {
            indeg[next]--;
            if(indeg[next] == 0) {
                q.push({time + arr[next], next});
            }
        }
    }

    for(int i=1; i<=N; i++) {
        printf("%d\n", answer[i]);
    }

}