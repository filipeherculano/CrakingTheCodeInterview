#include <bits/stdc++.h>

using namespace std;

int dx[] = {-1,-1,-1,0,1,1,1}, dy[] = {-1,0,1,0,-1,0,1}, mat[6][6];

bool check(int i, int j){
	return i >= 0 && i < 6 && j >= 0 && j < 6;
}

int main(){
	int ans = -1000;
	for(int i = 0; i < 6; ++i) 
		for(int j = 0; j < 6; ++j)
			scanf("%d",&mat[i][j]);

	for(int i = 0; i < 6; ++i) {
		for(int j = 0; j < 6; ++j){
			int cnt = 0;
			for(int z = 0; z < 7; ++z){
				if(check(i+dx[z],j+dy[z])) 
					cnt += mat[i+dx[z]][j+dy[z]];
				else 
					cnt -= 100000;
			}
			ans = max(ans, cnt);
		}
	}
	
	cout << ans << endl;
	return 0;
}
