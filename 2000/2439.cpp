//# Author : nuclear852 ========================#
//# Solution : 5174466 =========================#
//# Time Stamp : 2017-02-07 12:25:45 ===========#
//# Problem Title : 별 찍기 - 2 ===============#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main() {
        int N; cin>>N;
        for(int i=1; i<=N; i++){
                for(int j=1; j<=N-i; j++) cout<<" ";
                for(int j=1; j<=i; j++) cout<<"*";
                cout<<"\n";
        }
}