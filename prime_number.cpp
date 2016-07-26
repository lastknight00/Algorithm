#include<cstdio>
bool prime(int n) {
	if(n < 2) return false;
	for(int i = 2; i * i <= n; i++) {
		if(n % i == 0) return false;
	}
	return true;
}
int main() {
	for(int i = 1; i < 1000000;i++) {
		printf("is %d prime number?? %s\n", i, prime(i) ? "true" : "false");
	}
}
