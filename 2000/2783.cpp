//# Author : nuclear852 ========================#
//# Solution : 5160227 =========================#
//# Time Stamp : 2017-02-04 18:18:27 ===========#
//# Problem Title : 삼각 김밥 ==================#
//# Language : C++98 ===========================#

#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
int main(){
        float Max = 100000.00;
        float x, y; float z; cin>>x>>y;
        z=(float)(x/y)*1000;
        Max = min(Max, z);
        int n; cin>>n;
        while(n--){
                cin>>x>>y; z=(x/y)*1000;
                Max = min(Max, z);
        }
        printf("%.2f",Max);
}