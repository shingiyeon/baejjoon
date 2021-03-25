//# Author : nuclear852 ========================#
//# Solution : 4993601 =========================#
//# Time Stamp : 2017-01-11 17:10:15 ===========#
//# Problem Title : 기타리스트 ==================#
//# Language : C++98 ===========================#

#include <iostream>
using namespace std;
int N, S, M;
int arr[101];
bool dy[101][1001];

void dyna(int num)
{
        for(int i=0; i<=M; i++)
        {
                if(dy[num-1][i] == 1)
                {
                        if( i+arr[num] <= M)
                                dy[num][i+arr[num]] = 1;
                        if( i-arr[num] >= 0)
                                dy[num][i-arr[num]] = 1;
                }
        }
}
int main(void){
        cin>>N>>S>>M;
        for(int i=1; i<=N; i++)
                cin>>arr[i];
        for(int i=0; i<101; i++)
                for(int j=0; j<=1000; j++)
                        dy[i][j] = 0;
        dy[0][S] = 1;
        for(int i=1; i<=N; i++)
                dyna(i);
        int ans = -1;
        for(int i=0; i<=M; i++)
        {
                if(dy[N][i] == 1)
                        ans = i;
        }
        cout<<ans<<endl;
}