//# Author : nuclear852 ========================#
//# Solution : 22508433 ========================#
//# Time Stamp : 2020-09-12 23:17:10 ===========#
//# Problem Title : 구간 합 구하기 3 =============#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int arr[1025][1025];
vector<int> tree[4100];

void initY(int indexX, int xs, int xe, int indexY, int ys, int ye) {
	if (ys == ye) {
		if(xs == xe) tree[indexX][indexY] = arr[xs][ys];
		else tree[indexX][indexY] = tree[indexX * 2][indexY] + tree[indexX*2+1][indexY];
	}
	else {
		int mid = (ys + ye) / 2;
		initY(indexX, xs, xe, indexY * 2, ys, mid);
		initY(indexX, xs, xe, indexY * 2 + 1, mid + 1, ye);
		tree[indexX][indexY] = tree[indexX][indexY * 2] + tree[indexX][indexY * 2 + 1];
	}
}

void initX(int indexX, int s, int e) {
	if(s == e) {
		initY(indexX, s, e, 1, 1, N);
		return;
	}
	int mid = (s + e) / 2;
	initX(indexX * 2, s, mid);
	initX(indexX * 2 + 1, mid + 1, e);
	initY(indexX, s, e, 1, 1, N);
	return;
}

void updateY(int indexX, int indexY, int ys, int ye, int x, int y, int d) {
    if(y < ys || y > ye) return;
    if(ys == ye) {
        tree[indexX][indexY] += d;
        return;
    }
    int mid = (ys + ye) / 2;
    updateY(indexX, indexY * 2, ys, mid, x, y, d);
    updateY(indexX, indexY * 2 + 1, mid + 1, ye, x, y, d);
    tree[indexX][indexY] += d;
}

void updateX(int indexX, int xs, int xe, int x, int y, int d) {
    if(x < xs || x > xe) return;
    if(xs == xe) {
        updateY(indexX, 1, 1, N, x, y, d);
        return;
    }
    int mid = (xs + xe) / 2;
    updateX(indexX * 2, xs, mid, x, y, d);
    updateX(indexX * 2 + 1, mid + 1, xe, x, y, d);
    updateY(indexX, 1, 1, N, x, y, d);
}

int yquery(int indexX, int indexY, int ys, int ye, int yleft, int yright) {
    if (yleft <= ys && ye <= yright) return tree[indexX][indexY];
    else if(ye < yleft || ys > yright) return 0;
    if (ys == ye) return 0;
    int mid = (ys + ye) / 2;
    return yquery(indexX, indexY*2, ys, mid, yleft, yright) + yquery(indexX, indexY*2+1, mid+1, ye, yleft, yright);
}

int xquery(int indexX, int xs, int xe, int xleft, int xright, int yleft, int yright) {
    if (xleft <= xs && xe <= xright) return yquery(indexX, 1, 1, N, yleft, yright);
    else if(xe < xleft || xs > xright) return 0;
    if (xs == xe) return 0;
    int mid = (xs + xe) / 2;
    return xquery(indexX * 2, xs, mid, xleft, xright, yleft, yright) + xquery(indexX * 2 + 1, mid+1, xe, xleft, xright, yleft, yright);
}

int main() {
    scanf("%d%d", &N, &M);

    for(int i=1; i<=4100; i++) tree[i].resize(4100);

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    
    initX(1, 1, N);

    int c, x1, y1, x2, y2, val;
    for(int i=1; i<=M; i++) {
        scanf("%d", &c);
        if(c) {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            if(x2 < x1) {
                swap(x1, x2);
            }
            if(y2 < y1) {
                swap(y1, y2);
            }
            printf("%d\n", xquery(1, 1, N, x1, x2, y1, y2));
        }
        else {
            scanf("%d%d%d", &x1, &y1, &val);
            updateX(1, 1, N, x1, y1, val - arr[x1][y1]);
            arr[x1][y1] = val;
        }
    }
    
}