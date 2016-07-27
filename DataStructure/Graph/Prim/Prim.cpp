#include<cstdio>
#include<queue>
#include<vector>
#include<stdlib.h>
#include<string.h>
#define mpair pair<int,int>
#define mp(x,y) make_pair((x),(y))
using namespace std;
vector<mpair> v[17];
priority_queue<mpair> pq;
int prim(int n) {
	int c = 0;
	bool* visited= (bool*)calloc(n, sizeof(bool));
	memset(visited, 0, sizeof(visited));
	for(int i = 0; i < v[1].size(); i++) {
		pq.push(v[1][i]);
	}
	visited[1] = true;
	for(int i = 0; i < n - 1; i++) {
		mpair mp;
		while(true) {
			mp = pq.top();
			pq.pop();
			if(!visited[mp.second]) break;
		}
		c -= mp.first; 
		visited[mp.second] = true;
		for(int j = 0; j < v[mp.second].size(); j++) {
			pq.push(v[mp.second][j]);
		}
	}
	return c;
}
int main() {
	int n, c;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			scanf("%d", &c);
			v[i].push_back(mp(-c, j));
		}
	}
	printf("%d", prim(n));
}
