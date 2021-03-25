//# Author : nuclear852 ========================#
//# Solution : 1363589 =========================#
//# Time Stamp : 2016-01-23 10:36:19 ===========#
//# Problem Title : 피보나치 함수 ================#
//# Language : C++98 ===========================#

#include <iostream>

using namespace std;

int main(void)
{
        int T;
        cin >> T;

        for(int test = 0; test<T; test++)
        {
                int n;
                cin >> n;

                int one;
                int zero;

                int onea[n+1];
                int zeroa[n+1];

                onea[0] = 0;
                onea[1] = 1;
                zeroa[0] = 1;
                zeroa[1] = 0;

                for(int i=2; i<n+1; i++)
                {
                        onea[i] = onea[i-1] + onea[i-2];
                        zeroa[i] = zeroa[i-1] + zeroa[i-2];
                }

                cout<<zeroa[n]<<" "<<onea[n]<<endl;
        }

        return 0;
}