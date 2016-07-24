#include<cstdio>
#include<cstdlib>
#include<vector>
#include<string.h>
using namespace std;
typedef vector<int> Nodes;
typedef struct Tree {
	int size = 10000;
	int* nodes;
	Tree() {
		nodes = new int[size + 1];
		memset(nodes, -1, sizeof(int) * (size + 1));
	}
	void add(int n) {
		int index = 1;
		while(nodes[index] > -1) {
			/*if(index > size) {
				size *= 2;
				int* temp = new int[size + 1];
				memset(temp, -1, sizeof(int) * (size + 1));
				memcpy(temp, nodes, sizeof(int) * size + 1);
				printf("aa");
				for(int i=0;i<=size;i++) printf("%d ",nodes[i]);
				printf("\n");
				nodes = temp;
			}*/
			if(nodes[index] <= n) index = index * 2 + 1;
			else index *= 2;
		}
		nodes[index] = n;
	}
	void pre_order(Nodes* v,int cur) {
		if(nodes[cur] == -1) return;
		v->push_back(nodes[cur]);
		pre_order(v, cur * 2);
		pre_order(v, cur *2 + 1);
	}
	void in_order(Nodes* v,int cur) {
		if(nodes[cur] == -1) return;
		in_order(v, cur * 2);
		v->push_back(nodes[cur]);
		in_order(v, cur *2 + 1);
	}
	void post_order(Nodes* v,int cur) {
		if(nodes[cur] == -1) return;
		post_order(v, cur * 2);
		post_order(v, cur *2 + 1);
		v->push_back(nodes[cur]);
	}
};
void showV(Nodes v) {
	for(int i = 0; i<v.size();i++){
		printf("%d ",v[i]);
	}
	printf("\n");
}
int main() {
	Tree t;
	t.add(1);
	t.add(6);
	t.add(3);
	t.add(5);
	t.add(2);
	t.add(4);
	vector<int> v;
	t.pre_order(&v,1);
	showV(v);
	v.clear();
	t.in_order(&v,1);
	showV(v);
	v.clear();
	t.post_order(&v,1);
	showV(v);
}
