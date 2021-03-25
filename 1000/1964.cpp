//# Author : nuclear852 ========================#
//# Solution : 5090696 =========================#
//# Time Stamp : 2017-01-24 01:25:19 ===========#
//# Problem Title : 오각형, 오각형, 오각형… =========#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(){
        int N; cin>>N;
        int arr[2];
        arr[0] = 5;     arr[1] = 12;
        int tmp = arr[1]-arr[0]+3;
        for(int i=2; i<N; i++){
                int temp  = (tmp)%45678;
                arr[0] = arr[1];
                arr[1] = (arr[0] + temp);
                tmp = arr[1] - arr[0] + 3;
                arr[1] = arr[1]%45678;
        }
        if(N==1)        cout<<arr[0];
        else    cout<<arr[1];
}