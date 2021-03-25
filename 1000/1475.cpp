//# Author : nuclear852 ========================#
//# Solution : 5022038 =========================#
//# Time Stamp : 2017-01-15 11:34:41 ===========#
//# Problem Title : 방 번호 ===================#
//# Language : C++98 ===========================#

#include <iostream>
#include <string.h>
using namespace std;
int main(){
        char str[1000005];
        cin>>str;
        int N = strlen(str);
        int arr[9];
        int max = 0;
        for(int i=0; i<9; i++) arr[i] = 0;
        for(int i=0; i<N; i++){
                if(str[i]!='9')
                        arr[ str[i] - '0']++;
                else
                        arr[6] ++;
        }
        for(int i=0; i<9; i++){
                if(i!=6){
                        if(arr[i]>max)
                                max=arr[i];
                }
                else{
                        int temp = (arr[6] - 1)/2 + 1;
                        if( temp > max)
                                max = temp;
                }
        }
        cout<<max;
}