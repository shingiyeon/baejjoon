//# Author : nuclear852 ========================#
//# Solution : 2249972 =========================#
//# Time Stamp : 2016-03-12 20:19:06 ===========#
//# Problem Title : 주사위 ====================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(void)
{
        long long N;
        cin>>N;
        long long arr[6];
        long long other[6];
        long long dy[4];
        for(int i=0; i<=3; i++)
                dy[i] = 4000000;
        for(int i=0; i<=5; i++){
                cin>>arr[i];
                other[i] = 5-i;
        }
        int sum= 0;
        for(int i=0; i<=5; i++)
        {
                sum = sum + arr[i];
                if( arr[i] < dy[1])
                        dy[1] = arr[i];
                for(int j=i+1; j<=5; j++)
                {
                        if( other[i] != j)
                        {
                                if( arr[i]+arr[j] < dy[2] )
                                        dy[2] = arr[i] + arr[j];
                                for(int k=j+1; k<=5; k++)
                                {
                                        if(other[k] != i && other[k] != j)
                                        {
                                                if( arr[i]+arr[j]+arr[k] < dy[3])
                                                        dy[3] = arr[i]+arr[j]+arr[k];
                                        }
                                }
                        }
                }
        }
        for(int i=0; i<=5; i++){
                if( sum - arr[i] < dy[0])
                        dy[0] = sum - arr[i];
        }
        long long ans;
        if( N>=3)
                ans = (4*(N-2)+4*(N-1))*dy[2] + 4*dy[3] + ((N-2)*(N-2)+4*(N-2)*(N-1))*dy[1];
        else if (N == 2)
                ans = 4*dy[3] + 4*dy[2];
        else
                ans = dy[0];
        cout<<ans;
}