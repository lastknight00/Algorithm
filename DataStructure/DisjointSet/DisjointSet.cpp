#include<cstdio>
int p[1000001];
int n, m, o, a, b;
void init(int n) {
	for(int i = 0; i <= n; i++) p[i] = i;
}
int find(int x) {
	if(p[x] == x) return x;
	p[x] = find(p[x]);
	return p[x];
}
void Union(int x, int y) {
	int px = find(x);
	int py = find(y);
	p[py] = px;
}
int main() {
	scanf("%d %d", &n, &m);
	init(n);
	while(m--) {
		scanf("%d %d %d", &o, &a, &b);
		if(o) {
			printf("%s\n",(find(a) == find(b)) ? "YES" : "NO");
		} else {
			Union(a,b);
		}
	}
}
