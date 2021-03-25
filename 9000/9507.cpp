//# Author : nuclear852 ========================#
//# Solution : 4943183 =========================#
//# Time Stamp : 2017-01-05 15:48:10 ===========#
//# Problem Title : Generations of Tribbles #
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main()
{
        long long dy[68];
        dy[0] = 1;
        dy[1] = 1;
        dy[2] = 2;
        dy[3] = 4;
        for(int i=4; i<=67; i++)
                dy[i] = dy[i-1] + dy[i-2]+ dy[i-3] + dy[i-4];

        int T;
        cin>>T;
        while(T--)
        {
                int num;
                cin>>num;
                cout<<dy[num]<<endl;
        }
}