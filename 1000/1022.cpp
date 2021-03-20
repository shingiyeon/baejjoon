#include <stdio.h>

int arr[100][100];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int main(){
	int r1, c1, r2, c2; scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
	
	int x = 0, y = 0, num = 1;
	int moveon = 1;
	int idx = 0;
	if(r1<=x && x<=r2 && c1<=y && y<=c2)
		arr[x-r1][y-c1] = num;
		
	while(1){
		for(int i = 0; i < moveon; i++)
		{
			num++;
			x = x + dx[idx];
			y = y + dy[idx];
			if(r1<=x && x<=r2 && c1<=y && y<=c2){
				arr[x-r1][y-c1] = num;
			}
		}
		if(idx==1 || idx == 3) moveon += 1;
		idx = (idx+1)%4;
		if(x==5000&&y==5001)
			break;
	}
	char tmp[5] = "%1d ";
	int max = 1;
	for(int i=0; i<=r2-r1; i++){
		for(int j=0; j<100; j++){
			idx = 1;
			int temp = arr[i][j];
			while(temp/10){
				temp /= 10;
				idx += 1;
			}
			if(idx>max) max=idx;
		}
	}
	tmp[1] = max + '0';
	for(int i=0; i<=r2-r1; i++){
		for(int j=0; j<100; j++){
			if(arr[i][j]!=0)
				printf(tmp, arr[i][j]);
		}
		printf("\n");
	}
	
	
}
