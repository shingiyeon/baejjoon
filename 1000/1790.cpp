//# Author : nuclear852 ========================#
//# Solution : 5174233 =========================#
//# Time Stamp : 2017-02-07 11:28:42 ===========#
//# Problem Title : 수 이어 쓰기 2 ==============#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(){
        long long N, K; cin>>N>>K;

        long long temp = 1; long long gae = 1; long long num = 0;
        while( N >= (temp*10) ){
                num += temp * 9 * gae;
                gae++; temp*=10;
        }
        num += (N-temp+1)*gae;
        if( K>num ) {cout<<"-1"; return 0;}
        temp=1; gae=1; num=0;
        while(K > num+(temp*9*gae)){
                num += temp*9*gae;
                gae++; temp*=10;
        }
        K -= (num+1);
        for(long long i=0; i<gae; i++){
                if( (K-i)%gae == 0){
                        if( i== 0) { cout<<(long long)((K/(gae*temp))+1)%10; break;}
                        else { cout<<(long long)((K/(gae*temp))%10); break;}
                }
                temp /= 10;
        }

}