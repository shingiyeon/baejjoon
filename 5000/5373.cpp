//# Author : nuclear852 ========================#
//# Solution : 24886153 ========================#
//# Time Stamp : 2021-01-04 09:29:11 ===========#
//# Problem Title : 큐빙 =====================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> p;
typedef pair<int, p> pp;

int T;
int cube[6][3][3];


vector<pp> getRow(int face, int row, bool forward) {
    vector<pp> v;
    if(forward) {
        for(int i=0; i<=2; i++) {
            v.push_back({face, {row, i}});
        }
    }
    else {
        for(int i=2; i>=0; i--) {
            v.push_back({face, {row, i}});
        }
    }
    return v;
}

vector<pp> getCol(int face, int col, bool forward) {
    vector<pp> v;
    if(forward) {
        for(int i=0; i<=2; i++) {
            v.push_back({face, {i, col}});
        }
    }
    else {
        for(int i=2; i>=0; i--) {
            v.push_back({face, {i, col}});
        }
    }
    return v;
}

void rotate(vector< vector<pp> > v) {
    vector< vector<int> > t;
    for(int i=1; i<v.size(); i++) {
        vector<int> tmp;
        for(int j=0; j<3; j++) {
            int cF = v[i][j].first;
            int cRow = v[i][j].second.first;
            int cCol = v[i][j].second.second;
            tmp.push_back(cube[cF][cRow][cCol]);
        }
        t.push_back(tmp);
    }
    vector<int> first;
    for(auto val: v[0]) {
        first.push_back(cube[val.first][val.second.first][val.second.second]);
    }
    t.push_back(first);

    for(int i=0; i<v.size(); i++) {
        for(int j=0; j<3; j++) {
            int cF = v[i][j].first;
            int cRow = v[i][j].second.first;
            int cCol = v[i][j].second.second;
            cube[cF][cRow][cCol] = t[i][j];
        }
    }
}
int rev(int num) {
    if(num == 0) return 2;
    else return 0;
}
vector< vector<pp> > clockRev(vector< vector<pp> > v) {
    vector< vector<pp> > rv;
    for(int i=v.size()-1; i>=0; i--) rv.push_back(v[i]);
    return rv;
}
void control(int face, bool c) {
    vector< vector<pp> > v;
    vector< vector<pp> > fv;
    if(face == 0) {
        v.push_back(getRow(5, 0, true));
        v.push_back(getRow(1, 0, true));
        v.push_back(getRow(2, 0, true));
        v.push_back(getRow(4, 0, true));
    }
    else if(face == 3) {
        v.push_back(getRow(5, 2, true));
        v.push_back(getRow(4, 2, true));
        v.push_back(getRow(2, 2, true));
        v.push_back(getRow(1, 2, true));
    }
    else if(face == 1) {
        v.push_back(getRow(0, 2, true));
        v.push_back(getCol(5, 2, false));
        v.push_back(getRow(3, 0, true));
        v.push_back(getCol(2, 0, true));
    }
    else if(face == 4) {
        v.push_back(getRow(0, 0, false));
        v.push_back(getCol(2, 2, false));
        v.push_back(getRow(3, 2, false));
        v.push_back(getCol(5, 0, true));
    }
    else if (face == 5) {
        v.push_back(getCol(1, 0, true));
        v.push_back(getCol(0, 0, true));
        v.push_back(getCol(4, 2, false));
        v.push_back(getCol(3, 2, true));
    }
    else {
        v.push_back(getCol(1, 2, true));
        v.push_back(getCol(3, 0, true));
        v.push_back(getCol(4, 0, false));
        v.push_back(getCol(0, 2, true));
    }

    if(face != 3) {
        fv.push_back(getRow(face, 0, true));
        fv.push_back(getCol(face, 0, false));
        fv.push_back(getRow(face, 2, false));
        fv.push_back(getCol(face, 2, true));
    }
    else {
        fv.push_back(getRow(face, 0, false));
        fv.push_back(getCol(face, 2, false));
        fv.push_back(getRow(face, 2, true));
        fv.push_back(getCol(face, 0, true));
    }

    if(!c)  {
        v = clockRev(v);
        fv = clockRev(fv);
    }
    rotate(v);
    rotate(fv);
}

/*
U 위 : 0 : White   
F 앞 : 1 : Red
R 오 : 2 : Blue
D 밑 : 3 : Yellow
B 뒤 : 4 : Orange
L 왼 : 5 : Green
*/
int main() {
    scanf("%d", &T);
    while(T--) {
        int n; scanf("%d", &n);
        for(int i=0; i<6; i++){
            for(int j=0; j<3; j++) {
                for(int k=0; k<3; k++) {
                    cube[i][j][k] = i;
                }
            }
        }
        while(n--) {
            char tmp[5]; scanf("%s", tmp);
            bool c = true; int face;
            if(tmp[1] == '-') c = false;
            if(tmp[0] == 'U') face = 0;
            else if(tmp[0] == 'F') face = 1;
            else if(tmp[0] == 'R') face = 2;
            else if(tmp[0] == 'D') face = 3;
            else if(tmp[0] == 'B') face = 4;
            else face = 5;
            control(face, c);
        }
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(cube[0][i][j] == 0) printf("w");
                else if(cube[0][i][j] == 1) printf("r");
                else if(cube[0][i][j] == 2) printf("b");
                else if(cube[0][i][j] == 3) printf("y");
                else if(cube[0][i][j] == 4) printf("o");
                else printf("g");
            }
            printf("\n");
        }
    }
}