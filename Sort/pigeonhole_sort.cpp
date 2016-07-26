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
void pigeonhole(int*, int, bool);
int main(){
	int data[ARRSIZE] = {1,2,3,4,5,6,7,8,9,10};
	pigeonhole(data, ARRSIZE, true);

	print_arr(data, ARRSIZE);
}
void pigeonhole(int* data, int size, bool asc){
	int max_val = -1, min_val = 1<<30;
	for(int i = 0; i < size; i++) {
		max_val = MAX(max_val, data[i]);
		min_val = MIN(min_val, data[i]);
	}
	int* cnt = (int*)calloc(size, sizeof(int));
	memset(cnt, 0, sizeof(cnt));
	for(int i = 0; i < size; i++) {
		cnt[data[i] - min_val]++;
	}
	int offset = max_val - min_val;
	int point = 0;
	if(asc) {
		for(int i = 0; i <= offset; i++){
			while(cnt[i]--) {
				data[point++] = min_val + i;
			}
		}
	} else {
		for(int i = offset; i >= 0; i--){
			while(cnt[i]--) {
				data[point++] = min_val + i;
			}
		}
	}
	free(cnt);
}
void print_arr(int* data, int size){
	for(int i = 0; i < size; i++) printf("%d ", data[i]);
	printf("\n");
}
