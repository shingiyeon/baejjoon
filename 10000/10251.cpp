//# Author : nuclear852 ========================#
//# Solution : 1677859 =========================#
//# Time Stamp : 2016-02-13 20:22:02 ===========#
//# Problem Title : 운전 면허 시험 ===============#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(void)
{
        int T;
        cin >> T;
        for(int test = 0;  test< T; test++)
        {
                int M, N, L, G;
                cin>>M>>N>>L>>G;
                int dy[M][N][M+N][2];

                for(int i=0; i<M; i++)
                        for(int j=0; j<N; j++)
                                for(int k=0; k<M+N; k++)
                                        for(int l=0; l<2; l++)
                                                dy[i][j][k][l] = 1000001;

                int garo[M][N-1];
                int sero[M-1][N];

                for(int i=0; i<M; i++)
                        for(int j=0; j<N-1; j++)
                                cin>>garo[i][j];

                for(int i=0; i<M-1; i++)
                        for(int j=0; j<N; j++)
                                cin>>sero[i][j];
                dy[0][0][0][0] = 0;
                dy[0][0][0][1] = 0;
                for(int i=0; i<M; i++)
                {
                        for(int j=0; j<N; j++)
                        {
                                if(i==0 && j>0)
                                        dy[i][j][0][0] = dy[i][j-1][0][0] + garo[i][j-1];
                                else if(j==0 && i>0)
                                        dy[i][j][0][1] = dy[i-1][j][0][1] + sero[i-1][j];
                                else if( i!=0 && j!=0 )
                                {
                                        for(int k=0; k< i+j; k++)
                                        {
                                                if( dy[i][j-1][k][0] + garo[i][j-1] < dy[i][j][k][0])
                                                        dy[i][j][k][0] = dy[i][j-1][k][0] + garo[i][j-1];
                                                if( dy[i][j-1][k][1] + garo[i][j-1] < dy[i][j][k+1][0])
                                                        dy[i][j][k+1][0] = dy[i][j-1][k][1] + garo[i][j-1];
                                                if( dy[i-1][j][k][1] + sero[i-1][j] < dy[i][j][k][1])
                                                        dy[i][j][k][1] = dy[i-1][j][k][1] + sero[i-1][j];
                                                if( dy[i-1][j][k][0] + sero[i-1][j] < dy[i][j][k+1][1])
                                                        dy[i][j][k+1][1] = dy[i-1][j][k][0] + sero[i-1][j];
                                        }
                                }
                        }
                }
                int ans = -1;
                for(int i=M+N-1; i>=0; i--)
                {
                        if( dy[M-1][N-1][i][0] <= G)
                                ans = i;
                        if( dy[M-1][N-1][i][1] <= G)
                                ans = i;
                }
                if(ans != -1)
                        ans =  ((M-1) + (N-1)) * L + ans;
                cout<<ans<<endl;
        }
        return 0;
}