#include <bits/stdc++.h>

using namespace std;

int n, ans, cnt, arr[100001], order[100001];
bool vis[100001];
map<int,int> compress;

int dfs(int u, int cnt){
	vis[u] = true;
	if(!vis[arr[u]]) return dfs(arr[u],cnt+1);
	return cnt;
}

int main(){
	scanf("%d",&n); 
	for(int i = 0; i < n; ++i) 
		scanf("%d",&arr[i]), order[i] = arr[i];
	sort(order, order+n);
	for(int i = 0; i < n; ++i) compress[order[i]] = cnt++;
	for(int i = 0; i < n; ++i) arr[i] = compress[arr[i]];
	for(int i = 0; i < n; ++i)
		if(!vis[i])
			ans += dfs(i,0);
	cout << ans << endl;
	return 0;
}
