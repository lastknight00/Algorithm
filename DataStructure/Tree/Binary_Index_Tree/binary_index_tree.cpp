#include<cstdio>
long long a[1000001],t[1000001],d;
int N, M, K,b,c;
long long sum(int p) {
    long long retval = 0;
    while (p) {
        retval += t[p];
        p -= (p&-p);
    }
    return retval;
}
void update(int p, long long v) {
    while (p<=N) {
        t[p] += v;
        p += (p&-p);
    }
}
int main() {
    scanf("%d %d %d", &N, &M, &K);
    M += K;
    for (int i = 1; i <= N; i++) {
        scanf("%lld", &a[i]);
        update(i, a[i]);
    }
    while (M--) {
        scanf("%d %d %lld", &b, &c, &d);
        if (b == 1) {
            update(c, d-a[c]);
            a[c] = d;
        }
        else {
            printf("%lld\n", sum(d)-sum(c-1));
        }
    }
}
