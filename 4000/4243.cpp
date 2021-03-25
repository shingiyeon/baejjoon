//# Author : nuclear852 ========================#
//# Solution : 3789827 =========================#
//# Time Stamp : 2016-08-10 11:36:09 ===========#
//# Problem Title : 보안 업체 ==================#
//# Language : C++98 ===========================#

#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

long long t[100];
long long arr[101][101][2];
long long subsum[101][101];

int N;
int start;

long long dy(int s, int e, bool dir)
{
        if( arr[s][e][dir] != -1)
                return arr[s][e][dir];
        if( s>start || e<start )
                return 99999999999;

        if(dir)
                arr[s][e][dir] = min( dy(s,e-1,1) + subsum[e-1][e] * (s+N-e) , dy(s,e-1,0) + subsum[s][e] * (s+N-e) );
        else
                arr[s][e][dir] = min( dy(s+1,e,0) + subsum[s][s+1] * (s+N-e) , dy(s+1,e,1) + subsum[s][e] * (s+N-e) );

        return arr[s][e][dir];
}

int main(void)
{
        int testcase;
        cin>>testcase;

        while(testcase--)
        {
                cin>>N>>start;
                for(int i=1; i<=N-1; i++)
                        scanf("%lld",&t[i]);

                for(int i=1; i<=N; i++)
                {
                        for(int j=1; j<=N; j++)
                                subsum[i][j] = 0;
                }

                for(int i=1; i<=N-1; i++)
                        subsum[i][i+1] = t[i];

                for(int i=1; i<=100; i++)
                {
                        for(int j=1; j<=100; j++)
                        {
                                for(int k=0; k<=1; k++)
                                {
                                        arr[i][j][k] = -1;
                                }
                        }
                }

                for(int i=1; i<=N-2; i++)
                {
                        for(int j=i+2; j<=N; j++)
                        {
                                subsum[i][j] = subsum[i][j-1] + t[j-1];
                        }
                }


                arr[start][start][0] = 0;
                arr[start][start][1] = 0;

                cout<<min( dy(1,N,0) , dy(1,N,1) )<<endl;

        }
}