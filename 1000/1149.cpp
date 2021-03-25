//# Author : nuclear852 ========================#
//# Solution : 1363617 =========================#
//# Time Stamp : 2016-01-23 10:52:00 ===========#
//# Problem Title : RGB거리 ==================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;

int main(void)
{
        int N;

        cin>>N;

        long value[N][3]; // 0 red 1 green 2 blue
        long dy[N][3];

        for(int i=0; i<N; i++)
        {
                for(int j=0; j<3; j++)
                {
                        cin>>value[i][j];
                }
        }

        dy[0][0] = value[0][0];
        dy[0][1] = value[0][1];
        dy[0][2] = value[0][2];

        for(int i=1; i<N; i++)
        {
                for(int j=0; j<3; j++)
                {
                        switch(j)
                        {
                                case 0 :
                                {
                                        if( dy[i-1][1] <= dy[i-1][2])
                                                dy[i][j] = dy[i-1][1] + value[i][j];
                                        else
                                                dy[i][j] = dy[i-1][2] + value[i][j];
                                        break;
                                }

                                case 1 :
                                {
                                        if (dy[i-1][0] <= dy[i-1][2])
                                                dy[i][j] = dy[i-1][0] + value[i][j];
                                        else
                                                dy[i][j] = dy[i-1][2] + value[i][j];
                                        break;
                                }
                                case 2 :
                                {
                                        if( dy[i-1][0] <= dy[i-1][1])
                                                dy[i][j] = dy[i-1][0] + value[i][j];
                                                else
                                                dy[i][j] = dy[i-1][1] + value[i][j];
                                        break;
                                }
                        }
                }
        }
        long ans = dy[N-1][0];
        for(int i=1; i<3; i++)
        {
                if(dy[N-1][i] < ans)
                        ans = dy[N-1][i];
        }
        cout<<ans;
        return 0;
}