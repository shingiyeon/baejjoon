//# Author : nuclear852 ========================#
//# Solution : 2213015 =========================#
//# Time Stamp : 2016-03-10 20:28:50 ===========#
//# Problem Title : 1학년 ====================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int main(void){
        int N;
        cin>>N;
        int arr[N];
        unsigned long long dy[100][21];
        for(int i=0; i<=99; i++)
                for(int j=0; j<=20; j++)
                        dy[i][j] = 0;
        for(int i=0; i<N; i++)
                cin>>arr[i];
        dy[0][arr[0]] = 1;
        for(int i=1; i<N-1; i++)
        {
                for(int j=0; j<=20; j++)
                {
                        if(j-arr[i]>=0)
                                dy[i][j] = dy[i][j] + dy[i-1][j-arr[i]];
                        if(j+arr[i]<=20)
                                dy[i][j] = dy[i][j] + dy[i-1][j+arr[i]];
                }
        }
        cout<<dy[N-2][arr[N-1]]<<endl;
}