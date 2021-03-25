//# Author : nuclear852 ========================#
//# Solution : 5262955 =========================#
//# Time Stamp : 2017-02-22 11:30:06 ===========#
//# Problem Title : Mystery ================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(){
        int n;
        int *a = &n;
        long t =(long)a/16;
        if(t%2) cout<<"Yonsei";
        else cout<<"Korea";
}