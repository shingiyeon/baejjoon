#include <stdio.h>
int main()
{
	int arr[8];
	for(int i=0; i<8; i++) scanf("%d", &arr[i]);
	bool aspos = 1;
	bool despos = 1;
	for(int i=0; i<7; i++){
		if(arr[i]>arr[i+1]) aspos = 0;
		if(arr[i]<arr[i+1]) despos = 0;
	}
	printf("%s", aspos == 1? "ascending" : (despos == 1? "descending" : "mixed"));
}
