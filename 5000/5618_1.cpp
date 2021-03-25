//# Author : nuclear852 ========================#
//# Solution : 5153208 =========================#
//# Time Stamp : 2017-02-03 10:47:41 ===========#
//# Problem Title : 공약수 ====================#
//# Language : C++98 ===========================#

#include <stdio.h>
int main(){
        int n; scanf("%d",&n);
        int arr[3]; for(int i=0; i<n; i++) scanf("%d",&arr[i]);
        for(int i=1; i<=100000000; i++){
                bool pos = 1;
                for(int j=0; j<n; j++) if(arr[j]%i != 0) pos = 0;
                if(pos) printf("%d\n",i);
        }
}