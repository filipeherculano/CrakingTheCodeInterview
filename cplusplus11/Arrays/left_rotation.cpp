#include <bits/stdc++.h>

using namespace std;

int n, d, arr[1000001];

int main(){
	scanf("%d %d",&n,&d);
	for(int i = 0; i < n; ++i) scanf("%d",&arr[i]);
	for(int i = 0, j = d; i < n; ++i) 
		printf("%d ", arr[(j+i)%n]);
	puts("");
	return 0;
}
