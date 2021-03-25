//# Author : nuclear852 ========================#
//# Solution : 23715867 ========================#
//# Time Stamp : 2020-11-07 22:51:02 ===========#
//# Problem Title : 줄 세우기 ==================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int N;

int arr[101010];
int Q[101010];
int tree[404040];
int ans[101010];
vector<int> num;

void update(int index, int start, int end, int cur, int diff) {
    if(cur < start || cur > end) return;
    if(start <= cur && cur <= end) {
        tree[index] += diff;
    }
    if(start == end) return;
    int mid = (start + end) / 2;
    update(index * 2, start, mid , cur, diff);
    update(index * 2 +1 , mid + 1, end , cur, diff);
}

int find(int index ,int start, int end, int left, int right) {
    if(left <= start && end <= right) {
        return tree[index];
    }
    if(left > end || start > right) {
        return 0;
    }
    if(start == end) return 0;
    int mid = (start + end) / 2;
    return find(index * 2 , start , mid , left, right) + find(index * 2 +1, mid + 1, end, left, right);
}

int binary_find(int left, int right, int value) {
    if(left > right) {
        update(1, 1, N, left, -1);
        return left;
    }
    int mid = (left + right) / 2;
    int val = find(1, 1, N, 1, mid);
    if(val >= value) {
        return binary_find(left, mid - 1, value);
    }
    else 
        return binary_find(mid + 1, right, value);
}


int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr+1, arr+N+1);
    int index = 0;
    for(int i=1; i<=N; i++) {
        if(i==1) {
            update(1, 1, N, ++index, 1);
            num.push_back(arr[i]);
        }
        else {
            if(arr[i] != arr[i-1]) {
                update(1, 1, N, ++index, 1);
                num.push_back(arr[i]);
            }
            else {
                update(1, 1, N, index, 1);
            }
        }
    }
    for(int i=1; i<=N; i++) {
        scanf("%d", &Q[i]);
    }

    for(int i=N; i>=1; i--) {
        ans[i] = binary_find(1, index, Q[i] + 1);
    }
    // for(int i=0; i<index; i++) {
    //     printf("%d\n", num[i]);
    // }
    // for(int i=1; i<=N; i++) {
    //     printf("%d\n", ans[i]);
    // }
    for(int i=1; i<=N; i++) {
        printf("%d\n", num[ans[i]-1]);
    }

}