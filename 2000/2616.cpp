//# Author : nuclear852 ========================#
//# Solution : 5012892 =========================#
//# Time Stamp : 2017-01-13 22:29:03 ===========#
//# Problem Title : 소형기관차 ==================#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
        int N;
        int len;
        int arr[50001];
        int dy[50001][3];
        int subarr[50001];
        cin>>N;
        for(int i=0; i<N; i++)
                scanf("%d",&arr[i]);
        cin>>len;

        for(int i=0; i<N; i++)
                subarr[i] = 0;
        for(int i=0; i<len; i++)
                subarr[0] += arr[i];
        for(int i=1; i<=N-len; i++)
                subarr[i] = subarr[i-1] + arr[i+len-1] - arr[i-1];
        for(int i=N-len+1; i<N; i++)
                subarr[i] = subarr[i-1] - arr[i-1];

        for(int i=0; i<N; i++)
                dy[i][0] = subarr[i];

        int Max = dy[0][0];
        for(int i=len; i<N; i++)
        {
                Max = max(Max, dy[i-len][0]);
                dy[i][1] = Max + subarr[i];
        }
        Max = dy[len][1];
        for(int i=len*2; i<N; i++)
        {
                Max = max(Max, dy[i-len][1]);
                dy[i][2] = Max + subarr[i];
        }
        Max = 0;
        for(int i=0; i<N; i++)
        {
                for(int j=0; j<3; j++)
                {
                        if( dy[i][j] > Max)
                                Max = dy[i][j];
                }
        }
        cout<<Max<<endl;
}