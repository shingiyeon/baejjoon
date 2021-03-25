//# Author : nuclear852 ========================#
//# Solution : 22881553 ========================#
//# Time Stamp : 2020-09-27 23:48:02 ===========#
//# Problem Title : 구슬 탈출 2 ================#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <queue>
#include <utility>

using namespace std;

struct Point {
    int x, y;
};

bool operator==(const Point &a, const Point &b) {
    return a.x == b.x && a.y == b.y;
}

char map[13][13];
int N, M;
queue< pair< pair< Point, Point >, int > > q; 

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};


pair<Point, bool> max_distance(Point P, int dir, bool isRed) {
    int k = 0;
    bool pos = false;
    while(P.x + dx[dir] * (k+1) >= 0 && P.x + dx[dir] * (k+1) < N \
        && P.y + dy[dir] * (k+1) >= 0 && P.y + dy[dir] * (k+1) < M) {
        if(map[P.x + dx[dir] * (k+1)][P.y + dy[dir] * (k+1)] == '.') k++;
        else if(map[P.x + dx[dir] * (k+1)][P.y + dy[dir] * (k+1)] == 'O') {
            pos = true;
            break;
        }
        else {
            break;
        }
    }

    map[P.x][P.y] = '.';
    if(!pos && isRed) {
        map[P.x + dx[dir] * k][P.y + dy[dir] * k] = 'R';
    }
    else if(!pos && !isRed) {
        map[P.x + dx[dir] * k][P.y + dy[dir] * k] = 'B';
    }

    Point tmp;
    tmp.x = P.x + dx[dir] * k;
    tmp.y = P.y + dy[dir] * k;
    // if (isRed)
    //     printf("Red: %d %d -> %d %d\n", P.x, P.y, tmp.x, tmp.y);
    // else 
    //     printf("Blu: %d %d -> %d %d\n", P.x, P.y, tmp.x, tmp.y);
    return {tmp, pos};
}


int main() {
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; i++) scanf("%s", map[i]);

    Point R, B;
    Point O;

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(map[i][j] == 'R')  {
                R.x = i; R.y = j;
                map[i][j] = '.';
            }
            else if(map[i][j] == 'B') {
                B.x = i; B.y = j;
                map[i][j] = '.';
            }
            else if(map[i][j] == 'O') {
                O.x = i; O.y = j;
            }

        }
    } 

    bool pos = false;
    q.push({{R, B}, 0});
    while(!q.empty()) {
        R = q.front().first.first;
        B = q.front().first.second;
        int trial = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            //printf("%d %d==============\n", trial, i);
            map[R.x][R.y] = 'R';
            map[B.x][B.y] = 'B';
            pair<Point, bool> rP; pair<Point, bool> bP;
            if(i == 0) {
                if(R.x < B.x) {
                    rP = max_distance(R, i, true); bP = max_distance(B, i, false);
                }
                else {
                    bP = max_distance(B, i, false); rP = max_distance(R, i, true); 
                }
            }
            else if(i == 1) {
                if(R.x < B.x) {
                    bP = max_distance(B, i, false); rP = max_distance(R, i, true);
                }
                else {
                    rP = max_distance(R, i, true); bP = max_distance(B, i, false);
                }
            }
            else if(i == 2) {
                if(R.y < B.y) {
                    rP = max_distance(R, i, true); bP = max_distance(B, i, false);
                }
                else {
                    bP = max_distance(B, i, false); rP = max_distance(R, i, true);
                }
            }
            else {
                if(R.y < B.y) {
                    bP = max_distance(B, i, false); rP = max_distance(R, i, true);
                }
                else {
                    rP = max_distance(R, i, true); bP = max_distance(B, i, false);
                }
            }

            // for(int i=0; i<N; i++) {
            //     printf("%s\n", map[i]);
            // }
            map[rP.first.x][rP.first.y] = '.';
            map[bP.first.x][bP.first.y] = '.';

            if(bP.second) continue;
            else if(rP.second) { printf("%d" , trial + 1); return 0;}
            if(rP.first == R && bP.first == B) continue;
            if(trial >= 9) continue;
            q.push({{rP.first, bP.first}, trial+1});
        }
    }
    printf("-1");

}