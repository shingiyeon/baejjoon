#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
	char str[4];int arr[3]; for(int i=0; i<3; i++) scanf("%d", &arr[i]);
	sort(arr,arr+3); scanf("%s", str);
	for(int i=0; i<3; i++) printf("%d ", arr[str[i]-'A']);	
}
