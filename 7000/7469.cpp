//# Author : nuclear852 ========================#
//# Solution : 22283602 ========================#
//# Time Stamp : 2020-09-03 23:04:49 ===========#
//# Problem Title : K번째 수 ==================#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int arr[100001];
vector<int> tree[400001];

int n, m;


vector<int> sum_tree(vector<int> left_tree, vector<int> right_tree) {
    vector<int> parent;
    int left_idx = 0;
    int right_idx = 0;

    while(left_idx != left_tree.size() || right_idx != right_tree.size()) {
        if(left_idx == left_tree.size()) {
            parent.push_back(right_tree[right_idx++]);
        }
        else if(right_idx == right_tree.size()) {
            parent.push_back(left_tree[left_idx++]);
        }
        else {
            if(left_tree[left_idx] >= right_tree[right_idx]) {
                parent.push_back(right_tree[right_idx++]);
            }
            else {
                parent.push_back(left_tree[left_idx++]);
            }
        }
    }
    return parent;
}

vector<int> init(int index, int start, int end) {
    if (start == end) {
        tree[index].push_back(arr[start]);
        return tree[index];
    }
    else if(start > end) {
        vector<int> empty;
        return empty;
    }
    int mid = (start + end) / 2;
    vector<int> left_tree = init(index * 2, start, mid);
    vector<int> right_tree = init(index * 2 + 1, mid + 1, end);
    
    return tree[index] = sum_tree(left_tree, right_tree);
}

int find(int index, int start, int end, int left, int right, int val) {
    if(left <= start && end <= right) {
        return upper_bound(tree[index].begin(), tree[index].end(), val) - tree[index].begin();
    }
    else if(right< start || end < left) return 0;
    int mid = (start + end) / 2;
    return find(index * 2, start, mid, left, right, val) + find(index * 2 + 1, mid + 1, end, left, right, val);
}

// vector<int> find(int index, int start, int end, int left, int right) {
//     if(left <= start && end <= right) {
//         return tree[index];
//     }
//     else if(right < start || end < left || start == end) {
//         vector<int> empty;
//         return empty;
//     }
//     int mid = (start + end) / 2;
//     vector<int> left_tree = find(index * 2, start, mid, left, right);
//     vector<int> right_tree = find(index * 2 + 1, mid + 1, end, left, right);

//     vector<int> parent = sum_tree(left_tree, right_tree);
//     return parent;
// }

int main() {
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++) scanf("%d", &arr[i]);
    init(1, 1, n);
    int a, b, c;
    for(int i=1; i<=m; i++) {
        scanf("%d%d%d", &a, &b, &c);

        int start = -1e9, end = 1e9;
        while(start <= end) {
            int mid = (start + end) / 2;
            if(find(1, 1, n, a, b, mid) < c) start = mid + 1;
            else end = mid - 1;
        }
        printf("%d\n", start);
    }
}