//# Author : nuclear852 ========================#
//# Solution : 5046752 =========================#
//# Time Stamp : 2017-01-18 10:07:28 ===========#
//# Problem Title : 시험 성적 ==================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(){
        char a[5] = {'A','B','C','D','F'};
        int dx[4] = { 90, 80, 70, 60};
        int n;  cin>>n;
        for(int i=0; i<4; i++){
                if(n>=dx[i]){
                        cout<<a[i]<<endl;
                        return 0;
                }
        }
        cout<<a[4]<<endl;
        return 0;
}