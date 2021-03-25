//# Author : nuclear852 ========================#
//# Solution : 5048175 =========================#
//# Time Stamp : 2017-01-18 13:39:52 ===========#
//# Problem Title : 상근날드 ===================#
//# Language : C++98 ===========================#

#include <iostream>
#include <algorithm>
using namespace std;
int main(){
        int temp;
        int min1 = 9999; int min2 = 9999;
        for(int i=0; i<3; i++){
                cin>>temp;
                min1 = min(min1, temp);}
        for(int i=0; i<2; i++){
                cin>>temp;
                min2 = min(min2, temp);}
        cout<<min1+min2-50<<endl;
}