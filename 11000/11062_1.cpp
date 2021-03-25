//# Author : nuclear852 ========================#
//# Solution : 2154925 =========================#
//# Time Stamp : 2016-03-07 15:38:46 ===========#
//# Problem Title : 카드 게임 ==================#
//# Language : C++98 ===========================#

#include <bits/stdc++.h>
using namespace std;
 
int T, N;
int A[1003], S[1003];
int D[1003][1003];
 
int dy(int s, int e)
{
    if (s > e) return 0;
    if (s == e) return A[s];
    int &ret = D[s][e];
    if (ret >= 0) return ret;
    ret = max(S[e] - S[s-1] - dy(s+1, e), S[e] - S[s-1] - dy(s, e-1));
    return ret;
}
 
int main()
{
    for (scanf("%d", &T);T--;){
        scanf("%d", &N);
        for (int i=1;i<=N;i++) scanf("%d", A+i), S[i] = S[i-1] + A[i];
        for (int i=1;i<=N;i++) for (int j=i;j<=N;j++) D[i][j] = -1;
        printf("%d\n", dy(1, N));
    }
}