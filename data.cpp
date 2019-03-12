#include <stdio.h>
int main(){
	FILE* fp = fopen("./ex.txt", "w");
	for(int i=0; i<15000; i++){
		for(int j=0; j<150; j++){
			fprintf(fp, "1");
		}
		fprintf(fp,"\n");
	}
	fclose(fp);
}
