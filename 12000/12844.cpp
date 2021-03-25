//# Author : nuclear852 ========================#
//# Solution : 22697343 ========================#
//# Time Stamp : 2020-09-20 23:34:45 ===========#
//# Problem Title : XOR ====================#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <algorithm>
using namespace std;

int N, M;
int arr[500001];
int tree[4000040];
int lazy[4000040];

void init(int index, int start, int end) {
    if(start == end) {
        tree[index] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    init(index * 2, start, mid);
    init(index * 2 + 1, mid + 1, end);
    tree[index] = tree[index * 2] ^ tree[index * 2 + 1];
    return;
}

int XOR(int index, int start, int end, int left, int right) {
    if(lazy[index] != 0) {
        tree[index] ^= lazy[index] * ((end - start + 1) % 2);
        if(start != end){
            lazy[index*2] ^= lazy[index];
            lazy[index*2 + 1] ^= lazy[index];
        }
        lazy[index] = 0;
    }
    if(right < start || end < left) return 0;
    if(left <= start && end <= right)
        return tree[index];
    if(start == end) return 0;
    int mid = (start + end) / 2;
    return XOR(index * 2, start, mid, left, right) ^ XOR(index * 2 + 1, mid + 1, end, left, right);
}

void update(int index, int start, int end, int left, int right, int value) {
    if(lazy[index] != 0) {
        tree[index] ^= lazy[index] * ((end - start + 1) % 2);
        if(start != end){
            lazy[index*2] ^= lazy[index];
            lazy[index*2 + 1] ^= lazy[index];
        }
        lazy[index] = 0;
    }
    if(right < start || end < left) return;
    if(left <= start && end <= right) {
        tree[index] ^= value  * ((end - start + 1) % 2);
        if(start != end) {
            lazy[index * 2] ^= value;
            lazy[index * 2 + 1] ^= value;
        }
        return;
    }
    int mid = (start + end) / 2;
    update(index * 2, start, mid, left, right, value);
    update(index * 2 + 1, mid + 1, end, left, right, value);
    tree[index] = tree[index * 2] ^ tree[index*2+1];
}

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d", &arr[i]);
    init(1, 0, N-1);
    scanf("%d", &M);
    int b, i, j, k;
    for(int a=1; a<=M; a++) {
        scanf("%d", &b);
        if(b == 1) {
            scanf("%d%d%d", &i, &j, &k);
            if(i > j) swap(i , j);
            update(1, 0, N-1, i, j, k);
        }
        else {
            scanf("%d%d", &i, &j);
            if(i > j) swap(i , j);
            printf("%d\n", XOR(1, 0, N-1, i, j));
        }
    }
}