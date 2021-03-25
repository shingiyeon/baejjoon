//# Author : nuclear852 ========================#
//# Solution : 5035813 =========================#
//# Time Stamp : 2017-01-17 00:33:29 ===========#
//# Problem Title : 숨바꼭질 ===================#
//# Language : C++98 ===========================#

#include <iostream>
#include <queue>
#include <string.h>
#include <utility>
using namespace std;
int main(){
        int N, K; cin>>N>>K;
        bool visited[100005]; memset(visited,0,sizeof(visited));
        pair<int, int> p;
        queue< pair<int, int> > q;
        p.first = N; p.second = 0; q.push(p);
        visited[N] = 1;
        int x, n;
        while(!q.empty()){
                p = q.front(); x = p.first; n = p.second; q.pop();
                if(x == K){     cout<<n<<endl;  return 0;       }
                if(x-1>=0){
                        if(visited[x-1] == 0){
                                p.first = x-1; p.second = n+1; q.push(p); visited[x-1] = 1;}}
                if(x+1<=100000){
                        if(visited[x+1] == 0){
                                p.first = x+1; p.second = n+1; q.push(p); visited[x+1] = 1;}}
                if(2*x<=100000){
                        if(visited[2*x] == 0){
                                p.first = 2*x; p.second = n+1; q.push(p); visited[2*x] = 1;}}
        }
        return 0;
}