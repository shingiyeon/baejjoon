//# Author : nuclear852 ========================#
//# Solution : 5141164 =========================#
//# Time Stamp : 2017-02-01 13:57:44 ===========#
//# Problem Title : 수들의 합 4 ================#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;
int main(){
        map<long long,long long> mapping;
        long long n, k;
        long long ans = 0;
        long long subsum = 0; long long temp;
        mapping[0] = 1;
        cin>>n>>k;
        while(n--){
                scanf("%lld",&temp);
                subsum += temp;
                ans += mapping[subsum-k];
                mapping[subsum]++;
        }
        printf("%lld\n",ans);
}