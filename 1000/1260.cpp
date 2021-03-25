//# Author : nuclear852 ========================#
//# Solution : 2161986 =========================#
//# Time Stamp : 2016-03-07 23:05:26 ===========#
//# Problem Title : DFS와 BFS ===============#
//# Language : C++98 ===========================#

#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
int main(void)
{
        int N, M, K;
        cin>>N>>M>>K;
        int children[N+1];
        int graph[N+1][N+1];
        bool visited[N+1];
        for(int i=0; i<=N; i++){
                children[i]=0;
                visited[i]=0;
        }
        for(int i=0; i<M; i++)
        {
                int tmp1, tmp2;
                cin>>tmp1>>tmp2;
                graph[tmp1][ children[tmp1]] =tmp2;
                graph[tmp2][ children[tmp2]] = tmp1;
                children[tmp2]++;
                children[tmp1]++;
        }
        for(int i=1; i<=N; i++){
                for(int j=0; j< children[i]; j++)
                {
                        for(int k=j+1; k<children[i]; k++)
                        {
                                if( graph[i][j] > graph[i][k])
                                {
                                        int tmp = graph[i][k];
                                        graph[i][k] = graph[i][j];
                                        graph[i][j] = tmp;
                                }
                        }
                }
        }

        stack<int> p;
        p.push(K);
        while( !p.empty())
        {
                int point = p.top();
                p.pop();
                if(visited[point] == 0)
                {
                        cout<<point<<" ";
                        visited[point] = 1;
                        for(int i=children[point]-1; i>=0; i--)
                        {
                                if(visited[graph[point][i]]==0)
                                        p.push( graph[point][i] );
                        }
                }
        }

        for(int i=0; i<=N; i++)
                visited[i] = 0;
        cout<<endl;
        queue<int> q;
        q.push(K);
        visited[K]=1;
        while( !q.empty())
        {
                int point = q.front();
                q.pop();
                cout<<point<<" ";
                for(int i=0; i<children[point]; i++)
                {
                        if(visited[ graph[point][i] ] == 0)
                        {
                                q.push(graph[point][i]);
                                visited[ graph[point][i] ] = 1;
                        }
                }
        }
}