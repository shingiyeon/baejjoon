//# Author : nuclear852 ========================#
//# Solution : 5158395 =========================#
//# Time Stamp : 2017-02-04 09:21:51 ===========#
//# Problem Title : 시험 점수 ==================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(){
        int S=0, T=0, temp;
        for(int i=0; i<2; i++){
                for(int j=0; j<4; j++){
                        cin>>temp;
                        if(!i) S+=temp;
                        else T+=temp;
                }
        }
        S > T ? cout<<S : cout<< T;
}