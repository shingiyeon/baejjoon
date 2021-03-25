//# Author : nuclear852 ========================#
//# Solution : 1467245 =========================#
//# Time Stamp : 2016-02-01 11:36:32 ===========#
//# Problem Title : 헨리 =====================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(void)
{
        int T;
        cin >> T;
        for(int test = 0; test < T; test ++)
        {
                int a, b;
                cin>>a>>b;

                while(b%a)
                {
                        int k = b/a + 1;
                        a = a * k - b;
                        b = b * k;
                }

                cout<<b/a<<endl;
        }
        return 0;

}