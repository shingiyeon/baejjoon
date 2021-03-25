//# Author : nuclear852 ========================#
//# Solution : 2214785 =========================#
//# Time Stamp : 2016-03-10 22:13:19 ===========#
//# Problem Title : 얼마? ====================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(void)
    {
    int N;
    cin>>N;
    while(N--)
    {
        int car;
        cin>>car;
        int K;
        cin>>K;
        for(int i=0; i<K; i++){
            int a, b;
            cin>>a>>b;
            car = car + a*b;
        }
        cout<<car<<endl;
    }
}