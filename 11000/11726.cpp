//# Author : nuclear852 ========================#
//# Solution : 2294669 =========================#
//# Time Stamp : 2016-03-15 01:03:47 ===========#
//# Problem Title : 2×n 타일링 ================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(void){
        int n;
        cin>>n;
        int dy[1001];

        dy[0]= 0;
        dy[1]= 1;
        dy[2] = 2;

        for(int i=3; i<1001; i++)
                dy[i] = (dy[i-1] + dy[i-2])%10007;

        cout<<dy[n];
}