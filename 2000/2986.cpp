//# Author : nuclear852 ========================#
//# Solution : 5160090 =========================#
//# Time Stamp : 2017-02-04 17:48:06 ===========#
//# Problem Title : 파스칼 ====================#
//# Language : C++98 ===========================#

#include <iostream>
#include <math.h>
using namespace std;
int main(){
        int N; cin>>N;
        for(int i=2; i<=sqrt(N); i++){
                if(!(N%i)) {cout<<N-(N/i);return 0;}
        }
        cout<<N-1;
}