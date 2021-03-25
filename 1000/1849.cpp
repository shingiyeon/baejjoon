//# Author : nuclear852 ========================#
//# Solution : 22941198 ========================#
//# Time Stamp : 2020-09-30 23:00:01 ===========#
//# Problem Title : 순열 =====================#
//# Language : C++14 ===========================#

#include <stdio.h>

using namespace std;

int N;
int tree[400010];
int input[100001];
int ans[100001];
void init(int index, int start, int end) {
    if(start == end) {
        tree[index] = 1;
        if(start == 0) tree[index] = 0;
        return;
    }
    int mid = (start + end) / 2;
    init(index * 2, start, mid);
    init(index * 2 + 1, mid + 1, end);
    tree[index] = tree[index * 2] + tree[index * 2 + 1];
}
void update(int index, int start, int end, int cur) {
    if(cur < start || end < cur) {
        return;
    }
    if(start <= cur && cur <= end) {
        tree[index]--;
    }
    if(start == end) return;
    int mid = (start + end) / 2;
    update(index * 2, start, mid, cur);
    update(index * 2 + 1, mid + 1, end, cur);
} 

int sum(int index, int start, int end, int left, int right) {
    if(left > end || start > right) return 0;
    if(left <= start && end <= right) {
        return tree[index];
    }
    if(start == end) return 0;
    int mid = (start + end) / 2;
    return sum(index * 2 , start, mid, left, right) + sum(index * 2 + 1, mid + 1, end, left, right);  
}

int binary_search(int target) {
    int start = 0;
    int end = N;
    while(start <= end) {
        int mid = (start + end) / 2;
        int temp = sum(1, 0, N, 0, mid);
        if(temp > target) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    return start;
}

int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; i++) scanf("%d", &input[i]);
    init(1, 0, N);
   

    for(int i=1; i<=N; i++) {
        int tmp = binary_search(input[i]);
        update(1, 0, N, tmp);
        ans[tmp] = i;
    }

    for(int i= 1; i<=N; i++) {
        printf("%d\n", ans[i]);
    }

}