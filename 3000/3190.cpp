//# Author : nuclear852 ========================#
//# Solution : 24887515 ========================#
//# Time Stamp : 2021-01-04 10:57:41 ===========#
//# Problem Title : 뱀 ======================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <vector>
#include <utility>
using namespace std;

int map[101][101];
int dir[101][101];

int ans = 0;
int N, K, L;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

vector<pair<int, pair<int, int> > > snake;

struct Query {
    int sec;
    bool LTurn;
}Q[101];

void clear_map() {
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            if(map[i][j] == 1) {
                map[i][j] = 0;
            }
        }
    }
}
/*
map[i][j] = 1 : Snake
map[i][j] = 2 : Apple
D: 0
U: 1
R: 2
L: 3
*/
int cal_dir(int dir, bool LTurn) {
    if (LTurn) {
        if(dir == 0) return 2;
        else if(dir == 1) return 3;
        else if(dir == 2) return 1;
        else return 0;
    }
    else {
        if(dir == 0) return 3;
        else if(dir == 1) return 2;
        else if(dir == 2) return 0;
        else return 1;
    }
}

void print_map(int sec) {
    printf("seconds: %d\n", sec);
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            if(map[i][j] == 0) {
                printf(" ");
            }
            else if(map[i][j] == 1) {
                printf("O");
            }
            else {
                printf("X");
            }
        }
        printf("\n");
    }
    printf("===========\n");
} 

bool isOut(int x, int y, int dir) {
    if(x + dx[dir] <= 0 || x + dx[dir] > N || y + dy[dir] <= 0 || y + dy[dir] > N) {
        return true;
    }
    return false;
}

bool isCrushed(int x, int y, int dir) {
    for(auto val: snake) {
        if(x + dx[dir] == val.second.first && y + dy[dir] == val.second.second) return true;
    }
    return false;
}

int main() {
    int x, y;
    scanf("%d%d", &N, &K);
    for(int i=0; i<K; i++) {
        scanf("%d%d", &x, &y);
        map[x][y] = 2;
    }
    scanf("%d", &L);
    for(int i=0; i<L; i++) {
        int sec; char dir; int idir;
        scanf(" %d %c", &sec, &dir);
        if(dir == 'L') idir = 1;
        else idir = 0;
        Q[i].LTurn = idir; Q[i].sec = sec;
    }
    int dir = 2; x = y = 1;
    int q_idx = 0;
    snake.push_back({dir, {x, y}});

    while(true) {
        clear_map();
        int hP = snake.size() - 1;
        int hX = snake[hP].second.first;
        int hY = snake[hP].second.second;
        int dir = snake[hP].first;
        if(Q[q_idx].sec == ans) {
            dir = cal_dir(dir, Q[q_idx].LTurn); q_idx++;
            snake[hP].first = dir;
        }
        ans++;

        if(map[hX+dx[dir]][hY+dy[dir]] == 2) {
            snake.push_back({dir, {hX+dx[dir], hY+dy[dir]}});
            for(auto val: snake) {
                map[val.second.first][val.second.second] = 1;
            }
        }
        else {
            if(isCrushed(hX, hY, dir)) break;
            for(int i = 0; i < snake.size() - 1; i++) {
                int bDir = snake[i].first;
                snake[i].first = snake[i+1].first;
                snake[i].second.first += dx[bDir];
                snake[i].second.second += dy[bDir];
                map[snake[i].second.first][snake[i].second.second] = 1;
            }
            if(isOut(hX, hY, dir)) break;
            snake[hP].second.first += dx[dir];
            snake[hP].second.second += dy[dir];
            map[snake[hP].second.first][snake[hP].second.second] = 1;
        }
        //print_map(ans);
    }
    printf("%d", ans);
}