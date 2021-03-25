//# Author : nuclear852 ========================#
//# Solution : 2683544 =========================#
//# Time Stamp : 2016-04-03 11:56:06 ===========#
//# Problem Title : 토마토 ====================#
//# Language : C++98 ===========================#

#include <iostream>
#include <queue>
using namespace std;
int tomato[100][100][100];
int main(void){
        int M, N, H;
        cin>>M>>N>>H;
        queue<int> x;
        queue<int> y;
        queue<int> z;
        queue<int> day;

        for(int k=0; k<H; k++)
        {
                for(int j=0; j<N; j++)
                {
                        for(int i=0; i<M; i++)
                        {
                                cin>>tomato[i][j][k];
                                if(tomato[i][j][k] == 1)
                                {
                                        x.push(i);
                                        y.push(j);
                                        z.push(k);
                                        day.push(0);
                                }
                        }
                }
        }
        int ans = 0;
        while( !x.empty() )
        {
                int tmpx = x.front();
                x.pop();
                int tmpy = y.front();
                y.pop();
                int tmpz = z.front();
                z.pop();
                int tmpday = day.front();
                day.pop();

                if( tmpx + 1 < M && tomato[tmpx+1][tmpy][tmpz] == 0)
                {
                        tomato[tmpx+1][tmpy][tmpz] = 1;
                        x.push(tmpx+1);
                        y.push(tmpy);
                        z.push(tmpz);
                        day.push(tmpday+1);
                }

                if( tmpx - 1 >=0 && tomato[tmpx-1][tmpy][tmpz] == 0)
                {
                        tomato[tmpx-1][tmpy][tmpz] = 1;
                        x.push(tmpx-1);
                        y.push(tmpy);
                        z.push(tmpz);
                        day.push(tmpday+1);
                }

                if( tmpy + 1 < N && tomato[tmpx][tmpy+1][tmpz] == 0)
                {
                        tomato[tmpx][tmpy+1][tmpz] = 1;
                        x.push(tmpx);
                        y.push(tmpy+1);
                        z.push(tmpz);
                        day.push(tmpday+1);
                }

                if( tmpy - 1 >=0 && tomato[tmpx][tmpy-1][tmpz] == 0)
                {
                        tomato[tmpx][tmpy-1][tmpz] = 1;
                        x.push(tmpx);
                        y.push(tmpy-1);
                        z.push(tmpz);
                        day.push(tmpday+1);
                }

                if( tmpz + 1 < H && tomato[tmpx][tmpy][tmpz+1] == 0)
                {
                        tomato[tmpx][tmpy][tmpz+1] = 1;
                        x.push(tmpx);
                        y.push(tmpy);
                        z.push(tmpz+1);
                        day.push(tmpday+1);
                }

                if( tmpz - 1 >= 0 && tomato[tmpx][tmpy][tmpz-1] == 0)
                {
                        tomato[tmpx][tmpy][tmpz-1] = 1;
                        x.push(tmpx);
                        y.push(tmpy);
                        z.push(tmpz-1);
                        day.push(tmpday+1);
                }
                ans = tmpday;
        }

        for(int i=0; i<M; i++)
        {
                for(int j=0; j<N; j++)
                {
                        for(int k=0; k<H; k++)
                        {
                                if( tomato[i][j][k] == 0)
                                        ans = -1;
                        }
                }
        }
        cout<<ans<<endl;
}