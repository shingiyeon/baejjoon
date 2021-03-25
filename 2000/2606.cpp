//# Author : nuclear852 ========================#
//# Solution : 2195451 =========================#
//# Time Stamp : 2016-03-10 00:39:08 ===========#
//# Problem Title : 바이러스 ===================#
//# Language : C++98 ===========================#

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(void)
{
        int N, K;
        queue<int> q;
        vector<int> com[101];
        bool visited[101];
        for(int i=0; i<101; i++)
                visited[i] = 0;
        cin>>N>>K;

        for(int i=0; i<K; i++)
        {
                int tmpx, tmpy;
                cin>>tmpx>>tmpy;

                com[tmpx].push_back(tmpy);
                com[tmpy].push_back(tmpx);
        }
        int ans=0;
        q.push(1);
        visited[1]=1;
        while( !q.empty() )
        {
                int point = q.front();
                q.pop();
                ans++;
                for(int i=0; i<com[point].size(); i++)
                {
                        int temp = com[point].at(i);
                        if(visited[temp] == 0)
                        {
                                q.push(temp);
                                visited[temp] = 1;
                        }
                }
        }

        cout<<ans-1<<endl;
}