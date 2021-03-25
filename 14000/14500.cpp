//# Author : nuclear852 ========================#
//# Solution : 12988634 ========================#
//# Time Stamp : 2019-05-01 16:14:36 ===========#
//# Problem Title : 테트로미노 ==================#
//# Language : C++98 ===========================#

#include <stdio.h>

using namespace std;
int max(int a, int b){
    return a > b? a : b;
}
int Map[2][4][500][500];
int N, M;
int main(){
	int dx[5][4] = {\
		{0,0,0,0}, {0,0,1,1}, {0,1,2,2}, {0,1,1,2}, {0,0,0,1}\
	};
	int dy[5][4] = {\
		{0,1,2,3}, {0,1,0,1}, {0,0,0,1}, {0,0,1,1}, {0,1,2,1}\
	};
	int MAX = 0;
	scanf("%d%d", &N, &M);
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			scanf("%d", &Map[0][0][i][j]);
			Map[1][0][i][M-j-1] = Map[0][0][i][j]; 
		}
	}
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            Map[0][1][j][N-1-i] = Map[0][0][i][j];
            Map[1][1][j][N-1-i] = Map[1][0][i][j];
        }
    }
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            Map[0][2][j][M-1-i] = Map[0][1][i][j];
            Map[1][2][j][M-1-i] = Map[1][1][i][j];
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            Map[0][3][j][N-1-i] = Map[0][2][i][j];
            Map[1][3][j][N-1-i] = Map[1][2][i][j];
        }
    }/*
    printf("\n\n");
    for(int i=0; i<=1; i++){
        for(int j=0; j<=3; j++){
            for(int k=0; k<max(M,N); k++){
                for(int l=0; l<max(M,N); l++){
                    printf("%d ", Map[i][j][k][l]);
                }
                printf("\n");
            }
            printf("\n");
        }
    }*/
	
	for(int l=0; l<=1; l++){
		for(int i=0; i<=3; i++){
			for(int j=0; j<max(N,M); j++){
				for(int k=0; k<max(N,M); k++){
					
					for(int di=0; di<5; di++){	
						int sum = 0;
						for(int dj=0; dj<4; dj++){
							if(j+dx[di][dj] < 0 || j+dx[di][dj]>= (i%2==0 ? N:M) ||\
								k+dy[di][dj] < 0 || k+dy[di][dj] >= (i%2==0 ? M:N))
								continue;
							sum += Map[l][i][j+dx[di][dj]][k+dy[di][dj]];
						}
						if(sum >= MAX) MAX = sum;
					}
					
				}
			}
		}
	}
	printf("%d", MAX);
	
}