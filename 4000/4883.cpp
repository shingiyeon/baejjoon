//# Author : nuclear852 ========================#
//# Solution : 4908905 =========================#
//# Time Stamp : 2017-01-01 22:24:28 ===========#
//# Problem Title : 삼각 그래프 =================#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>

using namespace std;

int min(int a, int b){
        if(a>b)
                return b;
        else
                return a;
}

int main(){
        int N;
        int arr[2][3];
        long long dy[2][3];
        int temp;
        int k=1;
        while(1){
                cin>>N;
                if(N==0)
                        break;
                for(int i=0; i<N; i++){
                        for(int j=0; j<3; j++)
                                scanf("%d",&arr[1][j]);
                        if(i==0){
                                dy[0][0] = 99999999;
                                dy[0][1] = arr[1][1];
                                dy[0][2] = arr[1][1] + arr[1][2];
                                arr[0][0] = arr[1][0];
                                arr[0][1] = arr[1][1];
                                arr[0][2] = arr[1][2];
                        }
                        if(i==1){
                                dy[1][0] = arr[0][1] + arr[1][0];
                                dy[1][1] = min(arr[0][1] + arr[1][1] , min( arr[0][1]+arr[0][2]+arr[1][1],arr[0][1]+ arr[1][0] + arr[1][1]));
                                dy[1][2] = min( min(arr[0][1] + arr[1][2],arr[0][1]+arr[0][2]+arr[1][2]) , min( arr[0][1]+arr[1][1]+arr[1][2], arr[0][1]+arr[1][0]+arr[1][1]+arr[1][2]));
                                dy[0][0] =dy[1][0];
                                dy[0][1] =dy[1][1];
                                dy[0][2] =dy[1][2];
                                arr[0][0] = arr[1][0];
                                arr[0][1] = arr[1][1];
                                arr[0][2] = arr[1][2];
                        }
                        else{
                                int temp = min(dy[0][0]+arr[1][0], dy[0][1]+arr[1][0]);
                                dy[1][0] = temp;
                                temp = min( min(dy[0][0] + arr[1][1], dy[0][1] + arr[1][1]), min( dy[0][2]+ arr[1][1] , dy[1][0] + arr[1][1]));
                                dy[1][1] = temp;
                                temp = min( min(dy[1][1]+arr[1][2], dy[0][1]+arr[1][2]), dy[0][2]+arr[1][2]);
                                dy[1][2] = temp;
                                dy[0][0] = dy[1][0];
                                dy[0][1] = dy[1][1];
                                dy[0][2] = dy[1][2];
                        }
                }
                cout<<k<<". "<<dy[1][1]<<endl;
                k++;
        }
}