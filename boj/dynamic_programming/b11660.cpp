#define dRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std; 

int main(){
	int n, m, i, j, x1, x2, y1, y2, p[1030][1030]; 
	
	scanf("%d %d",&n,&m); 
	
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			scanf("%d", &p[i][j]); 
	
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			p[i][j] += p[i - 1][j]; 
	
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			p[i][j] += p[i][j - 1]; 
	
	for (i = 0; i < m; i++){
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2); 
		
		printf("%d\n", p[x2][y2] - p[x1 - 1][y2] - p[x2][y1 - 1] + p[x1 - 1][y1 - 1]); 
	}
	
	return 0; 
}