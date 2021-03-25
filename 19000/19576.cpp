//# Author : nuclear852 ========================#
//# Solution : 22891270 ========================#
//# Time Stamp : 2020-09-28 15:45:58 ===========#
//# Problem Title : 약수 =====================#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <algorithm>

using namespace std;

int dy[5001];
int arr[5001];
int N;


int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d", &arr[i]);
    dy[0] = 1;
    sort(arr, arr+N);
    int MAX = dy[0];
    for(int i=1; i<N; i++) {
        dy[i] = 1;
        for(int j=0; j<i; j++) {
            if(!(arr[i] % arr[j])) {
                dy[i] = max(dy[i] , dy[j] + 1);
            }
        }
        MAX = max(MAX, dy[i]);
    }
    printf("%d", N - MAX);
}