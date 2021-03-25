//# Author : nuclear852 ========================#
//# Solution : 22255249 ========================#
//# Time Stamp : 2020-09-02 23:00:11 ===========#
//# Problem Title : 스위치 ====================#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <map>
#include <algorithm>

using namespace std;

int N, M;

int arr[100001];
int tree[400001];
bool lazy[400001];

int sum(int index, int start, int end, int left, int right) {
    if(lazy[index] == 1) {
        tree[index] = (end - start + 1) - tree[index];
        if(start != end) {
            lazy[index * 2] = !lazy[index * 2];
            lazy[index * 2 + 1] = !lazy[index * 2 + 1];
        }
        lazy[index] = 0;
    }

    if(left <= start && end <= right) {
        return tree[index];
    }
    else if(right < start || end < left) {
        return 0;
    }
    int mid = (start + end) / 2;
    return sum(index * 2, start, mid, left, right) + sum(index * 2 + 1, mid + 1, end, left, right);
}

void update(int index, int start, int end, int left, int right) {
    if(lazy[index] == 1) {
        tree[index] = (end - start + 1) - tree[index];
        if(start != end) {
            lazy[index * 2] = !lazy[index * 2];
            lazy[index * 2 + 1] = !lazy[index * 2 + 1];
        }
        lazy[index] = 0;
    }

    if(right < start || end < left) return;

    if(left <= start && end <= right) {
        tree[index] = (end - start + 1) - tree[index];
        if(start!=end) {
            lazy[index * 2] = !lazy[index * 2];
            lazy[index * 2 + 1] = !lazy[index * 2 + 1];
        }
        return;
    }

    int mid = (start + end) / 2;
    update(index * 2, start, mid, left, right);
    update(index * 2 + 1, mid + 1, end, left, right);
    tree[index] = tree[index * 2] + tree[index * 2 + 1];
}

int main() {
    int a, b, c;
    scanf("%d%d", &N, &M);
    for(int i=1; i<=M; i++) {
        scanf("%d%d%d", &a, &b, &c);
        if(!a){
            update(1, 1, N, b, c);
        }
        else {
            printf("%d\n", sum(1, 1, N, b, c));
        }
    }
}