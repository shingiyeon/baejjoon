//# Author : nuclear852 ========================#
//# Solution : 1729575 =========================#
//# Time Stamp : 2016-02-16 11:20:43 ===========#
//# Problem Title : 스위치 배열 =================#
//# Language : C++98 ===========================#

#include <iostream>
#include <cstring>
using namespace std;
using std::string;
int main(void)
{
        int T;
        cin>>T;
        for(int test=0; test<T; test++)
        {
                char input[33];
                cin>>input;
                int n;
                n=strlen(input);

                long long dy[33];
                dy[0] = 0;
                dy[1] = 1;
                for(int i=2; i<33; i++)
                        dy[i] = 2*dy[i-1]+1;

                int k=0;
                long long ans = 0;

                for(int i=0; i<n; i++)
                {
                        if( input[i] == '1')
                        {
                                if( !(k%2))
                                        ans = ans + dy[n-i];
                                else
                                        ans = ans - dy[n-i];
                                k=(k+1)%2;
                        }
                }

                cout<<ans<<endl;
        }
        return 0;
}