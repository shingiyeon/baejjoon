//# Author : nuclear852 ========================#
//# Solution : 5158630 =========================#
//# Time Stamp : 2017-02-04 11:27:55 ===========#
//# Problem Title : 심부름 가는 길 ===============#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(){
        int sum = 0;    int temp;
        for(int i=0; i<4; i++){
                cin>>temp;
                sum+=temp;}
        cout<<sum/60<<"\n"<<sum%60;
}