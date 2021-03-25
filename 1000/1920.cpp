//# Author : nuclear852 ========================#
//# Solution : 2195207 =========================#
//# Time Stamp : 2016-03-10 00:25:24 ===========#
//# Problem Title : 수 찾기 ===================#
//# Language : C++98 ===========================#

#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
int A[100001];
int B[100001];
int N;
int search(int value,int start, int end)
{
        if(start > end)
                return 0;
        int mid = (start+end) / 2;
        if( A[mid] == value)
                return 1;
        else
        {
                if(A[mid] > value)
                        search( value, start, mid-1);
                else if( A[mid] < value)
                        search( value, mid+1, end);

        }
}
int main(void)
{
        int M;
        cin>>N;
        for(int i=0; i<N; i++)
                scanf("%d", &A[i]);
        sort(A, A+N);
        cin>>M;
        for(int i=0; i<M; i++)
                scanf("%d", &B[i]);

        for(int i=0; i<M; i++)
                printf("%d\n",search(B[i],0,N-1));
}