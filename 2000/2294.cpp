//# Author : nuclear852 ========================#
//# Solution : 24184342 ========================#
//# Time Stamp : 2020-12-03 15:34:12 ===========#
//# Problem Title : 동전 2 ===================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <algorithm>
#define MAX 999999999
using namespace std;

int n, k;
int d[10001];
int arr[101];

int main() {
    for(int j=0; j<10001; j++) d[j] = MAX;
    d[0] = 0;
    scanf("%d%d", &n, &k);
    for(int i=1; i<=n; i++) {
        scanf("%d", &arr[i]);
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=k; j++) {
            if(arr[i] <= j) {
                d[j] = min(d[j], d[j-arr[i]] + 1);
            }
        }
    } 
    printf("%d", d[k] == MAX ? -1 : d[k]);
}