//# Author : nuclear852 ========================#
//# Solution : 5153187 =========================#
//# Time Stamp : 2017-02-03 10:42:58 ===========#
//# Problem Title : 콘테스트 ===================#
//# Language : C++98 ===========================#

#include <iostream>
#include <algorithm>
using namespace std;
int main(){
        int W[2][10];
        for(int i=0; i<20; i++) cin>>W[i/10][i%10];
        sort(W[0],W[0]+10); sort(W[1],W[1]+10);
        cout<<W[0][7]+W[0][8]+W[0][9]<<" "<<W[1][7]+W[1][8]+W[1][9];
}