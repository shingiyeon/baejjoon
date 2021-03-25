//# Author : nuclear852 ========================#
//# Solution : 5048152 =========================#
//# Time Stamp : 2017-01-18 13:37:30 ===========#
//# Problem Title : 윷놀이 ====================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(){
        char arr[5] = {'D', 'C', 'B', 'A', 'E'};
        for(int j=0; j<3; j++){
                int temp; int ans = 0;
                for(int i=0; i<4; i++){ cin>>temp; if(temp) ans++;}
                cout<<arr[ans]<<endl;
        }
}