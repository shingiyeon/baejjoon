//# Author : nuclear852 ========================#
//# Solution : 5149963 =========================#
//# Time Stamp : 2017-02-02 17:48:03 ===========#
//# Problem Title : 앵그리 창영 =================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(){
        int N,W,H;
        cin>>N>>W>>H;
        while(N--){
                int temp; cin>>temp;
                temp*temp<=W*W+H*H ? cout<<"DA\n" : cout<<"NE\n";
        }
}