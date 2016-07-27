#include<cstdio>
#include<algorithm>
#define INF 999999999
int n, m, x, y;
int d[101][101];
void init(int n) {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			d[i][j] = INF;
		}
	}
}
int floyd(int n) {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			for(int k = 1; k <= n; k++) {
				d[j][k] = std::min(d[j][i] + d[i][k], d[j][k]);
			}
		}
	}
}
int showMinW(int n) {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			printf("%d ", (d[i][j] == INF) ? 0 : d[i][j]);
		}
		printf("\n");
	}
}
int main() {
	scanf("%d %d", &n, &m);
	init(n);
	while(m--) {
		scanf("%d %d", &x, &y);
		d[x][y] = 1;
	}
	floyd(n);
	showMinW(n);
}
