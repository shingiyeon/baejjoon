//# Author : nuclear852 ========================#
//# Solution : 2122824 =========================#
//# Time Stamp : 2016-03-05 20:38:25 ===========#
//# Problem Title : 미로 탐색 ==================#
//# Language : C++98 ===========================#

#include <iostream>
#include <queue>
using namespace std;
int main(void)
{
        int N, M;
        cin>>N>>M;
        char map[N][M];
        bool visited[N][M];
        for(int i=0; i<N; i++){
                for(int j=0; j<M; j++){
                        cin>>map[i][j];
                        visited[i][j]=0;
                }
        }

        int ans = N*M+1;

        queue<int> x;
        queue<int> y;
        queue<int> num;

        x.push(0);
        y.push(0);
        num.push(1);
        visited[0][0]=1;

        while( !x.empty())
        {
                int tmpx, tmpy, tmpnum;
                tmpx = x.front();
                tmpy = y.front();
                tmpnum = num.front();
        //      cout<<tmpx<<" "<<tmpy<<" "<<tmpnum<<endl;
                x.pop();
                y.pop();
                num.pop();

                if(tmpx == N-1 && tmpy == M-1)
                {
                        if(tmpnum < ans)
                                ans = tmpnum;
                }

                if( tmpx > 0){
                        if( visited[tmpx-1][tmpy] == 0 && map[tmpx-1][tmpy] == '1')
                        {
                                x.push(tmpx-1);
                                y.push(tmpy);
                                num.push(tmpnum+1);
                                visited[tmpx-1][tmpy]=1;
                        }
                }

                if(tmpx < N-1)
                {
                        if(visited[tmpx+1][tmpy] == 0 && map[tmpx+1][tmpy] == '1')
                        {
                                x.push(tmpx+1);
                                y.push(tmpy);
                                num.push(tmpnum+1);
                                visited[tmpx+1][tmpy]=1;
                        }
                }

                if(tmpy > 0)
                {
                        if( visited[tmpx][tmpy-1] == 0 && map[tmpx][tmpy-1] == '1')
                        {
                                x.push(tmpx);
                                y.push(tmpy-1);
                                num.push(tmpnum+1);
                                visited[tmpx][tmpy-1]=1;
                        }
                }

                if(tmpy < M-1)
                {
                        if(visited[tmpx][tmpy+1] == 0 && map[tmpx][tmpy+1]=='1')
                        {
                                x.push(tmpx);
                                y.push(tmpy+1);
                                num.push(tmpnum+1);
                                visited[tmpx][tmpy+1]=1;
                        }
                }
        }
        cout<<ans<<endl;
}