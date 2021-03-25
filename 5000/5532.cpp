//# Author : nuclear852 ========================#
//# Solution : 5158648 =========================#
//# Time Stamp : 2017-02-04 11:33:29 ===========#
//# Problem Title : 방학 숙제 ==================#
//# Language : C++98 ===========================#

#include <iostream>
#include <algorithm>
using namespace std;
int main(){
        int L,A,B,C,D; cin>>L>>A>>B>>C>>D;
        cout<<L-max(((A/C)+((A%C)?1:0)),((B/D)+((B%D)?1:0)));
}