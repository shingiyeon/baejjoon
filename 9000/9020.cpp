//# Author : nuclear852 ========================#
//# Solution : 3557401 =========================#
//# Time Stamp : 2016-07-23 17:21:42 ===========#
//# Problem Title : 골드바흐의 추측 ===============#
//# Language : C++98 ===========================#

#include <iostream>
#include <math.h>

using namespace std;

int main(void){
        int T;
        bool arr[10001];
        for(int i=2; i<=10000; i++)
                arr[i] = 1;

        for(int i=3; i<=10000; i++)
        {
                for(int j=2; j<=sqrt(i); j++)
                {
                        if( i%j == 0)
                                arr[i] = 0;
                }
        }

        int testcase;

        cin>>testcase;

        while(testcase--)
        {
                int n;
                cin>>n;

                for(int i=(n/2); i>=2; i--)
                {
                        if( arr[i] && arr[n-i] )
                        {
                                cout<<i<<" "<<n-i<<endl;
                                break;
                        }
                }
        }
}