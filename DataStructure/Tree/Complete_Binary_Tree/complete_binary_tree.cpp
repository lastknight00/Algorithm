#include<cstdio>
#include<vector>
using namespace std;
typedef vector<int> Nodes;
typedef struct Tree {
	Nodes ns;
	Tree() {
		ns.push_back(-1);
	}
	void add(int n) {
		ns.push_back(n);
	}
	void pre_order(Nodes* v,int cur) {
		if(cur >= ns.size()) return;
		v->push_back(ns[cur]);
		pre_order(v, cur * 2);
		pre_order(v, cur *2 + 1);
	}
	void in_order(Nodes* v,int cur) {
		if(cur >= ns.size()) return;
		in_order(v, cur * 2);
		v->push_back(ns[cur]);
		in_order(v, cur *2 + 1);
	}
	void post_order(Nodes* v,int cur) {
		if(cur >= ns.size()) return;
		post_order(v, cur * 2);
		post_order(v, cur *2 + 1);
		v->push_back(ns[cur]);
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
	t.add(2);
	t.add(3);
	t.add(4);
	t.add(5);
	t.add(6);
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
