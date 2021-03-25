//# Author : nuclear852 ========================#
//# Solution : 2122437 =========================#
//# Time Stamp : 2016-03-05 20:09:17 ===========#
//# Problem Title : 체스판 다시 칠하기 =============#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(void){
        char temp[9][9];
        int N, M;
        cin>>N>>M;
        char map[N+1][M+1];

        for(int i=0; i<N; i++)
                for(int j=0; j<M; j++)
                        cin>> map[i][j];

        int ans = 65;
        int amount = 0;


        for(int i=0; i<=N-8; i++)
        {
                for(int j=0; j<= M-8; j++)
                {
                        amount = 0;
                        int B=0, W=0;

                        for(int k=i; k<i+8; k++)
                                for(int l=j; l<j+8; l++)
                                        temp[k-i][l-j] = map[k][l];

                        for(int k=0; k<8; k++)
                        {
                                for(int l=0; l<8; l++)
                                {

                                        if( (k+l) % 2 ==0 && temp[k][l] != 'B')
                                                B++;
                                        if( (k+l) % 2 ==1 && temp[k][l] != 'W')
                                                B++;

                                        if( (k+l) % 2 ==0 && temp[k][l] !='W')
                                                W++;
                                        if( (k+l) % 2 ==1 && temp[k][l] !='B')
                                                W++;
                                }
                        }
                        
                        if(B>W)
                                amount = W;
                        else
                                amount = B;

                        if( amount < ans)
                                ans = amount;
                }
        }
        cout << ans<< endl;
}