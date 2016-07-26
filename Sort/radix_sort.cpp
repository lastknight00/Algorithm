#include<cstdio>
#include<stdlib.h>
#include<string.h>
#include<queue>
#define ARRSIZE 10
#define MAX_VAL 100
#define MIN(x,y) ((x) > (y)) ? (y) : (x)
#define MAX(x,y) ((x) > (y)) ? (x) : (y)
using namespace std;
void print_arr(int*, int);
void radix(int*, int, bool);
int main(){
	int data[ARRSIZE] = {119,236,54,445,21,56,77,97,75,51};
	radix(data, ARRSIZE, true);
	
	print_arr(data, ARRSIZE);
}
void radix(int* data, int size, bool asc) {
	int m = 0;
	int max_val = 0;
	queue<int> q[10];
	for(int i = 0; i < size; i++) max_val = MAX(max_val, data[i]);
	while(max_val) {
		m++;
		max_val /= 10;
	}
	int div = 1;
	if(asc) {
		for(int i = 0; i < m; i++) {
			for(int j = 0 ; j < size; j++) {
				q[(data[j] / div) % 10].push(data[j]);
			}
			int point = 0;
			for(int j = 0; j < 10; j++) {
				while(!q[j].empty()) {
					data[point++] = q[j].front();
					q[j].pop();
				}
			}
			div *= 10;
		}
	} else {
		for(int i = 0; i < m; i++) {
			for(int j = 0 ; j < size; j++) {
				q[(data[j] / div) % 10].push(data[j]);
			}
			int point = 0;
			for(int j = 9; j >= 0; j--) {
				while(!q[j].empty()) {
					data[point++] = q[j].front();
					q[j].pop();
				}
			}
			div *= 10;
		}
	}
}
void print_arr(int* data, int size){
	for(int i = 0; i < size; i++) printf("%d ", data[i]);
	printf("\n");
}
