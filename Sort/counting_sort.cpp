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
void counting(int*, int, bool);
int main(){
	int data[ARRSIZE] = {9, 1, 5, 9, 2, 4, 5, 2, 1, 3};
	counting(data, ARRSIZE, true);
	
	print_arr(data, ARRSIZE);
}

void counting(int* data, int size, bool asc) {
	int cnt[MAX_VAL];
	int* retval = (int*)calloc(sizeof(int), size);
	memset(cnt, 0, sizeof(cnt));
	for(int i = 0; i < size; i++) cnt[data[i]]++;
	for(int i = 1; i < MAX_VAL; i++) cnt[i] += cnt[i - 1];
	if(asc){
		for(int i = 0; i < size; i++) {
			retval[cnt[data[i]] - 1] = data[i];
			cnt[data[i]]--;
		}
	} else {
		for(int i = size - 1; i >=0; i--) {
			retval[size - (cnt[data[i]])] = data[i];
			cnt[data[i]]--;
		}	
	}
	memcpy(data, retval, sizeof(int) * size);
}
void print_arr(int* data, int size){
	for(int i = 0; i < size; i++) printf("%d ", data[i]);
	printf("\n");
}
