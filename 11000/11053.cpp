//# Author : nuclear852 ========================#
//# Solution : 2006499 =========================#
//# Time Stamp : 2016-02-28 20:31:42 ===========#
//# Problem Title : 가장 긴 증가하는 부분 수열 ========#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(void){
        int N;
        cin>>N;
        int arr[N];
        int dy[N];
        for(int i=0; i<N; i++){
                cin>>arr[i];
                dy[i]=1;
        }
        dy[0]=1;
        for(int i=1; i<N; i++)
        {
                for(int j=0; j<i; j++)
                {
                        if( arr[i] > arr[j])
                        {
                                if( dy[j]+1 > dy[i])
                                        dy[i]=dy[j]+1;
                        }
                }
        }
        int ans=0;
        for(int i=0; i<N; i++)
                if(dy[i]>ans)
                        ans=dy[i];
        cout<<ans<<endl;
}