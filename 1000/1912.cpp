//# Author : nuclear852 ========================#
//# Solution : 1367056 =========================#
//# Time Stamp : 2016-01-24 09:16:28 ===========#
//# Problem Title : 연속합 ====================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(void)
{
        int N;
        cin>>N;
        long long arr[N];
        long long dy[N];
        for(int i=0;i<N;i++)
                cin>>arr[i];
        dy[0]=arr[0];
        for(int i=1; i<N; i++)
        {
                if(dy[i-1]>0)
                        dy[i] = dy[i-1] + arr[i];

                else
                        dy[i]= arr[i];
        }
        long long max;
        max = dy[0];
        for(int i=1; i<N; i++)
        {
                if(max < dy[i])
                        max = dy[i];
        }
        cout<<max<<endl;
        return 0;
}