//# Author : nuclear852 ========================#
//# Solution : 5158817 =========================#
//# Time Stamp : 2017-02-04 12:27:45 ===========#
//# Problem Title : 수 이어 쓰기 1 ==============#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(){
        int N; cin>>N; int ans = 0;
        int K = 10; int num =1;
        while( (int)(N/K)){
                ans += 9*(K/10)*num;
                K*=10; num++;
        }
        ans += (N-(K/10)+1)*(num);
        cout<<ans;
}