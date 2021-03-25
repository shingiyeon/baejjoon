//# Author : nuclear852 ========================#
//# Solution : 1698846 =========================#
//# Time Stamp : 2016-02-14 22:57:04 ===========#
//# Problem Title : 01타일 ===================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(void)
{
    int N;
    cin>>N;
    long long arr[1000001];
    arr[1]=1;
    arr[2]=2;
    for(int i=3; i<1000001; i++)
        { arr[i] = arr[i-2] + arr[i-1];
        arr[i] = arr[i]%15746;}
    cout<<arr[N]<<endl;
    return 0;
}