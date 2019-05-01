#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
vector<int> c[51];
int main(){
    int p[51];
    int root;
    int cut;
    int N; scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d", &p[i]);
    scanf("%d", &cut);
    for(int i=0; i<N; i++){
        if(p[i]==-1) {root=i; continue;}
        c[p[i]].push_back(i);
    }
    int answer = 0;
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int idx = q.front(); q.pop();
        if(idx == cut) continue;
        for(int i=0; i<c[idx].size(); i++){
            if(c[idx][i] == cut) c[idx].erase(c[idx].begin() + i);
        }
        if(!c[idx].size()) answer++;
        for(int i=0; i<c[idx].size(); i++){
            q.push(c[idx][i]);
        }
    }
    printf("%d", answer);
}