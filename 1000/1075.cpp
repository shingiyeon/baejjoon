//# Author : nuclear852 ========================#
//# Solution : 4051741 =========================#
//# Time Stamp : 2016-09-01 22:28:31 ===========#
//# Problem Title : 나누기 ====================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;

int main(void)
{
        int N;
        int F;

        cin>>N>>F;

        N= (N/100)*100;

        for(int i=0; i<100; i++)
        {
                if( !((N+i)%F) )
                {
                        N=N+i;
                        break;
                }
        }

        if( N%100 < 10)
                cout<<"0"<<N%100<<endl;
        else
                cout<<N%100<<endl;
}