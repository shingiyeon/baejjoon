//# Author : nuclear852 ========================#
//# Solution : 25679549 ========================#
//# Time Stamp : 2021-01-26 09:09:42 ===========#
//# Problem Title : 수열과 쿼리 37 ==============#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <utility>
using namespace std;

int arr[100001];
pair<int, int> tree[404040];
int N, M;

void init(int index, int start, int end) {
    if(start == end) {
        if(arr[start] % 2) {
            tree[index] = {1, 0};
        }
        else {
            tree[index] = {0, 1};
        }
        return;
    }
    int mid = (start + end) / 2;
    init(index * 2, start , mid);
    init(index * 2 + 1, mid + 1, end);
    tree[index].first = tree[index * 2].first + tree[index * 2 + 1].first;
    tree[index].second = tree[index * 2].second + tree[index * 2 + 1].second;
}

void update(int index, int start, int end, int cur, pair<int, int> toval) {
    if(cur < start || cur > end) return;
    tree[index].first = tree[index].first + toval.first;
    tree[index].second = tree[index].second + toval.second;
    if(start == end) {
        return;
    }
    int mid = (start + end) / 2;
    update(index * 2, start, mid, cur, toval);
    update(index * 2 + 1, mid + 1, end, cur, toval);
}   

int find(int index, int start, int end, int left, int right, bool isOdd) {
    if(right < start || left > end) return 0;
    if(left <= start && end <= right) {
        if(isOdd) return tree[index].first;
        else return tree[index].second;
    }
    if(start == end) return 0;
    int mid = (start + end) / 2;
    return find(index * 2, start, mid, left, right, isOdd) + find(index * 2 + 1, mid + 1, end, left, right, isOdd);
}

int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        scanf("%d", &arr[i]);
    }

    init(1, 1, N);
    scanf("%d", &M);
    for(int i=0; i<M; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if(a == 1) {
            bool isOdd1 = arr[b] % 2;
            bool isOdd2 = c % 2;
            pair<int, int> tmp = {isOdd2 - isOdd1, !isOdd2 - !isOdd1};
            arr[b] = c;
            update(1, 1, N, b, tmp);
        }
        else if(a == 2) {
            printf("%d\n", find(1, 1, N, b, c, false));
        }
        else {
            printf("%d\n", find(1, 1, N, b, c, true));
        }
    }
}