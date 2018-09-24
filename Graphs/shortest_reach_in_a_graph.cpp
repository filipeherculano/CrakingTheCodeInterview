#include <bits/stdc++.h>

using namespace std;

int main(){
	int q, n, m, s;
	scanf("%d", &q);
	while(q--){
		scanf("%d %d", &n, &m);
		vector<int> adj[n+1];
		for(int i = 0; i < m; ++i){
			int a,b;
			scanf("%d %d", &a, &b);
			adj[a].push_back(b); adj[b].push_back(a);
		}
		scanf("%d", &s);
		vector<int> dist(n+1, 0x3f3f3f3f); dist[s] = 0;
		queue< pair<int,int> > fila; fila.push(make_pair(s,0));
		while(!fila.empty()){
			int d = fila.front().second, u = fila.front().first; fila.pop();
			for(int i = 0; i < adj[u].size(); ++i){
				if(dist[u] + 1 < dist[adj[u][i]]){
					dist[adj[u][i]] = dist[u] + 1;
					fila.push(make_pair(adj[u][i], dist[adj[u][i]]));
				}
			}
		}
		for(int i = 1; i <= n; ++i)
			if(i != s) 
				printf("%d ", (dist[i] == 0x3f3f3f3f ? -1:(6*dist[i]))); puts("");
	}
	return 0;
}





