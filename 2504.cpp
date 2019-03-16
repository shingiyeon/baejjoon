#include <stdio.h>
#include <stack>
#include <vector>
using namespace std;
vector<int> v;
stack<int> s;
bool pos = 1;
int main(){
	char a[31]; scanf("%s", a);
	for(int i=0; a[i]!='\0'; i++){
		if(a[i]=='(')
			s.push(-2);
		else if(a[i]=='[')
			s.push(-3);
		else if(a[i]==')'){
			if(!s.size()){
				pos = 0; break;
			}
			while(s.top()!=-2){
				v.push_back(s.top());
				s.pop();
				if(!s.size()) { break;}
			}
			if(!s.size()){
				pos = 0; break;
			}
			if(s.top()==-3){
				pos=0; break;
			}
			s.pop();
			if(!v.size())
				s.push(2);
			else if(v.size()==1){
				s.push(v[0]*2); v.clear();
			}
			else{
				int sum = 0;
				for(int j=0; j<v.size(); j++)
					sum += v[j] * 2;
				s.push(sum);
				v.clear();
			}
		}
		else if(a[i] == ']'){
			if(!s.size()){
				pos = 0; break;
			}
			while(s.top()!=-3 && s.size()){
				v.push_back(s.top());
				s.pop();
				if(!s.size()) break;
			}
			if(!s.size()){
				pos = 0; break;
			}
			if(s.top()==-2){
				pos=0; break;
			}
			s.pop();
			if(!v.size())
				s.push(3);
			else if(v.size()==1){
				s.push(v[0]*3); v.clear();
			}
			else{
				int sum = 0;
				for(int j=0; j<v.size(); j++)
					sum += v[j] * 3;
				s.push(sum);
				v.clear();
			}
		}
	}
	while(s.size()!=0){
		v.push_back(s.top());
		s.pop();
	}
	int sum = 0;
	for(int i=0; i<v.size(); i++){
		if(v[i]==-2 || v[i]==-3)
			pos = 0;
		else
			sum += v[i];
	}
	printf("%d", pos? sum : pos );
	
}
