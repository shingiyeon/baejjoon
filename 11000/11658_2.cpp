//# Author : nuclear852 ========================#
//# Solution : 22487968 ========================#
//# Time Stamp : 2020-09-11 23:09:09 ===========#
//# Problem Title : 구간 합 구하기 3 =============#
//# Language : C++14 ===========================#

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
//변수
#define MAX_N 1025
int tree[MAX_N][MAX_N];
int tree_data[MAX_N][MAX_N];
int N, M, totalN;
void update_tree(int row,int col, int value) {
while (col <= N) {
tree[row][col] += value;
col += (col & -col);
}
}
int query(int row, int col) {
int ret = 0;
while (col >= 1) {
ret += tree[row][col];
col -= (col & -col);
}
return ret;
}
int main() {
ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
cin >> N >> M;
for (int i = 1; i <= N; i++) {
for (int j = 1; j <= N; j++) {
int data; cin >> data;
tree_data[i][j] = data;
update_tree(i, j, data);
}
}
for (int i = 0; i < M; i++) {
int tag; cin >> tag;
if (tag == 0) {
int row, col, value, diff;
cin >> row >> col >> value;
diff = value - tree_data[row][col];
update_tree(row,col, diff);
tree_data[row][col] = value;
}
else {
int row1, col1, row2, col2;
int ans = 0;
cin >> row1 >> col1 >> row2 >> col2;
for (int j = row1; j <= row2; j++) {
int ret2 = query(j, col2);
int ret1 = query(j,col1-1);
ans += ret2 - ret1;
}
cout << ans << "\n";
}
}
}