#include <cstdio>
#include<string.h>
int left[2000], right[2000], cache[2000][2000];
int N, Answer = 0;;
 
int rec(int, int);
 
int main() {
    scanf("%d", &N);
    for (int index = 0; index < N; index++) {
        scanf("%d", &left[index]);
    }
    for (int index = 0; index < N; index++) {
        scanf("%d", &right[index]);
    }
    memset(cache,-1,sizeof(cache));
    Answer = rec(N - 1, N - 1);
    printf("%d", Answer);
}
 
int rec(int lpoint, int rpoint) {
    int retval = 0;
    if (lpoint < 0 || rpoint < 0) {
        return 0;
    }
    else if (cache[lpoint][rpoint] >= 0) {
        return cache[lpoint][rpoint];
    }
    else
    {
        if (left[lpoint] > right[rpoint]) {
            retval += right[rpoint];
            retval += rec(lpoint, rpoint - 1);
        }
        else {
            int temp = rec(lpoint - 1, rpoint);
            int temp1 = rec(lpoint - 1, rpoint - 1);
 
            if (temp >= temp1) {
                retval += temp;
            }
            else {
                retval += temp1;
            }
        }
    }
     
    cache[lpoint][rpoint] = retval;
 
    return retval;
}
