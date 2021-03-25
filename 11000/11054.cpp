//# Author : nuclear852 ========================#
//# Solution : 4951022 =========================#
//# Time Stamp : 2017-01-06 12:34:28 ===========#
//# Problem Title : 가장 긴 바이토닉 부분 수열 ========#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
        int arr[1001];
        int LIS[1001];
        int DIS[1001];
        int N;
        cin>>N;
        for(int i=1; i<=N; i++)
                scanf("%d", &arr[i]);

        for(int i=1; i<=N; i++)
        {
                int temp = 1;
                for(int j=i-1; j>=1; j--)
                {
                        if( arr[i] > arr[j]  && LIS[j] + 1 > temp)
                                temp = LIS[j] +1;
                }
                LIS[i] = temp;
        }

        for(int i=N; i>=1; i--)
        {
                int temp = 1;
                for(int j=i+1; j<=N; j++)
                {
                        if( arr[i] > arr[j] && DIS[j] + 1 > temp)
                                temp = DIS[j] + 1;
                }
                DIS[i] = temp;
        }
        int max = 0;

        for(int i=1; i<=N; i++)
        {
                if( LIS[i] + DIS[i] >= max)
                        max = LIS[i] + DIS[i];
        }
        cout << max-1<<endl;
}