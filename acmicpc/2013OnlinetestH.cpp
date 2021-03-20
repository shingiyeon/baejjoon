#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int m;
vector<int> adj[1001];
vector<int> aMatch, bMatch;
vector<bool> visited;

bool dfs(int a){
	if(visited[a]) return false;
	visited[a] = 1;

	for(int i=0; i<adj[a].size(); ++i){
		int b = adj[a][i];
		if(bMatch[b]==-1 || dfs(bMatch[b])){
			aMatch[a]=b;
			bMatch[b]=a;
			return true;
		}
	}

	return false;
}

int main(void)
{
	int testcase;
	cin>>testcase;

	while(testcase--)
	{
		scanf("%d",&m);
		int a, b;
		aMatch=vector<int>(m+1,-1);
		bMatch=vector<int>(m+1,-1);
		visited=vector<bool>(m+1,0);
		
		for(int i=1; i<m+1; i++)
			adj[i].clear();
		
		for(int i=0; i<m; i++)
		{
			scanf("%d%d",&a,&b);
			a++; b++;
			adj[a].push_back(b);
		}

		int size = 0;

		for(int start=1; start<m+1; ++start)
		{
			visited=vector<bool>(m+1,0);
			
			if( dfs(start))
				++size;
		}

		cout<<size<<endl;
	}
}
