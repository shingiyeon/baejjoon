//# Author : nuclear852 ========================#
//# Solution : 26608471 ========================#
//# Time Stamp : 2021-02-21 23:02:56 ===========#
//# Problem Title : 자동차가 차주 김표준의 편을 들면? ====#
//# Language : C++17 ===========================#

#include <iostream>
#include <math.h>
using namespace std;
typedef long long ll;
int arr[1001];
double ans_val[1001];
ll ans[1001], sum[1001];
int main()  {
    cin.tie(NULL); ios::sync_with_stdio(false);
    int N; 
    cin >> N;
    for(int i=1; i<=N; i++) {
        cin >> arr[i];
        sum[i] = sum[i-1] + arr[i]; ans[i] = 1;
    }
    for(int i=1; i<=N; i++) {
        for(int j=i; j<=N; j++) {
            double avg = (double)(sum[j] - sum[i-1]) / (double)(j-i+1);
            double dSum = 0;
            for(int k=i; k<=j; k++) {
                dSum += ((double)arr[k]-avg) * ((double)arr[k]-avg) ;
            }
            double c = dSum / (j-i+1);
            if( c  > ans_val[j-i+1]) {
                ans_val[j-i+1] = c;
                ans[j-i+1] = (ll)i;
            }
        }
    }
    for(int i=1; i<=N; i++) cout << ans[i] << "\n";

}