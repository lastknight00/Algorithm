#include<cstdio>
#include<vector>
#define node_type int
using namespace std;
typedef vector<int> Nodes;
typedef struct Heap {
	Nodes nodeList;
	bool (*comp)(node_type, node_type);
	Heap(bool (*_comp) (node_type, node_type)) {
		nodeList.push_back(-1);
		comp = _comp;
	}
	void add(node_type v) {
		nodeList.push_back(v);
		int pointer = nodeList.size() - 1;
		while(pointer > 1 && comp(nodeList[pointer], nodeList[pointer/2])) {
			swap(nodeList[pointer], nodeList[pointer/2]);
			pointer /= 2;
		}
	}
	node_type top() {
		if(nodeList.size() == 1) return -1;
		node_type retval = nodeList[1];
		nodeList[1] = nodeList.back();
		nodeList.pop_back();
		int pointer = 1;
		while(pointer * 2 < nodeList.size()) {
			int swap_pointer;
			if(pointer * 2 + 1 > nodeList.size()) {
				swap_pointer = pointer * 2;
			} else {
				if(comp(nodeList[pointer * 2], nodeList[pointer * 2 + 1])) {
					swap_pointer = pointer * 2;
				} else {
					swap_pointer = pointer * 2 + 1;
				}
			}
			if(comp(nodeList[swap_pointer], nodeList[pointer])) {
				swap(nodeList[swap_pointer], nodeList[pointer]);
				pointer = swap_pointer;
			} else {
				break;
			}
		}
		return retval;
	}
	void pre_order(Nodes* v,int cur) {
		if(cur >= nodeList.size()) return;
		v->push_back(nodeList[cur]);
		pre_order(v, cur * 2);
		pre_order(v, cur *2 + 1);
	}
	void in_order(Nodes* v,int cur) {
		if(cur >= nodeList.size()) return;
		in_order(v, cur * 2);
		v->push_back(nodeList[cur]);
		in_order(v, cur *2 + 1);
	}
	void post_order(Nodes* v,int cur) {
		if(cur >= nodeList.size()) return;
		post_order(v, cur * 2);
		post_order(v, cur *2 + 1);
		v->push_back(nodeList[cur]);
	}
};
bool comp(node_type a, node_type b) {
	return a > b;
}
void showV(Nodes v) {
	for(int i = 0; i<v.size();i++){
		printf("%d ",v[i]);
	}
	printf("\n");
}
int main() {
	Heap h = Heap(*comp);
	h.add(1);
	h.add(3);
	h.add(5);
	h.add(4);
	h.add(2);
	h.add(0);
	vector<node_type> v;
	h.pre_order(&v, 1);
	showV(v);
	
	printf("%d\n",h.top());
	printf("%d\n",h.top());
	printf("%d\n",h.top());
	printf("%d\n",h.top());
	printf("%d\n",h.top());
	printf("%d\n",h.top());
	printf("%d\n",h.top());
}
