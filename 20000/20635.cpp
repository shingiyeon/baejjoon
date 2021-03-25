#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
int aMatched[1001], bMatched[1001];
vector<int> adj[2001];
int lv[1001];
int checked[1001];
int component[2001];

void bfs() {
	    queue<int> q;
	        for(int i=1; i<=N; i++) {
			        if(aMatched[i] == -1) {
					            lv[i] = 0;
						                q.push(i);
								        }
				        else {
						            lv[i] = -5;
							            }
					    }
		    while(!q.empty()) {
			            int cur = q.front(); q.pop();
				            for(auto next: adj[cur]) {
						                next = next - 1000;
								            if(bMatched[next] != -1 && lv[bMatched[next]] == -5) {
										                    lv[bMatched[next]] = lv[cur] + 1;
												                    q.push(bMatched[next]);
														                }
									            }
					        }
}

bool dfs(int cur) {
	    for(int &i = checked[cur]; i < adj[cur].size(); i++) {
		            int next = adj[cur][i] - 1000;
			            if(bMatched[next] == -1) {
					                aMatched[cur] = next;
							            bMatched[next] = cur;
								                return 1;
										        }
				            else if(lv[bMatched[next]] == lv[cur] + 1 && dfs(bMatched[next])) {
						                aMatched[cur] = next;
								            bMatched[next] = cur;
									                return 2;
											        }
					        }
	        return 0;
}

int main() {
	    cin.tie(NULL); cout.tie(NULL);
	        ios::sync_with_stdio(false);
		    cin >> N >> M;
		        for(int i=1; i<=M; i++) {
				        int a, b; cin >> a >> b;
					        adj[a].push_back(b+1000);
						        adj[b+1000].push_back(a);
							    }
			    for(int i=1; i<=N; i++) {
				            aMatched[i] = bMatched[i] = -1;
					        }
			        int min_val = 0, max_val = 0;
				    while(true) {
					            int flow = 0;
						            for(int i=1; i<=N; i++) checked[i] = 0;
							            bfs();
								            for(int i=1; i<=N; i++) {
										                if(aMatched[i] == -1 && dfs(i)) {
													                flow++;
															            }
												        }
									            if(!flow) break;
										            min_val += flow;
											        }

				        queue<int> q; int c = 0;
					    for(int i=1; i<=2000; i++) {
						            if(component[i] == 0 && adj[i].size()) {
								                c++;
										            q.push(i);
											                component[i] = c;
													            while(!q.empty()) {
															                    int cur = q.front(); q.pop();
																	                    for(auto next: adj[cur]) {
																				                        if(!component[next]) {
																								                        component[next] = c;
																											                        q.push(next);
																														                    }
																							                }
																			                }
														            }
							        }

					        cout <<  M-min_val << " " << M - c;
}
