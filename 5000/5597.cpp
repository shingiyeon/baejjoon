//# Author : nuclear852 ========================#
//# Solution : 5153177 =========================#
//# Time Stamp : 2017-02-03 10:40:09 ===========#
//# Problem Title : 과제 안 내신 분..? ===========#
//# Language : C++98 ===========================#

#include <iostream>
#include <map>
using namespace std;
int main(){
        map<int, int> m;
        for(int i=1; i<29; i++){
                int temp; cin>>temp;
                m[temp]++;
        }
        for(int i=1; i<31; i++){
                if(!m[i]) cout<<i<<"\n";
        }
}