#include <stdio.h>

short map[2187][2187];

int num[3];

void divide(int x, int y, int size){
	if(size==1){
		num[map[x][y]+1]++;
		return;
	}
	
	int comp = map[x][y];
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			if(comp != map[x+i][y+j])
			{
				for(int k=0; k<3; k++){
					for(int l=0; l<3; l++){
						divide(x + size/3*k, y + size/3*l, size/3);
					}
				}
				return;
			}
		}
	}
	
	num[comp+1]++;
}

int main(){
	int N; scanf("%d",&N);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++)
			scanf("%d", &map[i][j]);
	}
	divide(0,0,N);
	for(int i=0; i<3; i++)
		printf("%d\n", num[i]);
}
