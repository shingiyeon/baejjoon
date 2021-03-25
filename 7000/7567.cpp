//# Author : nuclear852 ========================#
//# Solution : 12619548 ========================#
//# Time Stamp : 2019-04-06 16:36:17 ===========#
//# Problem Title : 그릇 =====================#
//# Language : C++98 ===========================#

#include <stdio.h>
#include <vector>
using namespace std;
int main(){
	int num = 0; vector<char> v;
	char arr[51]; scanf("%s", arr);
	for(int i=0; arr[i]!='\0'; i++){
		if(arr[i]=='('){
			if(v.size()==0 || v[v.size()-1]==')')
				num += 10;
			else	num += 5;
			v.push_back('(');
		}
		else{
			if(v.size()==0 || v[v.size()-1]=='(')
				num += 10;
			else	num += 5;
			v.push_back(')');
		}
	}
	printf("%d", num);
}