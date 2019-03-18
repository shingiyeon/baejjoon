#include <stdio.h>
int main(){
	FILE *fp = fopen("./input2.txt", "r");
	float sum=0, suma=0;
	while(feof(fp)==0){
		float a; char b[3]; float c=0;
		fscanf(fp,"%f%s",&a,b);
		c = (float)4-(b[0]-'A');
		if(b[1]=='+') c+=0.5;
		printf("%f%f\n",a,c);
		sum += c * a;
		suma += a;
	}
	printf("%f", sum/suma);
}
