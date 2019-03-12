#include <stdio.h>
int main(){
	int t; scanf("%d", &t);
	while(t--){
		bool dy[201];
		char arr[201];
		int N=1;
		scanf("%s", arr+1);
		int len = 1;
		for(;arr[len]!='\0';len++)
			dy[len] = 0;
			
		dy[0] = 1;
		for(int i=1; i<len; i++){
			if(i>=1){
				if(arr[i]=='1' && arr[i-1]=='0')
					dy[i] = dy[i]? dy[i] : dy[i-2];
			}
			if(i>=3){
				if(arr[i]=='1'){
					int j = i;
					while(arr[j]=='1' && j!=0){
						j--;
					}
					int zeronum = 0;
					if(j>=2){
						while(arr[j]=='0' && j>1){
							zeronum++;
							j--;
						}
					}
					if(j>=0){
						if(arr[j]=='1' && zeronum>=2)
							dy[i] = dy[i]? dy[i]: dy[j-1];
					}
				}
			}
		}
		printf("%s\n", dy[len-1]? "YES": "NO");
	}	
}
