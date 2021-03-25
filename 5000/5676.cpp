//# Author : nuclear852 ========================#
//# Solution : 22309117 ========================#
//# Time Stamp : 2020-09-04 22:42:39 ===========#
//# Problem Title : 음주 코딩 ==================#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <utility>

using namespace std;

int N, K;
int arr[100001];
pair<int, int> tree[1000008];

pair<int, int> init(int index, int start, int end) {
    if(start==end) {
        if(arr[start] == 0) {
            return tree[index] = {1, 1};
        }        
        return tree[index] = {arr[start], 0};
    }
    else if(start > end) {
        return {1, 0};
    }
    int mid = (start + end) / 2;
    pair<int, int> left_tree = init(index * 2, start, mid);
    pair<int, int> right_tree = init(index * 2 + 1, mid + 1, end);
    return tree[index] = {left_tree.first * right_tree.first, left_tree.second + right_tree.second};
}

int find(int index, int start, int end, int left, int right) {
    if(left <= start && end <= right) {
        if(tree[index].second > 0) {
            return 0;
        }
        else return tree[index].first;
    }
    else if(start > right || left > end) {
        return 1;
    }
    if(start == end) return 1;
    int mid = (start + end) / 2;
    return find(index * 2, start, mid, left, right) * find(index * 2 + 1, mid + 1, end, left, right);
}

void update(int index, int start, int end, int cur, int before, int after) {
    if(start <= cur && cur <= end) {
        if(before == 0) {
            tree[index].second -= 1;
        }
        else if(after == 0) {
            tree[index].second += 1;
            tree[index].first *= before;
        }
        else if(before != 0 && after != 0){
            tree[index].first *= before;
            tree[index].first *= after;
        }
    }
    else {
        return;
    }
    if(start == end) return;
    int mid = (start + end) / 2;
    update(index * 2, start, mid, cur, before, after);
    update(index * 2 + 1, mid + 1, end, cur, before, after);
}

int main() {
    char a;
    int b, c;
    while(scanf("%d%d", &N, &K) != EOF) {
        for(int i=0; i<=100000; i++) {
            arr[i] = 0;
        }
        for(int i=0; i<=1000000; i++) {
            tree[i].first = 1;
            tree[i].second = 0;
        }

        for(int i=1; i<=N; i++) {
            scanf("%d", &arr[i]);
            if(arr[i] > 0) arr[i] = 1;
            else if(arr[i] < 0) arr[i] = -1;
            else arr[i] = 0;
        }
        init(1, 1, N);
        
        for(int i=1; i<=K; i++) {
            scanf("\n%c %d %d",&a, &b, &c);
            if(a == 'C') {
                if(c > 0) c = 1;
                else if (c < 0) c = -1;
                else c = 0;
                update(1, 1, N, b, arr[b], c);
                arr[b] = c;
            }
            else {
                int ans = find(1, 1, N, b, c);
                if (ans>0) printf("+");
                else if (ans<0) printf("-");
                else printf("0");
            }
        }
        printf("\n");
    }
}