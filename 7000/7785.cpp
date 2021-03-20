#include <stdio.h>
#include <utility>
#include <map>
#include <string>
using namespace std;

int main(){
	map<string, int> m;
	int T; scanf("%d",&T);
	while(T--){
		char name[6]; char state[6];
		scanf("%s%s",name,state);
		if(state[0]=='e')m.insert(make_pair(string(name),1));
		else if(m.find(string(name))!=m.end())m.erase(string(name));
	}
	map<string, int>::iterator iter;
	for(iter = m.end()-1; iter != m.begin()-1; iter--)
		printf("%s\n",iter->first.c_str());
	
}
