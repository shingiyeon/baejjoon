//# Author : nuclear852 ========================#
//# Solution : 5167709 =========================#
//# Time Stamp : 2017-02-06 10:36:02 ===========#
//# Problem Title : 캔디 구매 ==================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(){
        int N; int K; cin>>N>>K;
        int temp = 1;
        while(K--) temp*=10;
        if(N%temp>=(5*(temp/10))) N +=(temp - (N%temp));
        else N -= N%temp;

        cout<<N;
}