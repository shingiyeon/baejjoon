//# Author : nuclear852 ========================#
//# Solution : 5155760 =========================#
//# Time Stamp : 2017-02-03 17:39:06 ===========#
//# Problem Title : 공약수 ====================#
//# Language : C++98 ===========================#

#include <stdio.h>
#include <iostream>
#include <map>
#include <math.h>
using namespace std;
int main(){
        int n; scanf("%d",&n);
        int arr[3]; for(int i=0; i<n; i++) scanf("%d",&arr[i]);
        map<int, int> m;
        for(int j=0; j<n; j++){
                for(int i=1; i<=sqrt(arr[j]); i++){
                        if(arr[j]%i == 0){
                                m[i]++;
                                if(arr[j]/i != i)
                                        m[arr[j]/i]++;
                        }
                }
        }

        map<int, int>::iterator iter;
        for(iter = m.begin(); iter != m.end(); iter++){

                if(iter->second == n) printf("%d\n",iter->first);
        }
}