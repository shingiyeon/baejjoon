#include <stdio.h>

int arr[102][102];
int main(){
    int N, M; scanf("%d%d", &N, &M);
    
    int ans = 2 * N * M;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            for(int k=0; k<4; k++){
                if( arr[i][j] > arr[i+dx[k]][j+dy[k]]){
                    ans += arr[i][j] - arr[i+dx[k]][j+dy[k]];
                }
            }
        }
    }
    printf("%d", ans);
}