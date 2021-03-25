//# Author : nuclear852 ========================#
//# Solution : 1466847 =========================#
//# Time Stamp : 2016-02-01 11:18:14 ===========#
//# Problem Title : 헨리 =====================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(void)
{
        int T;
        cin >> T;

        for(int test = 0; test<T; test++)
        {
                long long a;
                long long b;
                long long ab;
                cin>>a>>b;
                ab = (long long)b/a;
              //  cout<<ab<<endl;

                while(a!=1)
                {

                        if( a*ab - b >= 0)
                        {
                                long long tmp = b;
                                b= b*ab;
                                a= a*ab - tmp;

                                ab++;

                                long long temp = 2;

                                while(1)
                                {
                                        if( a%temp == 0 && b%temp == 0)
                                        {
                                                a = a/temp;
                                                b = b/temp;
                                        }

                                        else
                                        {
                                                temp++;
                                                if(temp > a)
                                                        break;
                                        }
                                }

                              //  cout<<a<<" "<<b<<endl;
                                if(a==0)
                                        break;
                                ab = b/a;
                           //     cout<<ab<<endl;
                        }
                        else
                                ab++;
                }
                cout<<b<<endl;
        }
        return 0;
}