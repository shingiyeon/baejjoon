//# Author : nuclear852 ========================#
//# Solution : 5174474 =========================#
//# Time Stamp : 2017-02-07 12:27:12 ===========#
//# Problem Title : 별 찍기 - 3 ===============#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(){
        int N; cin>>N;
        for(int i=N; i>=1; i--){
                for(int j=1; j<=i; j++)
                        cout<<"*";
                cout<<"\n";
        }
}