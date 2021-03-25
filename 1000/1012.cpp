//# Author : nuclear852 ========================#
//# Solution : 2067866 =========================#
//# Time Stamp : 2016-03-02 21:48:42 ===========#
//# Problem Title : 유기농 배추 =================#
//# Language : C++98 ===========================#

#include <iostream>
#include <queue>
using namespace std;
struct Point{
        int x;
        int y;
};
int main(void)
{
        int T;
        cin>>T;
        while(T--)
        {
                int M,N,K;
                cin>>M>>N>>K;
                int map[N][M];
                bool visited[N][M];
                int ans = 0;

                Point arr[K];
                for(int i=0; i<N; i++){
                        for(int j=0; j<M; j++){
                                map[i][j] = 0;
                                visited[i][j] = 1;
                        }
                }

                for(int i=0; i<K; i++)
                {
                        cin>>arr[i].x>>arr[i].y;
                        map[ arr[i].y ][ arr[i].x ] = 1;
                        visited[ arr[i].y ][ arr[i].x ] = 0;
                }

                queue<int> x;
                queue<int> y;

                for(int i=0; i<K; i++)
                {
                        if( visited[ arr[i].y ][ arr[i].x ] == 0)
                        {
                                ans++;
                                x.push( arr[i].x);
                                y.push( arr[i].y);

                                while( !x.empty())
                                {
                                        int tmpx;
                                        int tmpy;
                                        tmpx = x.front();
                                        tmpy = y.front();
                                        x.pop();
                                        y.pop();

                                        visited[tmpy][tmpx] = ans;

                                        if(tmpx > 0 && map[tmpy][tmpx-1] == 1 && visited[tmpy][tmpx-1] == 0)
                                        {
                                                x.push( tmpx-1);
                                                y.push( tmpy);
                                                visited[ tmpy][tmpx-1] = 1;
                                        }

                                        if(tmpx < M-1 && map[tmpy][tmpx+1] == 1 && visited[tmpy][tmpx+1] == 0)
                                        {
                                                x.push( tmpx+1);
                                                y.push( tmpy);
                                                visited[tmpy][tmpx+1]=1;
                                        }

                                        if(tmpy > 0 && map[tmpy-1][tmpx] == 1 && visited[tmpy-1][tmpx] == 0)
                                        {
                                                x.push(tmpx);
                                                y.push(tmpy-1);
                                                visited[tmpy-1][tmpx]=1;
                                        }

                                        if(tmpy <N-1 && map[tmpy+1][tmpx] == 1 && visited[tmpy+1][tmpx] == 0)
                                        {
                                                x.push(tmpx);
                                                y.push(tmpy+1);
                                                visited[tmpy+1][tmpx]=1;
                                        }
                                }
                        }
                }

                cout<<ans<<endl;
        }
}