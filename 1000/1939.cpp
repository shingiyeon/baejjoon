#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

vector<pair<int, int> > v[100001];
bool visited[100001];
int MAX = 1;
int s, e;

int max(int a, int b){
    return a > b? a : b;
}
void d(int start, int end){
    if(start > end) return;
    if(start <= 0 || end>1000000000) return;
    int mid = (start + end) / 2;
    queue<int> q;
    for(int i=0; i<=100000; i++) visited[i] = 0;
    bool pos = 0;
    q.push(s);
    visited[s] = 1;
    while(!q.empty()){
        int idx = q.front(); q.pop();
        if(idx == e){
            pos = 1;
            break;
        }
        for(int i=0; i<v[idx].size(); i++){
            if(visited[v[idx][i].first]) continue;
            if(v[idx][i].second >= mid){
                visited[v[idx][i].first] = 1;
                q.push(v[idx][i].first);
            }
        }
    }
    while(!q.empty()) q.pop();
    if(pos){
        MAX = max(MAX, mid);
        d(mid+1, end);
        return;
    }
    else{
        d(start, mid-1);
        return;
    }
}

int main(){
    int N, M; scanf("%d%d",&N,&M);
    for(int i=0; i<M; i++){
        int a, b, c; scanf("%d%d%d",&a,&b,&c);
        v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, c));
    }
    scanf("%d%d",&s, &e);
    d(1, 1000000000);
    printf("%d", MAX);
}