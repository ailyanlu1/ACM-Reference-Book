// ~ O(n)
#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1e6;
bool v[N] = {0}; // visited
int p[N] = {0}; // all primes

void sieve() {
    int pos = 0;
    for (int i = 2; i < N; i++) {
        if (!v[i]) p[pos++] = i;
        for (int j = 0; j < pos && i*p[j] < N; j++) {
            v[i*p[j]] = 1;
            if (i % p[j] == 0) break;
        }
    }
}

