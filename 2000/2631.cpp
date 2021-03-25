//# Author : nuclear852 ========================#
//# Solution : 4928496 =========================#
//# Time Stamp : 2017-01-03 22:52:42 ===========#
//# Problem Title : 줄세우기 ===================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(){
        int N;
        int arr[201];
        int dy[201];
        int max=0;
        cin>>N;
        for(int i=1; i<=N; i++)
                cin>>arr[i];
        arr[0] = 0;
        dy[0] = 0;
        for(int i=1; i<=N; i++)
        {
                int temp = 0;
                for(int j= i-1; j>=0; j--)
                {
                        if( arr[i] > arr[j] && dy[j] > temp)
                                temp = dy[j];
                }
                dy[i] = temp+1;
                if(dy[i] > max)
                        max = dy[i];
        }
        cout<<N-max<<endl;
}