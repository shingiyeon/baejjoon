//# Author : nuclear852 ========================#
//# Solution : 2108241 =========================#
//# Time Stamp : 2016-03-05 00:53:35 ===========#
//# Problem Title : 보물 =====================#
//# Language : C++98 ===========================#

#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int a, int b){
        return a>b;
}

int main(void){
        int N;
        cin>>N;
        int A[N];
        int B[N];
        for(int i=0; i<N; i++)
                cin>>A[i];
        for(int i=0; i<N; i++)
                cin>>B[i];
        sort(A,A+N);
        sort(B,B+N,cmp);

        int ans=0;

        for(int i=0; i<N; i++)
                ans = ans + A[i] * B[i];
        cout<<ans<<endl;
}