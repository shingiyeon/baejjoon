//# Author : nuclear852 ========================#
//# Solution : 2176589 =========================#
//# Time Stamp : 2016-03-08 23:34:35 ===========#
//# Problem Title : 피타고라스 기댓값 ==============#
//# Language : C++98 ===========================#

#include <bits/stdc++.h>
using namespace std;
 
int T, N, M;
int A[1004], B[1004];
 
int main()
{
    for (scanf("%d", &T);T--;){
        scanf("%d%d", &N, &M);
        for (int i=1;i<=N;i++) A[i] = B[i] = 0;
        for (int i=1;i<=M;i++){
            int a, b, p, q;
            scanf("%d%d%d%d", &a, &b, &p, &q);
            A[a] += p; B[a] += q;
            A[b] += q; B[b] += p;
        }
        double mx = 0, mn = 2e9;
        for (int i=1;i<=N;i++){
            double v = A[i] + B[i] ? ((double)(A[i]*A[i]) / (A[i]*A[i] + B[i]*B[i])) : 0;
            mx = max(mx, v);
            mn = min(mn, v);
        }
        printf("%d\n%d\n", (int)(mx * 1000 + 1e-8), (int)(mn * 1000 + 1e-8));
    }
}