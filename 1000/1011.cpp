//# Author : nuclear852 ========================#
//# Solution : 2038336 =========================#
//# Time Stamp : 2016-03-01 10:54:48 ===========#
//# Problem Title : Fly me to the Alpha Centauri #
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(void)
{
        int T;
        cin>>T;
        while(T--)
        {
                long long x;
                long long y;
                cin>>x>>y;
                long long distance = y - x;
                long long ans;
                long long tmp=1;
                if(distance ==0)
                        ans=0;
                else{
                        while(1)
                        {
                                if( tmp*(tmp-1)< distance && distance <=tmp*tmp)
                                {
                                        ans = 2*tmp-1;
                                        break;
                                }
                                else if ( tmp*tmp < distance && distance<= tmp*(tmp+1))
                                {
                                        ans = 2*tmp;
                                        break;
                                }
                                tmp++;
                        }
                }
                cout<<ans<<endl;
        }
}