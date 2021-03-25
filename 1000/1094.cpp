//# Author : nuclear852 ========================#
//# Solution : 1367071 =========================#
//# Time Stamp : 2016-01-24 09:26:19 ===========#
//# Problem Title : 막대기 ====================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(void)
{
        int length = 64;
        int N;
        cin >> N;
        int ans=0;

        while( N != 0)
        {
                if(length  > N)
                {
                        length= length/2;
                }

                else
                {
                        N= N-length;
                        ans++;
                }
        }
        cout<<ans<<endl;
        return 0;
}