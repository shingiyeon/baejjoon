//# Author : nuclear852 ========================#
//# Solution : 5158621 =========================#
//# Time Stamp : 2017-02-04 11:24:58 ===========#
//# Problem Title : 베르트랑 공준 ================#
//# Language : C++98 ===========================#

#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main(){
        int n; scanf("%d",&n);
        bool arr[250000]; memset(arr,1,sizeof(arr));
        arr[1] = 0;
        for(int i=2; i<250000; i++){
                if(arr[i]){
                        for(int j=i*2; j<250000; j+=i)
                                arr[j] = 0;
                }
        }
        while(n!=0){
                int ans=0;
                for(int i=n+1; i<=2*n; i++) if(arr[i]) ans++;
                printf("%d\n",ans);
                scanf("%d",&n);
        }
}