//# Author : nuclear852 ========================#
//# Solution : 5021660 =========================#
//# Time Stamp : 2017-01-15 09:41:44 ===========#
//# Problem Title : 5와 6의 차이 ===============#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main()
{
        int A, B;
        cin>>A>>B;
        int minA=A, maxA=A, minB=B, maxB=B;
        for(int i=1000000; i>=1; i=i/10)
        {
                if( A-(i*5) >=0 && A-(i*5) < i)
                        maxA += i;
                else if( A-(i*6) >=0 && A-(i*6) < i)
                        minA -= i;
                if( B-(i*5) >= 0 && B-(i*5) < i)
                        maxB += i;
                else if( B-(i*6) >= 0 && B-(i*6) < i)
                        minB -= i;
                A = A%i; B = B%i;
        }
        cout<<minA+minB<<" "<<maxA+maxB;
}