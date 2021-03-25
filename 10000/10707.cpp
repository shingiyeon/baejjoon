//# Author : nuclear852 ========================#
//# Solution : 5149287 =========================#
//# Time Stamp : 2017-02-02 16:41:13 ===========#
//# Problem Title : 수도요금 ===================#
//# Language : C++98 ===========================#

#include <iostream>
#include <algorithm>
using namespace std;
int main(){
        int A,B,C,D,P;
        cin>>A>>B>>C>>D>>P;
        cout<<min(A*P, C<P ? B+(P-C)*D : B)<<endl;
}