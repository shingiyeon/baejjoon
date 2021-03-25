//# Author : nuclear852 ========================#
//# Solution : 24386183 ========================#
//# Time Stamp : 2020-12-15 15:11:39 ===========#
//# Problem Title : 알고스팟어 ==================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <queue>
#include <vector>
#include <string>
using namespace std;

vector<int> adj[30];
vector<int> ans;
int indeg[30];
int lv[30];
int N;
char str[101][11];
bool appear[26];

bool cmp(int a, int b, int cur) {
    if(str[a][cur] != '\0' && str[b][cur] == '\0') {
        return false;
    }
    else if(str[a][cur] == '\0' || str[b][cur] == '\0') {
        return true;
    }
    
    if(str[a][cur] != str[b][cur]) {
        int aN = str[a][cur] - 'a';
        int bN = str[b][cur] - 'a';
        adj[aN].push_back(bN);
        indeg[bN]++;
        return true;
    }
    else {
        return cmp(a, b, cur+1);
    }
} 

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%s", str[i]);
    }
    for(int i=0; i<N; i++) {
        for(int j=0; str[i][j] != '\0'; j++) {
            appear[str[i][j] - 'a'] = true;
        }
    }

    bool state = true;
    bool pos = true;

    for(int i=0; i<N; i++) {
        for(int j=i+1; j<N; j++) {
            pos &= cmp(i, j, 0);
        }
    }
    queue<int> q;
    for(int i=0; i<26; i++) {
        if(!indeg[i] && appear[i]) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        if(q.size() > 1) {
            state = false;
        }
        int cur = q.front(); q.pop();
        ans.push_back(cur);
        for(auto next: adj[cur]) {
            indeg[next]--;
            if(!indeg[next]) {
                q.push(next);
            }
        }
    }

    for(int i=0; i<26; i++) {
        if(indeg[i] && appear[i]) {
            pos = false;
        }
    }
    if(!pos) {
        printf("!");
    }
    else if(!state) {
        printf("?");
    }
    else {
        for(auto val: ans) {
            printf("%c", val + 'a');
        }
    }


}