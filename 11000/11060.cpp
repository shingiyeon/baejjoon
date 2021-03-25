//# Author : nuclear852 ========================#
//# Solution : 4982140 =========================#
//# Time Stamp : 2017-01-10 14:53:32 ===========#
//# Problem Title : 점프 점프 ==================#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>

using namespace std;

int dyna[1001];
int arr[1001];
int N;
void dy(int s,int n)
{
        if(s==N)
        {
                if(n < dyna[N])
                        dyna[N] = n;
        }
        else if(n <= dyna[s]){
                dyna[s] = n;
                for(int i=1; i<=arr[s]; i++){
                        if(n+1 < dyna[s+i])
                                dy(s+i,n+1);
                }
        }
}

int main(){
        scanf("%d",&N);
        for(int i=1; i<=N; i++){
                scanf("%d",&arr[i]);
                dyna[i] = 99999999;
        }
        dy(1,0);
        if(dyna[N] > 90000)
                cout<<"-1"<<endl;
        else
                cout<<dyna[N]<<endl;
}