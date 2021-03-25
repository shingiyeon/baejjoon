//# Author : nuclear852 ========================#
//# Solution : 4998911 =========================#
//# Time Stamp : 2017-01-12 10:25:44 ===========#
//# Problem Title : 암호코드 ===================#
//# Language : C++98 ===========================#

#include <iostream>
#include <string.h>
using namespace std;
int main()
{
        char arr[5001];
        int dy[5002];
        dy[0] = 1;
        cin>>arr;
        int N = strlen(arr) - 1;
        for(int i=1; i<=N+1; i++)
                dy[i] = 0;
        for(int i=0; i<=N; i++)
        {
                if( arr[i] == '0')
                        continue;
                else if( arr[i] < '2' )
                {
                        if( i+2 <= N+1)
                        {
                                if( arr[i+1] == '0')
                                        dy[i+2] = (dy[i+2]+dy[i]) % 1000000;
                                else{
                                        dy[i+1] = (dy[i+1]+dy[i]) % 1000000;
                                        dy[i+2] = (dy[i+2]+dy[i]) % 1000000;
                                }
                        }
                        else
                                dy[i+1] = (dy[i+1]+dy[i]) % 1000000;
                }
                else if( arr[i] == '2')
                {
                        if( i+2 <= N+1)
                        {
                                if(arr[i+1] == '0')
                                        dy[i+2] = (dy[i+2]+dy[i]) % 1000000;
                                else if( arr[i+1] >= '1' && arr[i+1] <='6'){
                                        dy[i+1] = (dy[i+1]+dy[i]) % 1000000;
                                        dy[i+2] = (dy[i+2]+dy[i]) % 1000000;
                                }
                                else
                                        dy[i+1] = (dy[i+1]+dy[i]) % 1000000;
                        }
                        else
                                dy[i+1] = (dy[i+1]+dy[i]) % 1000000;
                }
                else
                        dy[i+1] = (dy[i+1]+dy[i]) % 1000000;
        }
        cout<<dy[N+1]<<endl;
}