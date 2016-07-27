#include<cstdio>
bool d[101][101], e[101][101];
int n, m, x, y;
int main() {
	scanf("%d %d", &n, &m);
	while(m--) {
		scanf("%d %d", &x, &y);
		d[x][y] = true;
		e[y][x] = true;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			for(int k = 1; k <= n; k++) {
				d[j][k] |= d[j][i] & d[i][k];
				e[j][k] |= e[j][i] & e[i][k];
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		int c = 0;
		for(int j = 1; j <= n; j++) {
			if(!d[i][j] && !e[i][j]) {
				c++;
			}
		}
		printf("%d\n", c - 1);
	}
}
