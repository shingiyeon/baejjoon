//# Author : nuclear852 ========================#
//# Solution : 1696783 =========================#
//# Time Stamp : 2016-02-14 20:46:56 ===========#
//# Problem Title : 가장 큰 증가 부분 수열 ==========#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(void)
{
        int N;
        cin >> N;
        int A[N];
        int dy[N];
        for(int i=0;i<N;i++)
                cin>>A[i];
        dy[0]=A[0];
        for(int i=1;i<N;i++)
        {
                dy[i]=A[i];

                for(int j=0; j<i; j++)
                {
                        if( A[i] > A[j])
                        {
                                if( A[i] + dy[j] >= dy[i])
                                        dy[i] = dy[j] + A[i];
                        }
                }
        }
        int ans = 0;
        for(int i=0; i<N; i++)
        {
                if(ans<dy[i])
                        ans=dy[i];
        }
        cout<<ans<<endl;
}