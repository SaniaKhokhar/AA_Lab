#include <bits/stdc++.h>
using namespace std;
const int n = 6;

bool bfs(int rg[n][n], int s, int t, int parent[n]){
	int vis[n];
	for(int i = 0; i < n; i++){
    	vis[i] = 0;
	}
	queue<int> q;
	q.push(s);
	vis[s] = 1;
	parent[s] = -1;
    
	while(!q.empty()){
    	int u = q.front();
    	q.pop();
    	for(int v = 0; v < n; v++){
        	if(vis[v] == 0 && rg[u][v] > 0){
            	if(v == t){
                	parent[v] = u;
                	return true;
            	}
            	q.push(v);
            	vis[v] = 1;
            	parent[v] = u;
        	}
    	}
	}
	return false;
}
int fordFulkerson(int g[][n], int s, int t){
	int rg[n][n];
	for(int u = 0; u < n; u++){
    	for(int  v = 0; v < n; v++){
        	rg[u][v] = g[u][v];
    	}
	}
    
	int parent[n];
	int max_flow =0;
    
	while(bfs(rg,s,t,parent)){
    	int path_flow = INT_MAX;
    	for(int v= t; v != s; v = parent[v]){
        	int u = parent[v];
        	path_flow = min(path_flow,rg[u][v]);
    	}
    	for(int v= t; v != s; v = parent[v]){
        	int u = parent[v];
        	rg[u][v] -= path_flow;
        	rg[v][u] += path_flow;
    	}
    	max_flow += path_flow;
	}
	return max_flow;
}
int main() {
	int g[6][6] = {
    	{0,16,13,0,0,0},
    	{0,0,10,12,0,0},
    	{0,4,0,0,14,0},
    	{0,0,9,0,0,20},
    	{0,0,0,7,0,4},
    	{0,0,0,0,0,0}
	};
	int ans = fordFulkerson(g,0,5);
    
	cout << "Max flow : " << ans << endl;
    
	return 0;
}
